# `ft_popen` — A Complete Explanation

This document explains **what `ft_popen` is**, **how it works internally**, a
**line-by-line walkthrough of `ft_popen.c`**, the **actual runtime behavior** of
this exact implementation, the **bugs it contains**, and a **corrected
reference version** you can compare against.

---

## Table of Contents

1. [What is `popen`?](#1-what-is-popen)
2. [The four system calls involved](#2-the-four-system-calls-involved)
3. [The signature and semantics](#3-the-signature-and-semantics)
4. [Line-by-line walkthrough](#4-line-by-line-walkthrough)
5. [Data flow diagrams](#5-data-flow-diagrams)
6. [What this exact code actually does at runtime](#6-what-this-exact-code-actually-does-at-runtime)
7. [Bugs in this implementation](#7-bugs-in-this-implementation)
8. [The test `main` explained](#8-the-test-main-explained)
9. [Corrected reference implementation](#9-corrected-reference-implementation)
10. [Usage examples](#10-usage-examples)
11. [Pitfalls and things to remember](#11-pitfalls-and-things-to-remember)

---

## 1. What is `popen`?

`popen(3)` is a libc function that runs an external command and gives you a
**file descriptor (via a `FILE*` stream) connected to that command**:

- `popen(cmd, "r")` → you **read** the command's standard output.
- `popen(cmd, "w")` → you **write** into the command's standard input.

Under the hood it is just three ideas glued together:

> **pipe → fork → dup2 + exec**

`ft_popen` is the classic 42-school exam exercise that asks you to rebuild
that glue, returning a raw `int` file descriptor instead of a `FILE*`.

---

## 2. The four system calls involved

### `pipe(int fd[2])`

Creates a **one-way communication channel** inside the kernel and hands back
two file descriptors:

| descriptor | name       | direction                        |
|------------|------------|----------------------------------|
| `fd[0]`    | read end   | data comes **out** of the pipe   |
| `fd[1]`    | write end  | data goes **into** the pipe      |

```
 write(fd[1], "hi")  ──►  [ kernel buffer, 64 KB typically ]  ──►  read(fd[0])
```

Key properties:

- **One-way.** You cannot read from `fd[1]` or write to `fd[0]` (you get
  `EBADF`).
- **Bytes, not messages.** The pipe is a byte stream; `read()` may return
  fewer bytes than you asked for.
- **EOF rule:** a reader sees `read() == 0` (EOF) only when **every** write
  end — in every process — is closed. This is why closing unused ends matters.
- Returns `-1` on failure.

### `fork()`

Duplicates the calling process. After `fork()` there are **two** nearly
identical processes, and the same call returns twice:

| return value | which process |
|--------------|---------------|
| `> 0`        | the **parent** — the value is the child's PID |
| `== 0`       | the **child** — a fresh copy of the parent |
| `-1`         | failure — no child was created |

Both processes inherit *copies* of the pipe's two descriptors, so after
`fork()` there are 4 open pipe descriptors in the system (2 per process).

### `dup2(int oldfd, int newfd)`

Atomically closes `newfd` (if open) and makes it point at the same open file
description as `oldfd`. This is how you **redirect** standard streams:

- `dup2(fd[1], 1)` → the child's **stdout** now writes into the pipe.
- `dup2(fd[0], 0)` → the child's **stdin** now reads from the pipe.

### `execvp(const char *file, char *const argv[])`

Replaces the **current process image** with a new program. Everything after
`execvp` in your code disappears if it succeeds — `execvp` returns **only on
failure** (e.g., command not found). It searches `PATH` for `file`, and
`argv` must be a `NULL`-terminated array: `{"ls", NULL}`.

That's why the standard pattern after a failed exec is:

```c
execvp(file, argv);
exit(1);   // only reached if execvp failed
```

---

## 3. The signature and semantics

```c
int ft_popen(const char *file, char *const argv[], char type);
```

| parameter | meaning |
|-----------|---------|
| `file`    | program to execute, e.g. `"ls"` (resolved via `PATH`) |
| `argv`    | argument vector for the program, `NULL`-terminated: `{"ls", NULL}` |
| `type`    | `'r'` = caller will **read** the command's output, `'w'` = caller will **write** to the command's input |

**Return value:**

| outcome | return |
|---------|--------|
| success, `type == 'r'` | read end of the pipe → `read()` the command's stdout |
| success, `type == 'w'` | write end of the pipe → `write()` into the command's stdin |
| invalid args, `pipe` or `fork` failure | `-1` |

The caller owns the returned descriptor and must `close()` it when done.

---

## 4. Line-by-line walkthrough

```c
int ft_popen(const char *file, char *const argv[], char type)
{
	int pid = -1;
	int fd[2];
```
Local state: `pid` will hold the `fork()` result, `fd[2]` will hold the two
pipe ends (`fd[0]` read, `fd[1]` write).

```c
	if (!file || !file[0])
		return -1;
```
Guard against a `NULL` or empty program name. Note: `argv` is **not** checked
(see [bugs](#7-bugs-in-this-implementation)), and neither is `type`.

```c
	int pipecheck = pipe(fd);
	if (pipecheck < 0)
		return -1;
```
Create the pipe. If that fails there is nothing to clean up, so returning
`-1` immediately is correct.

```c
	pid = fork();
	if (pid < 0)
		return close(pid), -1;
```
Fork. If `fork()` fails, the two pipe descriptors created above are **leaked**
— and this line is itself a bug: `close(pid)` closes the *PID number* as if it
were a file descriptor (it isn't), so it does nothing except set `errno` to
`EBADF`. It should be `close(fd[0]); close(fd[1]);`.

This line also uses the **comma operator**: in `return close(pid), -1;`, the
left expression (`close(pid)`) is evaluated for its side effect, then the
whole expression yields `-1`. Legal C, but easy to misread.

```c
	if (pid > 0)
	{
		if (type == 'r')
			dup2(fd[1], 1);
		else if (type == 'w')
			dup2(fd[0], 0);
		close(fd[0]), close(fd[1]);
		execvp(file, argv);
		exit(-1);
	}
```
⚠️ **This is the inverted part.** `pid > 0` is the **parent**, yet the parent
performs the redirection and the `execvp`. In a correct `ft_popen` this block
belongs to the **child** (`pid == 0`). Section 6 traces the consequences.

```c
	if (type == 'r')
		return (close(fd[1]), fd[0]);
	else if (type == 'w')
		return (close(fd[0]), fd[1]);
	return -1;
}
```
Again using the comma operator: close the unused end, then return the useful
end — `fd[0]` (read end) for `'r'`, `fd[1]` (write end) for `'w'`. These two
lines are correct **in spirit**, but because of the inverted branch above they
now execute in the **child** (the parent never reaches them if `execvp`
succeeds). An invalid `type` falls through to `return -1` — but only after a
pipe and a fork have already been created.

---

## 5. Data flow diagrams

### `type == 'r'` — *intended* behavior ("caller reads the command")

```
 ┌────────────────┐  fd[0] (read end)        fd[1] (write end)  ┌─────────────────┐
 │    CALLER      │ ◄═══════════════ kernel pipe ══════════════ │ CHILD execs ls  │
 │  read(fd) ...  │                                            │ dup2(fd[1], 1)  │
 └────────────────┘                                            └─────────────────┘
        ▲ gets "file1\nfile2\n..." on stdout of the child ──────┘
```

The child's stdout is *rewired* into the pipe, so anything `ls` prints lands
in the caller's `read()`.

### `type == 'w'` — *intended* behavior ("caller feeds the command")

```
 ┌────────────────┐  fd[1] (write end)       fd[0] (read end)   ┌─────────────────┐
 │    CALLER      │ ═════════════════ kernel pipe ════════════► │ CHILD execs wc  │
 │  write(fd,...) │                                             │ dup2(fd[0], 0)  │
 └────────────────┘                                             └─────────────────┘
                                             the command reads it on stdin ──┘
```

The child's stdin is *rewired* out of the pipe, so the command reads whatever
the caller writes.

---

## 6. What this exact code actually does at runtime

Because the `dup2`/`exec` block runs in the **parent** (`pid > 0`) instead of
the child, the roles come out backwards:

1. `pipe()` creates the pipe.
2. `fork()` splits the process.
3. **The parent** dups a pipe end onto stdin/stdout, closes both pipe fds, and
   `execvp`s the command → **the process that called `ft_popen` is replaced by
   the command.** The original program's PID now belongs to `ls` (or whatever
   you ran).
4. **The child** skips the block, closes the unused end, and *returns from
   `ft_popen` with the pipe fd* → the rest of the caller's code (e.g. `main`)
   continues running **in the forked child**.

So data still flows through the pipe — the exec'd process (former parent)
writes to it and the forked copy (former child) reads from it — which is why
this code can *look* like it works. But the semantics are wrong:

- The **caller becomes the command**; the "continuation" of your program is a
  forked double, not the original process.
- A program calling this cannot do anything after `ft_popen` in its own
  original process — its identity was handed to the command.

A correct implementation must have the **child** (`pid == 0`) do the
`dup2` + `execvp`, and the **parent** return the pipe fd.

---

## 7. Bugs in this implementation

| # | Bug | Effect | Fix |
|---|-----|--------|-----|
| 1 | `dup2` + `execvp` in the `pid > 0` (**parent**) branch | Parent is replaced by the command; the caller's continuation runs in a forked child. Roles inverted (see §6) | Move the block into `pid == 0` |
| 2 | `return close(pid), -1;` on `fork()` failure | Closes a PID value, not a descriptor → pipe fds **leaked** every failed fork | `close(fd[0]); close(fd[1]);` |
| 3 | `type` is never validated before `pipe`/`fork` | An invalid type (e.g. `'x'`) still creates a pipe, forks, and the parent **execs the command with untouched stdio**; the child returns `-1` and keeps running | Validate `type` up front: `if (type != 'r' && type != 'w') return -1;` |
| 4 | `argv` is not checked for `NULL` | `execvp(file, NULL)` is undefined behavior | `if (!file || !argv || !file[0]) return -1;` |
| 5 | Child never closes its unused pipe end after `dup2` (once moved to the child) | For `'r'`: the child keeps `fd[0]` open; harmless here, but leaving the *wrong* end open breaks **EOF** — the reader never sees `read() == 0` while the child lives | In the child: `dup2(...)`, then `close(fd[0]); close(fd[1]);` |
| 6 | `exit(-1)` after failed exec | Exit status is truncated to a byte → `255`; conventional failure code is `1` | `exit(1);` |
| 7 | No `waitpid` / `pclose` equivalent | The command becomes a **zombie** when it exits until the caller exits (same contract as raw `popen`, but worth knowing) | Out of scope for the exercise; real `pclose` calls `waitpid` |

Also stylistic: `pid_t pid` is the idiomatic type, and `return close(x), y;`
(comma operator) hurts readability — two statements are clearer.

---

## 8. The test `main` explained

```c
int main()
{
    int  fd;
	char buffer[1024];
    fd = ft_popen("ls", (char *const []){"ls", NULL}, 'w');
    while (read(fd, buffer, sizeof(buffer)) > 0)
        write(fd, buffer, sizeof(buffer));
    return (0);
}
```

Problems, one by one:

1. **Mode/fd mismatch.** With `'w'`, the returned fd is the pipe's **write**
   end. `read()`ing from it fails immediately with `EBADF`, so the loop body
   never executes. The intent was clearly `'r'`.
2. **Echo loop to nowhere.** Even with `'r'`, `write(fd, ...)` writes the data
   *back into the same pipe* it just came from — the program should print to
   stdout (`write(1, ...)`), not recycle the buffer into the pipe.
3. **`write(..., sizeof(buffer))`** always writes 1024 bytes regardless of how
   many bytes `read` actually returned. Use the `read` return value.
4. **`fd` is never closed.**

A correct driver would be:

```c
fd = ft_popen("ls", (char *const[]){"ls", NULL}, 'r');
while ((n = read(fd, buffer, sizeof(buffer))) > 0)
    write(STDOUT_FILENO, buffer, n);
close(fd);
```

---

## 9. Corrected reference implementation

```c
#include <unistd.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	int		fd[2];
	pid_t	pid;

	if (!file || !file[0] || !argv || (type != 'r' && type != 'w'))
		return -1;
	if (pipe(fd) < 0)
		return -1;
	pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return -1;
	}
	if (pid == 0)                       /* ---- child ---- */
	{
		if (type == 'r')
			dup2(fd[1], STDOUT_FILENO); /* stdout -> pipe write end */
		else
			dup2(fd[0], STDIN_FILENO);  /* stdin  <- pipe read end  */
		close(fd[0]);
		close(fd[1]);
		execvp(file, argv);             /* returns only on failure */
		exit(1);
	}
	/* ---- parent ---- */
	if (type == 'r')
	{
		close(fd[1]);                   /* parent never writes */
		return fd[0];
	}
	close(fd[0]);                       /* parent never reads  */
	return fd[1];
}
```

Checklist of what changed versus the original:

- ✅ `type` and `argv` validated **before** creating anything.
- ✅ `fork` failure closes **both** pipe ends.
- ✅ `dup2` + `execvp` happen in the **child** (`pid == 0`).
- ✅ Child closes **both** pipe ends after `dup2` (the dup'd copy stays live
  through fd 0/1; the originals must go).
- ✅ Parent closes the unused end and returns the useful one.
- ✅ `exit(1)` after a failed exec.

---

## 10. Usage examples

**Read a command's output (like `popen(cmd, "r")`):**

```c
int fd = ft_popen("ls", (char *const[]){"ls", NULL}, 'r');
char buf[256];
ssize_t n;

while ((n = read(fd, buf, sizeof(buf))) > 0)
	write(STDOUT_FILENO, buf, n);
close(fd);   /* after this, the child sees EOF on stdin if it reads */
```

**Feed a command's input (like `popen(cmd, "w")`):**

```c
int fd = ft_popen("wc", (char *const[]){"wc", "-l", NULL}, 'w');

write(fd, "a\nb\nc\n", 6);
close(fd);   /* closing the write end sends EOF -> wc prints "3" */
```

**Building pipelines:** chain calls by dup'ing one call's output onto another
call's child stdin — the same primitive `sh` uses for `a | b`.

---

## 11. Pitfalls and things to remember

- **Close unused ends.** EOF is only delivered when *all* write ends are
  closed. If the parent forgets `close(fd[1])` in mode `'r'`, the caller's
  `read` loop never terminates.
- **`execvp` doesn't come back.** Anything after it runs only if the exec
  failed — that's the exit point, not an error path to "recover" from.
- **Pipes are byte streams.** One `read` ≠ one `write` from the other side;
  loop until you have what you need or until EOF.
- **The returned fd belongs to you.** `close()` it; there is no `pclose` here,
  so don't forget the child may linger as a zombie until your process exits.
- **Order matters:** validate → `pipe` → `fork` → (child: dup2, close both,
  exec) / (parent: close unused, return).
- **`'r'` vs `'w'` is from the caller's point of view**, not the command's:
  `'r'` = *I* read the command's output, `'w'` = *I* write the command's input.
