# picoshell — A Complete Walkthrough

```c
int    picoshell(char **cmds[]);
```

`picoshell` is a 42 exam exercise ("exam04") that asks you to reimplement the
core mechanism of a **shell pipeline** — the plumbing behind commands like:

```bash
ls | grep picoshell
echo 'squalala' | cat | sed 's/a/b/g'
```

Given a list of commands, the function must execute all of them **in
parallel**, wire the standard output of each command to the standard input of
the next one, wait for every child to finish, and return `0` on success or
`1` if anything went wrong (closing every file descriptor first).

This document explains the reference solution in `picoshell.c` line by line,
the UNIX concepts it relies on, the descriptor lifecycle, the error paths,
and the traps that make this exercise harder than it first looks.

---

## Table of Contents

1. [The input data structure](#1-the-input-data-structure)
2. [The system calls involved](#2-the-system-calls-involved)
3. [The full source, annotated](#3-the-full-source-annotated)
4. [Step-by-step execution trace](#4-step-by-step-execution-trace)
5. [File descriptor lifecycle](#5-file-descriptor-lifecycle)
6. [Error handling paths](#6-error-handling-paths)
7. [Why every single `close` matters](#7-why-every-single-close-matters)
8. [A worked example: `echo | cat | sed`](#8-a-worked-example-echo--cat--sed)
9. [Common mistakes and traps](#9-common-mistakes-and-traps)
10. [Recap of invariants](#10-recap-of-invariants)

---

## 1. The input data structure

```c
int    picoshell(char **cmds[]);
```

The parameter type `char **cmds[]` is really `char ***cmds` — an array of
`argv`-style arrays:

```text
cmds
 ├── cmds[0] ──► ["ls", "-la", NULL]        ← argv for the 1st command
 ├── cmds[1] ──► ["grep", "picoshell", NULL] ← argv for the 2nd command
 └── NULL                                    ← end of the pipeline
```

* `cmds` itself is **NULL-terminated**: you stop when `cmds[i] == NULL`.
* Each `cmds[i]` is a classic `argv` array: a NULL-terminated list of
  `char *`, where `cmds[i][0]` is the program name/path.
* A pipeline with **N commands** therefore has **N − 1 pipes**.
  Crucially, the *last* command has no successor: its output goes to the
  shell's stdout, and it must **not** get a pipe.

The provided `main.c` builds this structure from the command line, splitting
the arguments on `"|"` tokens, so `./picoshell ls "|" grep foo` produces:

```c
cmds[0] = ["ls", NULL]
cmds[1] = ["grep", "foo", NULL]
cmds[2] = NULL
```

---

## 2. The system calls involved

The allowed functions are exactly: `close, fork, wait, exit, execvp, dup2,
pipe`. Each plays one role:

| Call              | Role in the pipeline                                              |
| ----------------- | ----------------------------------------------------------------- |
| `pipe(fd)`        | Creates a one-way channel: `fd[0]` = read end, `fd[1]` = write end. |
| `fork()`          | Duplicates the current process. Returns `0` in the child, the child's PID in the parent, `-1` on failure. |
| `dup2(old, new)`  | Atomically makes `new` a copy of `old` (closing the previous `new` if it was open). Used to redirect fd 0/1. |
| `close(fd)`       | Releases a descriptor. Essential so EOF can propagate.            |
| `execvp(file, argv)` | Replaces the child process image with the named program, searching `$PATH`. Returns only on failure. |
| `wait(...)`       | Collects a terminated child, returning its PID; returns `-1` when there are no children left. Used here to reap them all. |
| `exit(1)`         | Kills the child if `execvp` failed, so it never runs as a clone of the parent. |

**The mental model of a pipeline:**

```text
        stdin ──► [ cmd 1 ] ──pipe──► [ cmd 2 ] ──pipe──► [ cmd 3 ] ──► stdout
```

Each pipe is created *once*, in the parent. The child for command `i`
duplicates the pipe's write end onto its stdout; the child for command `i+1`
duplicates the same pipe's read end onto its stdin.

---

## 3. The full source, annotated

```c
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int    picoshell(char **cmds[])
{
    int    fd_in = 0;        // read end of the PREVIOUS pipe (0 = "none yet", i.e. real stdin)
    int    pipefd[2];        // read/write ends of the pipe being created this iteration
    int    i = 0;            // index of the command being launched
    int    ret = 0;          // function result: 0 = OK, 1 = error
    pid_t  pid;              // fork() result

    while (cmds[i])
    {
        /* ---- 1. Create a pipe only if there IS a next command ---- */
        if (cmds[i + 1])
        {
            if (pipe(pipefd) == -1)
            {
                ret = 1;
                break;                 // nothing to clean: pipe failed atomically
            }
        }

        /* ---- 2. Fork the child that will run cmds[i] ---- */
        pid = fork();
        if (pid == -1)
        {
            ret = 1;
            if (cmds[i + 1])           // we did open a pipe this round —
            {                          // fork failing does NOT close it for us
                close(pipefd[0]);
                close(pipefd[1]);
            }
            break;                     // fd_in (previous pipe) is closed below
        }

        if (pid == 0)                  /* ==================== CHILD ==================== */
        {
            /* Redirect stdin from the previous pipe, if any */
            if (fd_in != 0)
            {
                dup2(fd_in, 0);        // fd 0 now points at the pipe's read end
                close(fd_in);          // the original fd is redundant after dup2
            }
            /* Redirect stdout into the next pipe, if there is a next command */
            if (cmds[i + 1])
            {
                close(pipefd[0]);      // child WRITES only: drop the read end
                dup2(pipefd[1], 1);    // fd 1 now points at the pipe's write end
                close(pipefd[1]);      // the original fd is redundant after dup2
            }
            execvp(cmds[i][0], cmds[i]);  // replace image; returns only on failure
            exit(1);                   // exec failed → the child must not continue
        }

        /* ==================== PARENT ==================== */
        /* ---- 3. Parent has no use for the read end of the previous pipe ---- */
        if (fd_in != 0)
            close(fd_in);              // child holds it now; parent must let go

        /* ---- 4. This pipe becomes the NEXT command's stdin ---- */
        if (cmds[i + 1])
        {
            close(pipefd[1]);          // parent never writes into the pipe
            fd_in = pipefd[0];         // remember the read end for iteration i+1
        }
        i++;
    }

    /* ---- 5. Loop exited: either all commands launched, or an error ---- */
    if (fd_in != 0)                    // the last pipe's read end is still
        close(fd_in);                  // open in the parent in BOTH cases

    /* ---- 6. Reap every child (also covers the failure case: the children
            already launched still exist and must not be left as zombies) ---- */
    while (wait(NULL) != -1)
        ;

    return ret;
}
```

---

## 4. Step-by-step execution trace

Suppose `cmds = [A, B, C, NULL]` (three commands, two pipes).

**Parent state:** `fd_in = 0`, `ret = 0`.

### Iteration `i = 0` (command A)

1. `cmds[1]` exists → `pipe(p1)` is created. Parent holds both `p1[0]`, `p1[1]`.
2. `fork()` → child 1.
   * Child: `fd_in == 0`, so no stdin redirect (A reads real stdin).
     There is a next command → close `p1[0]`, `dup2(p1[1], 1)`, close `p1[1]`.
     A's stdout is now the pipe. `execvp(A)`.
   * Parent: `fd_in == 0`, nothing to close. Close `p1[1]` (parent never
     writes). `fd_in = p1[0]` — "the next command will read from here".

### Iteration `i = 1` (command B)

3. `cmds[2]` exists → `pipe(p2)` created.
4. `fork()` → child 2 (which inherits `p1[0]` as `fd_in`, `p2[0]`, `p2[1]`).
   * Child: `fd_in != 0` → `dup2(p1[0], 0)`, close `p1[0]`. B's stdin = pipe 1.
     Next command exists → close `p2[0]`, `dup2(p2[1], 1)`, close `p2[1]`.
     B's stdout = pipe 2. `execvp(B)`.
   * Parent: close `p1[0]` (its copy of the old read end — the child has it).
     Close `p2[1]`. `fd_in = p2[0]`.

### Iteration `i = 2` (command C, the last one)

5. `cmds[3] == NULL` → **no pipe is created**. `pipefd` still holds stale
   values from `p2`, but they are never touched because every use is guarded
   by `if (cmds[i + 1])`.
6. `fork()` → child 3.
   * Child: `fd_in != 0` → `dup2(p2[0], 0)`, close `p2[0]`. C's stdin = pipe 2.
     No next command → stdout untouched: C writes to the real stdout.
     `execvp(C)`.
   * Parent: close `p2[0]`. `cmds[3] == NULL` → no new `fd_in` assignment.

### After the loop

7. `fd_in` is still `p2[0]` (the parent closed it in step 6, but note it was
   reassigned... see the [invariants](#10-recap-of-invariants)) — in this
   implementation the final `if (fd_in != 0) close(fd_in);` is what reliably
   closes the leftover read end no matter how the loop ended.
8. `wait(NULL)` loops until it returns `-1` (no children left), reaping
   children 1, 2 and 3.
9. Return `0`.

At runtime the processes and descriptors look like this:

```text
PARENT                        CHILD 1 (A)         CHILD 2 (B)          CHILD 3 (C)
  launches all, closes           fd0: tty            fd0: p1[0]           fd0: p2[0]
  every fd it doesn't            fd1: p1[1]          fd1: p2[1]           fd1: tty
  need, then waits                  │                   ▲                    ▲
       ▲                            └────── p1 ─────────┘                    │
       │                                                └────── p2 ─────────┘
  reaps: wait() × 3
```

---

## 5. File descriptor lifecycle

The key discipline: **every fd must end up either closed or owned by exactly
one process that actually needs it.** Here is the full ledger for a
3-command pipeline.

| fd                          | Created        | Closed by child                       | Closed by parent                     |
| --------------------------- | -------------- | ------------------------------------- | ------------------------------------ |
| `p1[0]` (pipe 1 read end)   | iteration `i=0`| child 1 (before dup2, doesn't read it); child 2 (after `dup2(fd_in,0)`) | iteration `i=1`, via `close(fd_in)` |
| `p1[1]` (pipe 1 write end)  | iteration `i=0`| child 1 (after `dup2(pipefd[1],1)`)   | iteration `i=0`, right after fork    |
| `p2[0]` (pipe 2 read end)   | iteration `i=1`| child 2 (before dup2); child 3 (after dup2) | iteration `i=2` + final cleanup |
| `p2[1]` (pipe 2 write end)  | iteration `i=1`| child 2 (after dup2)                  | iteration `i=1`, right after fork    |

Why this matters mechanically: a read on a pipe returns **EOF only when all
write ends are closed**. If the parent "helpfully" keeps `p1[1]` open, `B`
will hang forever waiting for input that will never come, because A already
exited. Symmetrically, if write ends linger, `grep`-style programs that read
to EOF never terminate. The dance of closes *is* the exercise.

A subtle inherited-fd point: every child forked *after* a pipe exists
inherits that pipe's descriptors. E.g. child 3 inherits nothing extra here
because the parent already closed `p1[0]`/`p1[1]` before forking it — that's
why the parent closes its copies **before the next `fork`**, not after the
whole loop.

---

## 6. Error handling paths

There are exactly two failure points inside the function, and both must
leave no dangling descriptors:

### `pipe()` fails

```c
if (pipe(pipefd) == -1)
{
    ret = 1;
    break;
}
```

When `pipe` fails it does **not** create any descriptor (the call is atomic),
so there is nothing to clean up here. The only fd possibly still open is the
previous pipe's read end, and the unconditional cleanup after the loop
handles it.

### `fork()` fails

```c
pid = fork();
if (pid == -1)
{
    ret = 1;
    if (cmds[i + 1])
    {
        close(pipefd[0]);
        close(pipefd[1]);
    }
    break;
}
```

When `fork` fails, the pipe created moments ago **does exist** and both ends
must be closed manually — a failed fork leaves the parent untouched, so
nothing else will ever close them. The guard `if (cmds[i + 1])` matters: on
the last command no pipe was created this round, and closing stale values in
`pipefd` could theoretically close an unrelated (reused) fd.

Note what the two paths have in common: **children already launched keep
running.** The function does not attempt to kill them; it simply closes all
fds in the *parent* and proceeds to `wait()` for everyone. That satisfies
the subject ("close all the open fds before returning 1") while reaping the
survivors.

### `execvp()` fails

Not an error of *picoshell* itself, but the child must handle it: `execvp`
returns only when it fails, and falling through would make the child run a
second copy of the parent's loop (forking more children!). Hence the
mandatory:

```c
execvp(cmds[i][0], cmds[i]);
exit(1);
```

`exit` is in the allowed list precisely for this. (Using `_exit` or `exit`
here is equivalent in practice since nothing is buffered by this program.)

---

## 7. Why every single `close` matters

It's easy to dismiss some closes as "optional cleanups". They are not — each
one prevents a concrete bug:

| Omitted close                          | Symptom |
| -------------------------------------- | ------- |
| Parent keeps `pipefd[1]` after fork    | Next command **hangs**: a pipe reader gets EOF only when *all* write ends are closed. |
| Parent keeps previous `fd_in`          | Descriptor leak; worse, later children inherit a read end they never read, and — if a later round reused the fd number — confusing redirections. |
| Child keeps `pipefd[0]` before dup2    | Leak in the child; a program like `yes` that closes its inherited fds could behave unexpectedly. Mostly hygiene, always required for the exam. |
| Child keeps `pipefd[1]` after dup2     | **Deadlock**: the child holds a write end of its own stdout pipe; even after it exits... actually the fatal case is the *next* child inheriting it — everyone keeps the pipe alive, readers never see EOF. |
| Child skips `exit(1)` after execvp     | Two processes continue the loop → commands execute **twice**, extra forks, corrupted pipeline. |
| Final `close(fd_in)` after the loop    | Leak of the last pipe's read end; also, on the error paths it's the *only* thing closing it. |

Rule of thumb used by the solution:

* **In the child:** duplicate onto 0/1, then close the *original* pipe fds —
  the child needs only the redirected 0/1.
* **In the parent:** close both ends of any pipe it won't personally use —
  it only *holds* a read end temporarily, to hand it to the next child.

---

## 8. A worked example: `echo | cat | sed`

```
./picoshell echo 'squalala' "|" cat "|" sed 's/a/b/g'
squblblb
```

`cmds`:

```c
cmds[0] = ["echo", "squalala", NULL]
cmds[1] = ["cat", NULL]
cmds[2] = ["sed", "s/a/b/g", NULL]
cmds[3] = NULL
```

Data flow:

1. `echo` writes `squalala\n` into **pipe 1** and exits.
2. `cat` reads pipe 1 until EOF (which requires `echo`'s exit *and* all write
   ends closed — hence the close discipline), writes it to **pipe 2**.
3. `sed` reads pipe 2, substitutes each `a` with `b`, writes `squblblb\n` to
   the real stdout.
4. Parent reaps all three and returns `0`.

If instead the parent forgot to close its copy of pipe 1's write end, `cat`
would block forever on `read` — no EOF — and the whole pipeline would hang.

---

## 9. Common mistakes and traps

* **Piping the last command.** Creating a pipe unconditionally at the top of
  the loop leaves the last command writing to a pipe nobody reads (output
  lost) and an orphan fd in the parent. Always test `cmds[i + 1]`.
* **Cleaning `pipefd` unconditionally after a failed `fork`.** On the last
  command, `pipefd` holds a *previous* (already closed) fd number. If that
  number was reused by another open file, you'd close the wrong thing. Guard
  with `if (cmds[i + 1])`.
* **Closing the previous pipe's read end too late.** The parent must close
  `fd_in` before the next `fork`, otherwise every subsequent child inherits
  an fd it will never close, keeping pipe 1 alive and possibly preventing
  EOF for command 2 if it's still open in a long-running child 3.
* **`exit` after `execvp`.** Forgetting it is the classic "commands run
  twice" bug — the failed-exec child falls back into the loop.
* **Using `wait()` once instead of a loop.** `wait(NULL)` reaps *one* child;
  you need the `while (wait(NULL) != -1);` pattern to reap them all. It also
  conveniently handles the error paths, where some children still run.
* **Returning before waiting.** The subject requires waiting for all
  children *before* returning 0.
* **Assuming `fd_in` is a valid fd when it's 0.** The code uses `0` as a
  sentinel for "no redirection yet". That works because fd 0 is the real
  stdin — dup2'ing 0 onto 0 would be a no-op anyway, but the sentinel keeps
  the logic explicit.

---

## 10. Recap of invariants

At every point where `fork()` is called, the state satisfies:

1. **Parent holds:**
   * `fd_in` — the read end of the pipe feeding command `i` (`0` if none).
   * Both ends of the pipe feeding command `i+1`, freshly created, *if*
     command `i+1` exists.
2. **Child `i` ends up with:**
   * stdin = previous pipe (or real stdin for the first command),
   * stdout = next pipe (or real stdout for the last command),
   * no other leftover pipe fds.
3. **Parent keeps nothing it doesn't need** — it closes `fd_in` and the
   write end immediately after forking, *before* the next iteration's fork.
4. **On any error:** every fd opened by the parent is closed before
   returning; children already spawned are still waited for.
5. **On success:** all children are reaped with the `wait` loop, and the
   function returns `0`.

The whole function is a compact demonstration of the three idioms every
mini-shell is built from: **pipe → fork → dup2 → execvp → wait**, with
relentless fd hygiene in the parent.
