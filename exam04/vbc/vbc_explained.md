# vbc — explained thoroughly

`vbc` ("very basic calculator") is a classic 42 exam exercise. The program takes a math
expression as a **single argument** and prints its value. It must support:

- single-digit numbers `0`–`9`
- the operators `+` and `*`
- parentheses `( )`
- **operator precedence**: `*` binds tighter than `+`, so `3+4*5` is `23`, not `35`
- parentheses overriding precedence: `(3+4)*5` is `35`

Anything else (a bad symbol, a misplaced parenthesis, input ending too early) must print:

- `Unexpected token 'X'` (with the offending character) → exit code `1`
- `Unexpected end of input` (input ended where more was required) → exit code `1`
- on a syscall failure → just exit `1`

The easiest reliable way to do this in exam conditions is a **recursive descent parser that
computes the result directly** — no AST/`calloc` trees needed, ~70 lines.

---

## The core idea in one picture

Every grammar rule becomes **one function**. Each function only consumes the tokens it
recognizes, then returns. The `input` pointer is a global cursor that always sits on the
next unread character.

```
expr    := product ( '+' product )*      -> parse_expr
product := atom    ( '*' atom )*         -> parse_product
atom    := DIGIT | '(' expr ')'          -> parse_atom
```

Reading the grammar top-down:

- An **expression** is products separated by `+` → lowest precedence lives here.
- A **product** is atoms separated by `*` → higher precedence, because products are
  glued together *inside* the expression before the `+` loop ever runs.
- An **atom** is where recursion closes the loop: a digit, or `( expr )` — the
  parenthesized expression recursively calls the *top* rule, which is exactly why
  `(3+4)*5` works.

Because `parse_expr` calls `parse_product`, which calls `parse_atom`, which can call
`parse_expr` again, precedence falls out of the call structure automatically. **You never
write any precedence logic yourself** — that's why this approach is the safest for the exam.

---

## The code, piece by piece

### Globals and error helper

```c
char	*input;	/* global cursor into argv[1] */

void	unexpected(char c)
{
	if (c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of input\n");
	exit(1);
}
```

- A single global `char *` cursor keeps every function's signature tiny — one less thing
  to get wrong under time pressure.
- `unexpected` exploits a C trick: `'\0'` is the character `0`, which is *false* in C.
  The end of the string is `'\0'`, so `if (c)` distinguishes **"there is a real character
  to blame"** from **"the string ended"** — the two error messages from the subject — in
  one tiny function. It prints and `exit(1)` immediately.

### The three grammar functions

```c
int	parse_atom(void)
{
	int	value;

	if (*input == '(')
	{
		input++;                 /* consume '(' */
		value = parse_expr();    /* the inside is a full expression */
		if (*input != ')')
			unexpected(*input);  /* missing ')' or junk inside */
		input++;                 /* consume ')' */
	}
	else if (isdigit(*input))
	{
		value = *input - '0';    /* ASCII digit -> numeric value */
		input++;                 /* consume the digit */
	}
	else
		unexpected(*input);      /* nothing we recognize: blame *input */
	return (value);
}
```

`parse_atom` is the only place that actually *produces* numbers.

- The digit case is `*input - '0'`: digits are contiguous in ASCII (`'0'`=48 … `'9'`=57),
  so subtracting 48 gives the value 0–9. The subject says all values are 0–9, so there is
  deliberately **no multi-digit parsing** — `12` must fail with `Unexpected token '2'`
  because after reading `1`, the cursor sees `2`, which is neither `+`, `*`, `)` nor end.
- The parenthesis case consumes `(`, recursively evaluates the whole inside with
  `parse_expr()`, then **demands** `)`. If the next char isn't `)`, `unexpected(*input)`
  reports the first wrong thing. Note `((1+3)*12+(3*(2+6))` correctly reports the `2`:
  after the inner `(2+6)` is consumed and `)` seen, the outer `)` is fine too — the parser
  is then still in `parse_product`'s `*`-loop position looking at `2`, a token that can't
  follow, so the error is honest.
- The final `else` covers every wrong start of an atom: `*3`, `+1`, `a`, or end of input
  (`*input` is `'\0'` → "Unexpected end of input").

```c
int	parse_product(void)
{
	int	value;

	value = parse_atom();
	while (*input == '*')
	{
		input++;                    /* consume '*' */
		value = value * parse_atom();
	}
	return (value);
}
```

```c
int	parse_expr(void)
{
	int	value;

	value = parse_product();
	while (*input == '+')
	{
		input++;                    /* consume '+' */
		value = value + parse_product();
	}
	return (value);
}
```

These two are the **same shape**: parse one item, then *while* the next token is my
operator, consume it and combine with the next item. The `while` (not `if`) is what makes
long chains like `1+2+3+4+5` work, and left-to-right accumulation is the natural reading
order.

`isdigit` is allowed by the subject (it's in the explicitly permitted list: `malloc,
calloc, realloc, free, printf, isdigit, write`). It comes from `<ctype.h>`.

### `main`

```c
int	main(int argc, char **argv)
{
	int	result;

	if (argc != 2)
		return (1);
	input = argv[1];
	result = parse_expr();
	if (*input != '\0')
		unexpected(*input);
	if (printf("%d\n", result) < 0)
		return (1);
	return (0);
}
```

Step by step:

1. `argc != 2` — the subject wants exactly one argument; any other count silently exits 1.
2. Point the global cursor at the argument.
3. `parse_expr()` evaluates the whole expression and returns the number.
4. **The trailing-garbage check.** This is the easiest thing to forget. After
   `parse_expr` returns, valid input *must* be fully consumed. `1+2)` parses `1+2`, then
   stops on `)` — without this check you'd print `3` and ignore the junk. `*input != '\0'`
   means "there are unread characters left" → error. (This is why `12` fails: `parse_expr`
   happily returns `1`, and the check catches the leftover `2`.)
5. `printf(...) < 0` covers the "syscall failure → exit 1" clause (`printf` returns a
   negative value on failure). `exit(1)` inside `unexpected` covers failures there too,
   since `exit` is a syscall wrapper — this is exam-level paranoia, not something the
   graders usually trigger.

---

## Why the precedence works (worked example: `3+4*5`)

```
parse_expr
├─ parse_product
│  └─ parse_atom → 3          (value=3; next char '+', loop not entered)
├─ see '+', consume it
├─ parse_product              ← crucial: the right side of '+' is a WHOLE product
│  ├─ parse_atom → 4          (value=4)
│  ├─ see '*', consume it
│  └─ parse_atom → 5          (value=4*5=20)
└─ value = 3 + 20 = 23        ✓
```

The `+` loop calls `parse_product` for its operands — so all `*`s around a number are
absorbed **before** the `+` ever combines it. That single fact is the whole precedence
mechanism. And `(3+4)*5`? `parse_atom` hits `(`, calls `parse_expr` for the inside
(`3+4=7`), returns `7` as one atom, then `parse_product` multiplies by `5` → `35`.

Also note the `*`-loop inside `parse_product` evaluates **left to right**, e.g.
`(((((2+2)*2+2)*2+2)*2+2)*2+2)*2` builds up correctly step by step → `188`.

---

## Error paths at a glance

| Input      | What happens                                            | Output                     |
|------------|---------------------------------------------------------|----------------------------|
| `1+`       | after `+`, `parse_product → parse_atom` sees `'\0'`      | `Unexpected end of input`  |
| `1+2)`     | top-level parse ends, leftover `)` caught in `main`      | `Unexpected token ')'`     |
| `(3+4`     | `parse_expr` inside parens returns, `*input` is `'\0'`   | `Unexpected end of input`  |
| `*3`       | atom can't start with `*`                                | `Unexpected token '*'`     |
| `3-4`      | `-` can't start an atom after `3` is read                | `Unexpected token '-'`     |
| `12`       | `1` parsed, leftover `2` caught in `main`                | `Unexpected token '2'`     |
| `a`        | unknown symbol at atom position                          | `Unexpected token 'a'`     |
| (no args)  | `argc != 2`                                             | (nothing) exit `1`         |

`unexpected` is only ever called in token-expectation positions, and it reads `*input`
directly — so it automatically reports either the offending character or, when `*input`
is `'\0'`, the end-of-input message. One function, both messages.

---

## Exam tips

- **The grammar is given to you by the exercise itself**: allowed operators + precedence
  = the three rules above. Write the grammar as comments first, then translate each line
  to a function. The functions are almost mechanical.
- **Two easy points people lose:**
  1. forgetting the *trailing garbage check* in `main` (`1+2)` would print `3`);
  2. writing `if` instead of `while` in the operator loops (long chains would break).
- The subject mentions `malloc/calloc/realloc/free` because the *original* exam template
  builds an AST; the direct-evaluation version needs **none** of them, which is exactly
  why it's the easiest correct approach.
- Depth: recursive descent uses the call stack, one level per parenthesis. The exam's
  tests don't go anywhere near stack limits.
- Compile with `cc -Wall -Wextra -Werror vbc.c -o vbc` — the exam compiles like that, so
  make sure it's warning-free (don't forget `#include <ctype.h>` for `isdigit`).

## Test results (all from subject.txt)

```
pass=15 fail=0
```

Extra manual checks: empty string, unclosed parens, leading `*`, `-`, letters,
multi-digit numbers and wrong `argc` all produce the expected error + exit code 1.
