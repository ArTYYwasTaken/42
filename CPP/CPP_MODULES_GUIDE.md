# C++ Modules 00–04 — The Complete Beginner's Guide

This guide teaches you **everything you need to know** to do the 5 C++ modules, in order, assuming you know **zero C++**. Read it top to bottom: each chapter builds on the previous one. Every code example works under **C++98** (the standard your modules require).

**The modules at a glance:**

| Module | Title | What it really teaches |
|---|---|---|
| 00 | Megaphone, PhoneBook, Account | First contact: classes, I/O, `static`, `const` |
| 01 | Zombies, Harl | Memory: stack vs heap, references, pointers to members |
| 02 | Fixed-point numbers | Operator overloading, the Orthodox Canonical Form |
| 03 | ClapTrap family | Inheritance and polymorphism via inheritance |
| 04 | Animals, Materias | Virtual functions, abstract classes, interfaces, deep copies |

---

## Table of contents

- [Part 0 — Setup & ground rules](#part-0--setup--ground-rules)
- [Part 1 — Absolute basics (Module 00)](#part-1--absolute-basics-module-00)
- [Part 2 — Classes: the heart of everything](#part-2--classes-the-heart-of-everything)
- [Part 3 — static and const (Module 00 deep dive)](#part-3--static-and-const-module-00-deep-dive)
- [Part 4 — Streams, strings, iomanip (Module 00 exercises)](#part-4--streams-strings-iomanip-module-00-exercises)
- [Part 5 — Memory: stack, heap, new/delete (Module 01)](#part-5--memory-stack-heap-newdelete-module-01)
- [Part 6 — References vs pointers (Module 01)](#part-6--references-vs-pointers-module-01)
- [Part 7 — File streams & string surgery (Module 01 ex04)](#part-7--file-streams--string-surgery-module-01-ex04)
- [Part 8 — Pointers to member functions & switch (Module 01 Harl)](#part-8--pointers-to-member-functions--switch-module-01-harl)
- [Part 9 — Orthodox Canonical Form & operator overloading (Module 02)](#part-9--orthodox-canonical-form--operator-overloading-module-02)
- [Part 10 — Fixed-point numbers (Module 02)](#part-10--fixed-point-numbers-module-02)
- [Part 11 — Inheritance (Module 03)](#part-11--inheritance-module-03)
- [Part 12 — The diamond problem & virtual inheritance (Module 03 ex03)](#part-12--the-diamond-problem--virtual-inheritance-module-03-ex03)
- [Part 13 — Subtype polymorphism & virtual functions (Module 04)](#part-13--subtype-polymorphism--virtual-functions-module-04)
- [Part 14 — Abstract classes & interfaces (Module 04)](#part-14--abstract-classes--interfaces-module-04)
- [Part 15 — Deep copies, the Rule of Three, memory leaks](#part-15--deep-copies-the-rule-of-three-memory-leaks)
- [Part 16 — Makefiles for C++](#part-16--makefiles-for-c)
- [Part 17 — Evaluation cheat-sheet & checklist](#part-17--evaluation-cheat-sheet--checklist)

---

# Part 0 — Setup & ground rules

## What C++ is

C++ = C + classes ("C with Classes", created by Bjarne Stroustrup). Almost all valid C code compiles as C++, but the modules want you to write **C++-style**, not "C with a C++ compiler".

You will target **C++98** — an old standard on purpose: it forces you to build concepts by hand that modern C++ does for you.

## Compiling

```bash
c++ -Wall -Wextra -Werror -std=c++98 main.cpp -o my_program
```

- `-Wall -Wextra` → enable almost all warnings; `-Werror` → warnings become errors. Fix every warning.
- `-std=c++98` → compile as C++98. Your code must survive this flag.

## Hard rules from the subjects (breaking these = 0 or -42)

1. **Forbidden functions:** `*printf()`, `*alloc()`, `free()` — grade 0. Use `std::cout`, `std::string`, `new`/`delete`.
2. **No C++11 or later, no Boost, no external libraries.**
3. **No STL until Module 08:** no `std::vector`, `std::list`, `std::map`, no `<algorithm>`. `std::string`, `std::cout`, `std::cin`, `<iomanip>` ARE part of the standard library and are allowed (and expected).
4. **No `using namespace <ns>;`** and **no `friend`** keyword (unless a subject explicitly allows it) — grade -42.
5. **No function implementation in header files** (except templates) — grade 0. Headers declare; `.cpp` files implement.
6. **Include guards in every header** — grade 0 otherwise (see Part 2).
7. **From Module 02 on: every class in Orthodox Canonical Form** (Part 9).
8. **No memory leaks** — every `new` needs a matching `delete`.
9. Every output message ends with `\n` and goes to **standard output**.
10. Class names in `UpperCamelCase`; files named after the class: `ClapTrap.hpp`, `ClapTrap.cpp`.
11. No Norminette! Write whatever clean style you like, but be readable.
12. No dynamic allocation in Module 00 ex01 (PhoneBook): fixed-size arrays only.

> **42 AI note:** the subjects ask you to reason first, discuss with peers, and not just copy AI answers. Use this guide as a map of the concepts — then write the code yourself and make sure you can explain every line during the defense.

## Your very first program

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
```

- `#include <iostream>` — pull in the input/output library.
- `std::cout` — the standard output stream. `<<` pushes data into it ("insertion operator").
- `std::` — the namespace of the standard library. Everything standard lives inside `std`.
- `std::endl` — newline **and** flush the stream. `"\n"` also works when flushing isn't needed.

---

# Part 1 — Absolute basics (Module 00)

## Variables and types

```cpp
int     i = 42;        // integer
float   f = 42.42f;    // floating point ('f' suffix = float, not double)
double  d = 42.42;     // bigger floating point
char    c = 'A';       // single character, single quotes
bool    ok = true;     // true / false
```

All of these exist in C. C++ adds a big one:

```cpp
std::string s = "hello";   // a real string class, no char*, no strlen
```

## Input/output

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string name;
    std::cout << "What is your name? ";   // prompt
    std::getline(std::cin, name);          // read a WHOLE line, even with spaces
    std::cout << "Hello, " << name << "!" << std::endl;
    return 0;
}
```

- `std::cin >> name;` reads **one word** (stops at whitespace).
- `std::getline(std::cin, name);` reads the **whole line** — you need this for PhoneBook fields ("first name" contains a space!).
- Mixing the two is tricky: after `std::cin >> x;` the newline stays in the buffer and the next `getline` reads an empty line. Stick to `getline` for user input in these exercises.

## Command-line arguments (Megaphone)

```cpp
#include <iostream>

int main(int argc, char **argv)
{
    // argc = number of arguments (program name counts, so argc >= 1)
    // argv[0] = "./megaphone", argv[1] = first real argument, etc.
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++)
        std::cout << argv[i];   // strings can be concatenated with <<
    std::cout << std::endl;
    return 0;
}
```

## Functions

```cpp
int add(int a, int b)          // definition: return type, name, parameters
{
    return a + b;
}
```

- **Declaration vs definition:** a *declaration* (`int add(int, int);`) tells the compiler a function exists — usually lives in a `.hpp`. The *definition* (the body) lives in a `.cpp`.
- **Default parameters:** `void greet(std::string name = "stranger");` — callers may omit the argument.

## Control flow (quick reference — you know this from C)

```cpp
if (x > 0) { ... } else if (x < 0) { ... } else { ... }

for (int i = 0; i < n; i++) { ... }

while (condition) { ... }

switch (level)              // see Part 8 — Module 01 ex06 wants this
{
    case "A" ...            // switch works on INTEGRAL types, not std::string!
}
```

Note: C++98 `switch` only works on integer-like values (`int`, `char`, `enum`), **not** `std::string`. Harl filter has a trick for this (Part 8).

## Member functions of std::string you will actually use

```cpp
std::string s = "Hello, world!";
s.size();            // or s.length() — number of characters
s.substr(7, 5);      // "world" — from index 7, 5 characters
s[i];                // character at index i
s.find("world");     // index of first occurrence, or std::string::npos
s.empty();           // true if ""
s + "!"              // concatenation -> "Hello, world!!"
s += "!";            // append in place
std::toupper(c)      // from <cctype>: uppercase one char
```

Megaphone: loop over each character and `std::toupper` it. PhoneBook: build display columns with `size()`, `substr`, and `<iomanip>`.

---

# Part 2 — Classes: the heart of everything

A **class** bundles *data* (attributes) with the *functions* that operate on it (member functions, aka methods). This is Object-Oriented Programming (OOP).

## The anatomy of a class

**`Contact.hpp`** (declaration — the "what"):

```cpp
#ifndef CONTACT_HPP          // include guard, part 1
# define CONTACT_HPP        // part 2

#include <string>

class Contact
{
public:
    void setFirstName(const std::string &name);
    std::string getFirstName(void) const;

private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
};

#endif                        // include guard, part 3
```

**`Contact.cpp`** (implementation — the "how"):

```cpp
#include "Contact.hpp"

void Contact::setFirstName(const std::string &name)
{
    _firstName = name;
}

std::string Contact::getFirstName(void) const
{
    return _firstName;
}
```

Key ideas:

- `class Contact { ... };` — **the semicolon after the closing brace is mandatory** and forgetting it is the #1 beginner compile error.
- `public:` members = usable from outside ("the interface"). `private:` = only the class itself may touch them. This is **encapsulation**: the outside world asks, the class decides.
- Rule of thumb from the subject: *"anything that will always be used inside a class is private, and anything that can be used outside is public."*
- `Contact::getFirstName` — the `::` "scope resolution operator" says "this function belongs to class Contact".
- Leading underscores (`_firstName`) are a common convention to mark attributes. Pick one convention and keep it.
- **Include guards** (`#ifndef/#define/#endif`) prevent a header from being pasted twice into the same file (double-inclusion → compile error). Alternative: `#pragma once` — but guards are the classic, portable way.

## Objects and using them

```cpp
#include <iostream>
#include "Contact.hpp"

int main()
{
    Contact c;                       // c is an object (instance) of Contact
    c.setFirstName("Ada");           // call a member function with '.'
    std::cout << c.getFirstName() << std::endl;
    return 0;
}
```

A class is the **blueprint**; an object is a real thing built from it. `PhoneBook` contains an array of `Contact` *objects* — not structs, not C arrays of strings.

## Constructors and destructors

Special member functions called automatically:

- **Constructor:** runs when the object is created. Same name as the class, no return type. Use it to initialize every attribute.
- **Destructor:** `~Contact()` runs when the object dies (end of scope, or `delete`). Clean up what the object owns.

```cpp
class Zombie
{
public:
    Zombie(std::string name);   // parameterized constructor
    ~Zombie();                  // destructor
    void announce(void);
private:
    std::string _name;
};
```

```cpp
Zombie::Zombie(std::string name) : _name(name)   // initializer list (below!)
{
    std::cout << "Zombie " << _name << " created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << _name << " destroyed" << std::endl;
}
```

You can have **several constructors** with different parameters — the compiler picks by the arguments (this is *overloading*, same idea as for functions).

## The initializer list (Module 00 headline topic!)

The `: _name(name)` syntax above is an **initialization list**: attributes are initialized directly with the given values, instead of first default-constructed and then assigned.

```cpp
// GOOD — initialization
Zombie::Zombie(std::string name) : _name(name)
{
}

// WORKS but worse — assignment after default construction
Zombie::Zombie(std::string name)
{
    _name = name;
}
```

Why prefer the list:

1. Attributes are *initialized* (built with the value in one step), not *assigned* (built, then overwritten).
2. **Mandatory** for `const` attributes and references — they can never be assigned, only initialized (Module 02's `Point` with `Fixed const x` needs this!).
3. Mandatory to call a **parent constructor** in Module 03: `ScavTrap::ScavTrap(std::string name) : ClapTrap(name) { ... }`.

Order warning: attributes are initialized **in the order they are declared in the class**, not the order of the list. Keep the list in declaration order.

## Getters and setters

Since attributes are private, the outside world uses accessors:

```cpp
std::string Contact::getFirstName(void) const { return _firstName; }  // getter
void Contact::setFirstName(const std::string &n) { _firstName = n; }  // setter
```

The trailing `const` on the getter is explained in Part 3.

---

# Part 3 — static and const (Module 00 deep dive)

These two keywords are everywhere in the modules. Master them now.

## `const` — "I promise not to modify"

```cpp
const int answer = 42;
answer = 43;              // COMPILE ERROR
```

Applied to parameters — pass big things by reference but forbid modification (Part 6 explains `&`):

```cpp
void print(const std::string &s);   // cheap AND read-only
```

Applied to member functions — a getter that doesn't touch the object's state:

```cpp
class Fixed
{
public:
    int getRawBits(void) const;    // const member function
private:
    int _rawBits;
};

int Fixed::getRawBits(void) const  // the const belongs HERE too
{
    return _rawBits;    // ok: reading
    // _rawBits = 0;    // COMPILE ERROR: can't modify in a const function
}
```

A `const` member function is the **only** kind you can call on a `const` object:

```cpp
const Fixed b(10);
b.getRawBits();     // OK — function is const
// b.setRawBits(5); // ERROR — non-const function on a const object
```

You will need this constantly in Module 02 (`Fixed const b(10)` in the subject's main) — so write `const` getters from the start.

## `static` — "belongs to the class, not to an object"

Two very different uses:

**1. Static attribute: one shared copy for ALL objects.**

```cpp
class Account
{
public:
    static int getNbAccounts(void);        // static member FUNCTION
private:
    static int _nbAccounts;                // static member ATTRIBUTE
    static int _totalAmount;
};

int Account::_nbAccounts = 0;   // MUST be defined once in a .cpp file
```

```cpp
Account a;               // _nbAccounts becomes 1
Account b;               // 2 — same variable, shared by every Account
Account::getNbAccounts() // called on the CLASS, no object needed
```

This is exactly Module 00 ex02 (`Account`): the number of accounts, total amount, total deposits/withdrawals are shared class-wide data. A static attribute is *declared* in the header but must be *defined/initialized* in the `.cpp`.

**2. Static member function: callable without an object.**

```cpp
int Account::getNbAccounts(void) { return _nbAccounts; }  // no const, no object
```

- Called as `Account::getNbAccounts()`.
- A static member function **cannot** touch non-static attributes (there is no `this` object — see below), and cannot be `const`.

**3. `static` inside a function (C-style):** a local variable that persists between calls — useful for "number of times called" counters.

## `this` pointer

Inside every non-static member function, `this` is a pointer to the current object:

```cpp
void Contact::print(void)
{
    std::cout << this->_firstName;   // equivalent to _firstName
}
```

You rarely need to write it — except to return the current object from operator overloads (`return *this;`, Module 02) and to disambiguate.

## Namespaces

A **namespace** groups names to avoid collisions. That's what `std` is.

```cpp
namespace Audio
{
    int volume = 5;
    void play(void) { /* ... */ }
}

Audio::play();      // qualified access
```

For the modules you mostly *use* namespaces (`std::`) — and defining `using namespace std;` is forbidden. Write `std::` explicitly: it also makes your code clearer about what comes from the standard library.

---

# Part 4 — Streams, strings, iomanip (Module 00 exercises)

## How Megaphone fits together

- `main(int argc, char **argv)`, loop from `argv[1]`.
- For each argument string, uppercase every character: `std::toupper(argv[i][j])`.
- Print with no separator, then one newline.
- No arguments → print the feedback-noise line.

## PhoneBook: what you need beyond the basics

**The loop that accepts only ADD / SEARCH / EXIT:**

```cpp
while (1)
{
    std::cout << "Enter command (ADD, SEARCH, EXIT): ";
    if (!std::getline(std::cin, command))
        break;                    // EOF (Ctrl+D) — exit cleanly
    if (command == "ADD") { /* ... */ }
    else if (command == "SEARCH") { /* ... */ }
    else if (command == "EXIT")
        return 0;
    // anything else: ignore, loop again
}
```

**Design:** `PhoneBook` has `Contact contacts[8];` — a fixed array, no `new` (dynamic allocation is forbidden in this exercise). Adding a 9th contact overwrites the **oldest**: use an index that wraps around (`index = (index + 1) % 8`) plus a counter of how many are stored.

**Empty fields:** prompt field by field with `getline`; re-prompt until the string is not empty.

**The 4-column display (the `<iomanip>` part):**

```cpp
#include <iomanip>
#include <iostream>
#include <string>

std::string truncate(std::string s)
{
    if (s.size() > 10)
        return s.substr(0, 9) + ".";   // 9 chars + a dot
    return s;
}

// in the display loop:
std::cout << std::setw(10) << truncate(contact.getFirstName()) << "|";
```

- `std::setw(10)` — set the **w**idth of the *next* output to 10 characters (applies to one item only, then resets — re-issue it every time).
- Default alignment is **right**-aligned, which the subject wants.
- Format: `index | first | last | nickname` then a newline; each column 10 wide, separated by `'|'`.
- Then read an index with `getline`, convert it (`std::atoi` from `<cstdlib>` works in C++98, or check `s == "0"`, `s == "1"`... — your choice), and print that contact one field per line. Handle out-of-range / garbage input gracefully.

## Account (ex02): reconstructing from a log

You get `Account.hpp` and a log file; you must write `Account.cpp` so the output matches. Everything you need is in Part 2/3:

- 8 attributes, 5 of them `static` (`_nbAccounts`, `_totalAmount`, `_nbDeposits`, `_nbWithdrawals`, plus the display index `_accountIndex` is per-object).
- Static getters: `getNbAccounts`, `getTotalAmount`, `getNbDeposits`, `getNbWithdrawals`.
- `_displayTimestamp()` — a private static helper printing `[19920104_091532]` style timestamps. The log shows the exact format; reproduce it with `<iostream>` fill/width or `<iomanip>` (`std::setw`, `std::setfill('0')`).
- Read the log line by line and mirror it: constructor prints `[timestamp] index:x;amount:y;created`, `makeDeposit` prints `index:x;p_amount:y;deposit:z;amount:w;deposits:d`, etc.
- The exact strings are all in the provided log — this exercise is reading-comprehension, not design. (It's optional for the module validation, but great static/const practice.)

---

# Part 5 — Memory: stack, heap, new/delete (Module 01)

## The two kinds of memory

**Stack** — automatic, fast, managed for you:

```cpp
int main()
{
    Zombie z("Bob");     // lives on the stack
    z.announce();
    return 0;
}                        // <- z is destroyed HERE, automatically, destructor runs
```

Objects on the stack die when their scope (`{ ... }`) ends. You never free them yourself.

**Heap** — manual, big, yours to manage:

```cpp
int main()
{
    Zombie *z = new Zombie("Bob");   // allocated on the heap
    z->announce();                   // NOTE: '->' not '.' for pointers!
    delete z;                        // <- YOU must free it, destructor runs here
    return 0;
}
```

Forget `delete` → **memory leak** (the memory is never returned). Delete twice or use after delete → undefined behavior/crash.

## When to use which? (The actual point of Module 01 ex00)

- **Stack** (`Zombie z("Bob")`): object only needed inside the current function, size known, lifetime = scope. `randomChump()` creates a zombie, makes it announce, and the zombie dies at the end of the function — stack is perfect.
- **Heap** (`new Zombie(...)`): object must **outlive the function** (be returned to the caller), or be big, or have a runtime-decided lifetime. `newZombie()` returns the zombie, so it must survive the function's end → heap + `return` the pointer.

> Rule of thumb: stack by default; heap only when the object must escape the scope or live longer. Every heap allocation needs a documented `delete` somewhere.

## `new` / `delete` vs C's `malloc` / `free`

| C | C++ |
|---|---|
| `malloc(n)` allocates raw bytes | `new T(...)` allocates **and calls the constructor** |
| `free(p)` releases | `delete p` calls the **destructor** then frees |
| `p->member` | same, `p` is a pointer |

Never mix: `free` something from `new`, or `delete` something from `malloc`.

## Arrays with new[]

Module 01 ex01 (zombieHorde): allocate N objects in **one** allocation:

```cpp
Zombie* zombieHorde(int N, std::string name)
{
    Zombie *horde = new Zombie[N];   // one allocation, N default-constructed zombies
    for (int i = 0; i < N; i++)
        horde[i].setName(name);      // then name each one
    return horde;
}

// in main:
Zombie *horde = zombieHorde(5, "Bob");
for (int i = 0; i < 5; i++)
    horde[i].announce();
delete[] horde;                      // NOTE: delete[] for new[]!
```

- `new Zombie[N]` requires a default constructor (one taking no arguments) — have one.
- Free with **`delete[]`**, never plain `delete`.
- `horde[i].announce()` — indexing a pointer to an array of objects gives you an object; use `.` on it.

## Checking for leaks

- The destructor prints the zombie's name (required) — if a zombie never announces its destruction, you leaked it.
- Tools: compile with `-g -fsanitize=address` for a run-time leak report (on macOS use `leaks -atExit -- ./prog`, or valgrind on Linux) — *for testing only, not part of submission flags*.

---

# Part 6 — References vs pointers (Module 01)

Both deal with **addresses**. C++ adds references, and the modules hammer the difference.

## Pointers — recap

```cpp
int x = 42;
int *p = &x;      // p HOLDS the address of x
std::cout << *p;  // dereference: prints 42
*p = 7;           // modifies x through p
```

- `&x` = address of x. `*p` = the thing p points to.
- A pointer can be **NULL** ("points to nothing"), **reassigned** to other addresses, and needs `*` to access the value.
- `->` is shorthand: `p->announce()` ≡ `(*p).announce()`.

## References — an alias, another name for an existing thing

```cpp
int x = 42;
int &ref = x;     // ref IS x — same memory, different name
ref = 7;          // modifies x
std::cout << &ref << " " << &x;   // same address!
```

Rules:

1. A reference **must be initialized** when created.
2. It can **never** be rebound to another object — it refers to `x` forever.
3. It can never be null.
4. Using it needs no special syntax — no `*`, no `->`. It *is* the object.

```cpp
void increment(int &n) { n++; }   // C++ way of "in/out" parameters

int main()
{
    int i = 41;
    increment(i);    // i is now 42 — no &i, no *
}
```

## When pointers, when references? (Module 01 ex03 is exactly this question)

```cpp
class HumanA   // ALWAYS has a weapon
{
private:
    Weapon &_weapon;   // REFERENCE: born with it, can never be "no weapon"
public:
    HumanA(std::string name, Weapon &w);
};
```

```cpp
class HumanB   // MAY not have a weapon... maybe later
{
private:
    Weapon *_weapon;   // POINTER: can start as NULL, set later with setWeapon
public:
    HumanB(std::string name);        // no weapon yet
    void setWeapon(Weapon &w);       // pick one up
};
```

**The answer the evaluators want:** use a **reference** when the object must always exist and never change what it refers to (HumanA is always armed); use a **pointer** when "nothing there yet / later / maybe never" must be representable (HumanB can be unarmed).

⚠️ Trap: a reference member must be initialized in the **initializer list** (Part 2) — it cannot be assigned in the constructor body. And a class with a reference member can't be assigned normally (that's why HumanA doesn't need `operator=` for this exercise).

## Passing by value / pointer / reference

```cpp
void byValue(std::string s);          // COPIES the string — slow, changes invisible outside
void byPointer(std::string *s);       // passes address; can be NULL; call: f(&str)
void byReference(const std::string &s); // no copy, read-only — THE default for objects
```

Default habit for the modules: pass objects as `const std::string &` / `const ClassName &` — no copies, no modification. That's what the `getType()` in Module 01 returns: a `const` reference.

## HI THIS IS BRAIN (ex02) — the full pattern

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;    // pointer
    std::string &stringREF = brain;     // reference

    std::cout << &brain     << std::endl;  // address of the variable
    std::cout << stringPTR  << std::endl;  // address held by the pointer (same)
    std::cout << &stringREF << std::endl;  // address of the referent (same!)

    std::cout << brain      << std::endl;  // the value
    std::cout << *stringPTR << std::endl;  // value through the pointer
    std::cout << stringREF  << std::endl;  // value through the reference
}
```

All three addresses printed are identical — the reference and the pointer both lead to the same single string. The reference just *hides* the address arithmetic.

---

# Part 7 — File streams & string surgery (Module 01 ex04)

## Reading and writing files — the C++ way

```cpp
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream in("input.txt");          // input file stream
    if (!in.is_open())                      // ALWAYS check
    {
        std::cerr << "Error: cannot open input.txt" << std::endl;
        return 1;
    }

    std::ofstream out("input.txt.replace"); // output file stream

    std::string line;
    while (std::getline(in, line))          // line by line, without '\n'
    {
        out << replaceAll(line) << "\n";    // write + newline
    }
    // files close automatically when the stream objects die
}
```

- `std::ifstream` = read, `std::ofstream` = write (created/truncated), `std::fstream` = both.
- `getline(stream, line)` strips the newline; add your own when writing.
- `std::cerr` is the error output stream — fine to use for error messages.

## Replacing all occurrences of s1 with s2 — WITHOUT std::string::replace (it's forbidden)

Manual scan-and-build:

```cpp
std::string replaceAll(const std::string &line,
                       const std::string &s1, const std::string &s2)
{
    std::string result;
    size_t pos = 0;
    if (s1.empty())
        return line;                     // avoid infinite loop on empty s1
    while (true)
    {
        size_t found = line.find(s1, pos);
        if (found == std::string::npos)
            break;                       // no more occurrences
        result += line.substr(pos, found - pos);  // text before the match
        result += s2;                             // the replacement
        pos = found + s1.size();                  // jump past the match
    }
    result += line.substr(pos);                  // the tail after the last match
    return result;
}
```

Concepts used: `size_t` (unsigned index type), `find(from)` searching from a position, `npos` = "not found", `substr(start, length)`, string `+=`.

Edge cases to handle (the subject demands it): wrong argument count, unopenable file, empty `s1`, empty file, `s1` not present. Write your own test files.

---

# Part 8 — Pointers to member functions & switch (Module 01 Harl)

## Pointer to a member function (Harl 2.0, ex05)

Problem: `complain("debug")` must call `debug()`, `complain("info")` must call `info()`... without if/else chains.

A **pointer to a member function** stores "which function of that class to call". It's a type like any other:

```cpp
// type: pointer to a Harl member function taking void and returning void
typedef void (Harl::*HarlFunc)(void);

void Harl::complain(std::string level)
{
    HarlFunc funcs[4] = { &Harl::debug, &Harl::info,
                          &Harl::warning, &Harl::error };
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*funcs[i])();    // call the member function on this object
            return;
        }
    }
}
```

Reading the syntax:

- `void (Harl::*HarlFunc)(void)` — "pointer into class Harl, returns void, takes void". The parentheses around `Harl::*` are mandatory.
- `&Harl::debug` — take the address of a member function (the `&` is required).
- `(this->*funcs[i])()` — call it **on** an object. Both sets of parentheses are mandatory. `this->*f` = "call f on me"; `object.*f` also exists.

That's the whole trick: a table of levels + a table of member-function pointers, one loop, zero if/else forests.

## switch statement (Harl filter, ex06)

```cpp
switch (value)          // works on int, char, enum — NOT std::string
{
    case 1:
        doSomething();
        break;          // break prevents falling into the next case!
    case 2:
    case 3:             // empty case = both go here
        doOther();
        break;
    default:
        doDefault();
}
```

For Harl filter the input is a string, and you must print a level **and all levels above it**. The classic trick: `switch` on a *fall-through chain* ordered so each case falls into the ones below:

```cpp
// levels 0..3: DEBUG=0, INFO=1, WARNING=2, ERROR=3
int index = levelToIndex(argv[1]);   // map string -> 0..3, or -1 if unknown

switch (index)
{
    case 0:
        std::cout << "[ DEBUG ]" << std::endl;
        harl.debug();               // fall through on purpose — no break!
    case 1:
        std::cout << "[ INFO ]" << std::endl;
        harl.info();
    case 2:
        std::cout << "[ WARNING ]" << std::endl;
        harl.warning();
    case 3:
        std::cout << "[ ERROR ]" << std::endl;
        harl.error();
        break;                      // break only at the bottom
    default:
        std::cout << "[ Probably complaining about insignificant problems ]"
                  << std::endl;
}
```

The missing `break`s are **intentional**: entering at `case 0` executes everything down to the `break` — "this level and above". Map the string to an index first (with if/== comparisons or a small lookup).

---

# Part 9 — Orthodox Canonical Form & operator overloading (Module 02)

## The Orthodox Canonical Form (OCF) — required from Module 02 on

Every class must provide these **four** special member functions:

```cpp
class Fixed
{
public:
    Fixed();                            // 1. default constructor
    Fixed(const Fixed &other);          // 2. copy constructor
    Fixed &operator=(const Fixed &other); // 3. copy assignment operator
    ~Fixed();                           // 4. destructor
private:
    int _rawBits;
};
```

Why each exists:

1. **Default constructor** `Fixed()` — builds a "blank" object (`Fixed a;`).
2. **Copy constructor** `Fixed(const Fixed &other)` — builds a NEW object as a copy of an existing one. Called by: `Fixed b(a);`, `Fixed b = a;` (at declaration!), and pass-by-value.
3. **Copy assignment** `Fixed &operator=(const Fixed &other)` — replaces the contents of an EXISTING object with a copy of another. Called by: `c = b;` when `c` already exists.
4. **Destructor** `~Fixed()` — cleanup.

Copy vs assignment — the classic confusion:

```cpp
Fixed a;
Fixed b(a);    // COPY CONSTRUCTOR (b is being born)
Fixed c = a;   // COPY CONSTRUCTOR TOO (declaration with = is initialization!)
Fixed d;
d = a;         // operator= (d already existed)
```

The standard implementation of `operator=`:

```cpp
Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)        // guard against self-assignment (a = a)
        _rawBits = other._rawBits;
    return *this;              // enables chaining: a = b = c
}
```

- Parameter is a **const reference** (no copy of the source).
- Returns `Fixed &` — a reference to `*this` — so assignments chain.
- The subject's expected output tells you exactly which messages each function prints — make them match.

**File layout rule:** class definition in `Fixed.hpp`, implementations in `Fixed.cpp`. Nothing implemented in the header.

## Operator overloading — teach your class real operators

C++ lets most operators be redefined for your types. Two forms exist:

**Member function form** (binary operators like `+`):

```cpp
// in the class:
Fixed operator+(const Fixed &other) const;

// implementation:
Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result._rawBits = _rawBits + other._rawBits;
    return result;
}

// usage — both identical:
Fixed c = a + b;
Fixed c = a.operator+(b);
```

- `a + b` → `a` is `this`, `b` is `other`.
- `const` on the end = `a` isn't modified (needed when operands are const).

**All the operators Module 02 ex02 wants:**

| Group | Operators | Signature pattern |
|---|---|---|
| Comparison | `< > <= >= == !=` | `bool operator<(const Fixed &) const;` |
| Arithmetic | `+ - * /` | `Fixed operator*(const Fixed &) const;` |
| Increment/decrement | `++ --` (pre and post) | see below |

**Pre-increment vs post-increment** — a classic interview question, and the subject's test output checks it:

```cpp
Fixed &Fixed::operator++(void)      // PRE-increment: ++a
{
    _rawBits += 1;                  // modify, then...
    return *this;                   // ...return the NEW value
}

Fixed Fixed::operator++(int)        // POST-increment: a++ — the int is a DUMMY
{
    Fixed old(*this);               // save a copy of the OLD value
    _rawBits += 1;                  // modify
    return old;                     // ...return the OLD value (by value!)
}
```

- The `int` parameter in the post form is a fake argument that only distinguishes the two overloads. Never use it.
- Pre returns `Fixed &` (the updated object); post returns a **copy** of the old state (hence by value).
- In the subject's test: `++a` prints the increased value immediately; `a++` prints the old one, and only the *next* `<< a` shows the increase.

**The stream operator `<<` must be a free (non-member) function** — because the left side is the stream, not your object:

```cpp
// in Fixed.hpp:
std::ostream &operator<<(std::ostream &out, const Fixed &value);

// in Fixed.cpp:
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();     // subject: print the floating-point representation
    return out;                 // returning the stream enables chaining
}
```

You need `std::ostream` from `<iostream>` in the header (a forward declaration `#include <iosfwd>` also works). This single operator is why every later `std::cout << a` prints your class nicely.

**Static min/max** (also ex02) — static member functions (Part 3) taking references, with a **const and a non-const version**:

```cpp
static Fixed &min(Fixed &a, Fixed &b);
static const Fixed &min(const Fixed &a, const Fixed &b);
static Fixed &max(Fixed &a, Fixed &b);
static const Fixed &max(const Fixed &a, const Fixed &b);
// call: Fixed::max(a, b) — compare with the ternary operator: (a < b) ? b : a
```

---

# Part 10 — Fixed-point numbers (Module 02)

## What and why

`int` can't hold fractions; `float`/`double` are imprecise (binary can't represent 0.1 exactly) and slow on some hardware. A **fixed-point number** stores a real number as an integer with a fixed number of "fractional bits". With **8 fractional bits**:

```
value = raw_bits / 256        (256 = 2^8)

  42.0  -> raw = 42 * 256  = 10752
  42.42 -> raw = round(42.42 * 256) = 10860   -> back: 10860/256 = 42.421875
  0.00390625 = 1/256 -> raw = 1  (the smallest representable step, "epsilon")
```

Precision, range and speed are all fixed at compile time — that's why graphics/sound code loves fixed-point. That's your `Fixed` class: one `int` attribute + `static const int _fractionalBits = 8`.

## The conversions (ex01)

```cpp
#include <cmath>

Fixed::Fixed(const int n)  : _rawBits(n << 8) {}              // n * 256 (bit shift = fast multiply)
Fixed::Fixed(const float f): _rawBits(roundf(f * 256.0f)) {}  // round, don't truncate!

float Fixed::toFloat(void) const { return (float)_rawBits / 256.0f; }
int   Fixed::toInt(void)   const { return _rawBits >> 8; }    // integer part
```

- `roundf` (from `<cmath>`) is the **only** C math function allowed in these exercises.
- `<< 8` and `>> 8` are bit shifts: multiply/divide by 2^8. (`x << 8` ≡ `x * 256`.)
- Constructor-taking-one-argument note: `Fixed b(10)` and `Fixed c(42.42f)` pick the int/float constructor automatically. This also means an implicit conversion exists (`int` → `Fixed`) — harmless here, but be aware evaluators may ask about it.

Then add the `<<` operator (Part 9) and `toFloat/toInt` — the subject's expected output is your test.

## Arithmetic operators (ex02) — doing math in raw bits

Given `a._rawBits = A * 256` and `b._rawBits = B * 256`:

```
a + b  ->  (A*256 + B*256)   / 256 = A + B      => rawA + rawB          (already scaled)
a - b  ->  rawA - rawB
a * b  ->  (A*256) * (B*256) = (A*B) * 256*256  => (rawA * rawB) >> 8   (too scaled: shift back)
a / b  ->  (A*256) / (B*256) = A / B (unscaled)  => (rawA << 8) / rawB   (too small: scale up)
```

```cpp
Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result._rawBits = ((long)this->_rawBits * other._rawBits) >> 8;
    // (long) avoids overflowing the int on big multiplications
    return result;
}
```

(Overflow-hardening is optional — but understand the `>> 8` / `<< 8` logic, it *is* the exercise. Division by zero → crash is accepted by the subject.)

Comparisons are trivial: the raw ints preserve order, so `operator<` is `return _rawBits < other._rawBits;`. Increment by the smallest step is `_rawBits += 1` (that's exactly 1/256 = ε).

## BSP (ex03): point in triangle

New class `Point`: two `Fixed const` attributes `x`, `y`. Const members **must** be set in the initializer list — the copy assignment operator then has nothing assignable (write an empty-bodied `operator=` with the usual signature).

`bool bsp(Point const a, Point const b, Point const c, Point const point)` — returns true only if the point is **strictly inside** (vertices and edges → false).

The standard approach: the point is inside if and only if the areas of triangles ABP, BCP, CAP are all positive (or all negative) — equivalently all the same sign:

```cpp
// cross product of 2D vectors (a->b) x (a->p) — its sign tells which side p is on
static float cross(const Point &a, const Point &b, const Point &p)
{
    return (b.getX() - a.getX()).toFloat() * (p.getY() - a.getY()).toFloat()
         - (b.getY() - a.getY()).toFloat() * (p.getX() - a.getX()).toFloat();
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float d1 = cross(a, b, point);
    float d2 = cross(b, c, point);
    float d3 = cross(c, a, point);

    bool hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    return !(hasNeg && hasPos);   // all same sign = inside; any 0 = on edge/vertex = false
}
```

(Optional exercise, but a beautiful synthesis of OCF + const + operator overloading.)

---

# Part 11 — Inheritance (Module 03)

## The idea

**Inheritance** = a class (*derived*) gets the attributes and functions of another (*base*), then adds or overrides behavior. ClapTrap → ScavTrap → FragTrap: all are ClapTraps with more muscle.

```cpp
class ScavTrap : public ClapTrap   // "ScavTrap is a ClapTrap"
{
public:
    ScavTrap(std::string name);
    ~ScavTrap();
    void attack(const std::string &target);
    void guardGate(void);
};
```

- `public ClapTrap` = public inheritance: everything public in ClapTrap stays public in ScavTrap.
- The derived class **inherits all attributes** (`_hitPoints`, `_energyPoints`, ...) — you don't redeclare them.
- "is-a" relationship: a `ScavTrap` *is a* `ClapTrap`, so anywhere a ClapTrap is expected, a ScavTrap works.

## Constructors and destructors chain (ex01/02's core lesson)

Creating a `ScavTrap s("SC4V")` runs, **in order**:

```
1. ClapTrap constructor        (base is built FIRST)
2. ScavTrap constructor        (derived body runs second)
```

Destroying it runs in **reverse**:

```
1. ~ScavTrap()
2. ~ClapTrap()                 (derived is destroyed FIRST)
```

Why: the derived part can only be built on top of a finished base part, and must be taken apart before the base underneath it disappears. Your test main must print this chaining (constructors/destructors print messages).

To pass arguments to the base constructor — initializer list again:

```cpp
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)   // explicit base constructor
{
    _hitPoints = 100;      // re-set the inherited attributes
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap constructor" << std::endl;
}
```

If you don't write `: ClapTrap(name)`, the compiler calls ClapTrap's **default** constructor automatically. If the base has no default constructor, you MUST call one explicitly.

## protected

A third access level between public and private:

```cpp
class ClapTrap
{
protected:
    std::string _name;        // accessible in ClapTrap AND derived classes
private:
    int _secret;              // NOT visible to ScavTrap, even though it inherits it
};
```

- `private` members are *inherited but inaccessible* to the child.
- `protected` = "private to the world, public to my children" — that's why the subject makes `Animal::type` protected in Module 04 (Dog/Cat need to set it).

## Overriding vs overloading

- **Overloading** (Module 00-02): same function name, *same class*, different parameter lists.
- **Overriding** (Module 03-04): derived class redefines a base function with the **same signature**. `ScavTrap::attack` overrides `ClapTrap::attack` — ScavTrap objects calling `attack()` get the ScavTrap message.

Calling the parent's version explicitly (useful to reuse code):

```cpp
void ScavTrap::attack(const std::string &target)
{
    ClapTrap::attack(target);   // run the base logic, then add flavor
    std::cout << "SC4V-TP style!" << std::endl;
}
```

⚠️ Subtlety: in C++98, without `virtual` (Module 04) an override only "wins" when you call through the derived type itself. A `ClapTrap *p = &scav; p->attack();` calls the **ClapTrap** version — that's the problem `virtual` fixes in Part 13. Module 03 lives with this; Module 04 fixes it.

## The ClapTrap family — what each exercise adds

- **ex00 ClapTrap:** plain class; private name/hit(10)/energy(10)/damage(0); `attack`, `takeDamage`, `beRepaired` each print a message; attacking/repairing costs 1 energy; can't act with 0 hit or 0 energy. Careful: `takeDamage` shouldn't bring hit points below 0. OCF applies (constructors/destructors print).
- **ex01 ScavTrap:** inherits; different messages; new stats (100/50/20); its own `attack` message; `guardGate()` prints "Gate keeper mode". Show construction/destruction chaining.
- **ex02 FragTrap:** same pattern again (100/100/30), `highFivesGuys()`.
- **ex03 DiamondTrap:** the weird one — Part 12.

---

# Part 12 — The diamond problem & virtual inheritance (Module 03 ex03)

## The problem

DiamondTrap inherits from **both** FragTrap **and** ScavTrap — which both inherit from ClapTrap:

```
      ClapTrap
      /      \
 FragTrap   ScavTrap
      \      /
     DiamondTrap
```

Without protection, a DiamondTrap would contain **two copies** of ClapTrap (one via FragTrap, one via ScavTrap) → ambiguous attributes (`_name`? whose?), ambiguous base, double construction/destruction. That's the **diamond problem**.

## The solution: virtual inheritance

Each middle class inherits from ClapTrap **virtually**:

```cpp
class FragTrap : virtual public ClapTrap { /* ... */ };
class ScavTrap : virtual public ClapTrap { /* ... */ };
class DiamondTrap : public FragTrap, public ScavTrap { /* ... */ };
```

With `virtual` inheritance, the ClapTrap sub-object is **shared** — exactly one instance exists inside any DiamondTrap, constructed once.

The price (know this for the defense): the **most derived class becomes responsible for constructing the virtual base**. DiamondTrap's constructor must call `ClapTrap(...)` itself, even though FragTrap/ScavTrap also list it — the base-class calls from the middle classes are ignored for the virtual base:

```cpp
DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name),          // virtual base — constructed by the most derived class
      FragTrap(name),
      ScavTrap(name),
      _name(name)              // its own name attribute (same variable name as ClapTrap's!)
{
    ClapTrap::_name = name + "_clap_name";  // ClapTrap's name gets the suffix
    _hitPoints = FragTrap::_hitPoints;      // stats: HP from FragTrap
    _energyPoints = ScavTrap::_energyPoints;  // energy from ScavTrap
    _attackDamage = FragTrap::_attackDamage;  // damage from FragTrap
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "I am " << _name << " and my ClapTrap name is "
              << ClapTrap::_name << std::endl;
}
```

Details the subject demands:

- DiamondTrap has its own `name` attribute **with the exact same variable name** as ClapTrap's (the `-Wshadow` warning in the subject is about this shadowing: the derived `_name` hides the inherited one — use `ClapTrap::_name` to reach the hidden one).
- `attack()` comes from **ScavTrap** (say so explicitly in the class: `using ScavTrap::attack;` in C++98 style, or define a wrapper that calls `ScavTrap::attack(target);`).
- Constructor order with virtual inheritance: virtual bases first (ClapTrap), then direct bases in **declaration order** (FragTrap then ScavTrap), then DiamondTrap's own body. Destructors run in reverse.

---

# Part 13 — Subtype polymorphism & virtual functions (Module 04)

## The problem `virtual` solves

Module 04 starts with Animal/Dog/Cat:

```cpp
class Animal
{
protected:
    std::string type;
public:
    void makeSound(void) const { std::cout << "..." << std::endl; }
};

class Dog : public Animal
{
public:
    void makeSound(void) const { std::cout << "Woof" << std::endl; }
};
```

Now the trap — the subject's own test:

```cpp
const Animal *j = new Dog();
j->makeSound();      // prints "..." — the ANIMAL sound! Why?
```

`j` has type `Animal *`. Without anything special, C++ picks the function by the **static type** (the type the pointer is declared with) — so Animal's version runs, even though the object really is a Dog. This is **static binding**.

## The fix: `virtual` → dynamic binding

```cpp
class Animal
{
protected:
    std::string type;
public:
    virtual void makeSound(void) const { std::cout << "..." << std::endl; }
    virtual ~Animal(void) {}          // virtual destructor — see below!
    std::string getType(void) const { return type; }
};

class Dog : public Animal
{
public:
    Dog(void) { type = "Dog"; }
    void makeSound(void) const { std::cout << "Woof" << std::endl; }  // overrides
};
```

Now:

```cpp
const Animal *j = new Dog();
j->makeSound();          // "Woof" — the DOG sound
delete j;                // ~Dog runs first, then ~Animal — correct cleanup
```

**Polymorphism** ("many forms"): one call site, `j->makeSound()`, many behaviors depending on the real object behind the pointer. With `virtual`, the decision is made at **runtime** based on the object's actual type (dynamic binding, implemented with a vtable — a table of function pointers attached to each object's class; evaluators love asking about it).

Rules and details:

- Mark a function `virtual` once in the base; it stays virtual in all derived classes (repeating the keyword in children is good style).
- The override must match signature **and const-ness**, or you accidentally create a new overload instead of overriding.
- **Always make the destructor virtual in a polymorphic base.** `Animal *a = new Dog(); delete a;` with a non-virtual destructor calls only `~Animal` — the Dog part is never destroyed (leak + UB). With `virtual ~Animal()`, `delete` through the base pointer destroys the full object, in the right order. This is *the* exam question of Module 04 ex01.
- Constructors can't be virtual; destructors must be (in polymorphic bases).

## The WrongAnimal/WrongCat test

The subject asks you to build the same zoo *without* virtual (WrongAnimal, WrongCat) and show that `WrongCat` through a `WrongAnimal *` produces the WrongAnimal sound — the control group proving you understand what `virtual` changes.

## An array of Animals (ex01) — and why pointers matter

```cpp
Animal *zoo[4];                 // array of POINTERS, not objects
for (int i = 0; i < 4; i++)
    (i % 2 == 0) ? (void)(zoo[i] = new Dog()) : (void)(zoo[i] = new Cat());

for (int i = 0; i < 4; i++)
    zoo[i]->makeSound();        // each makes ITS OWN sound — polymorphism

for (int i = 0; i < 4; i++)
    delete zoo[i];              // correct destructors chain, no leaks
```

Why an array of pointers and not `Animal zoo[4]`? An array of base **objects** would slice every Dog/Cat down to its Animal part (each element must be exactly `sizeof(Animal)`) — no polymorphism, no dog. Pointers are all the same size and can point at any derived object. ("Object slicing" — nice term to drop during evaluation.)

## Brain and deep copies (ex01, and everywhere)

Dog and Cat get a `Brain *` attribute — a pointer to a heap-allocated `Brain` holding 100 `ideas`:

```cpp
class Dog : public Animal
{
private:
    Brain *_brain;              // Dog OWNS its brain
public:
    Dog(void) : _brain(new Brain()) { type = "Dog"; }
    ~Dog(void) { delete _brain; }                     // free what you own

    Dog(const Dog &other) : Animal(other)             // copy constructor
    {
        type = other.type;
        _brain = new Brain(*other._brain);            // NEW brain, copied — DEEP copy
    }

    Dog &operator=(const Dog &other)
    {
        if (this != &other)
        {
            type = other.type;
            *_brain = *other._brain;                  // copy the IDEAS, not the pointer
        }
        return *this;
    }
};
```

**Shallow vs deep copy** — the central idea:

- **Shallow** (the compiler's default `operator=`): copies the *pointer* → two dogs share one brain. First destructor frees it; the second one deletes it again → double-free crash.
- **Deep**: allocate a **new** Brain and copy the *ideas* → two independent dogs.

Test it: copy a dog, change an idea in the copy, print both brains — originals and copies must differ. The subject explicitly requires this test.

---

# Part 14 — Abstract classes & interfaces (Module 04)

## Abstract class (ex02)

`Animal` makes no sense to instantiate — you never meet a generic animal. Make it **abstract** with a **pure virtual function**:

```cpp
class Animal
{
public:
    virtual void makeSound(void) const = 0;   // PURE virtual — note the = 0
    virtual ~Animal(void) {}
};

// Animal a;            // COMPILE ERROR: abstract class can't be instantiated
Animal *a = new Dog();  // fine: a DERIVED, CONCRETE class
```

`= 0` means "no implementation here — every concrete child MUST provide one". A class with ≥ 1 pure virtual function is **abstract**; it defines an interface of behavior, not a usable object. (Derived classes stay abstract until they implement every pure virtual function.)

## Interface (ex03) — pure abstract class

An **interface** is a class where *everything* is pure virtual — a pure contract with zero implementation. C++98 has no `interface` keyword; the convention:

```cpp
class ICharacter
{
public:
    virtual ~ICharacter(void) {}                       // virtual empty destructor
    virtual std::string const &getName(void) const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;
};
```

(The leading `I` is the naming convention for interfaces.) Classes *implement* it:

```cpp
class Character : public ICharacter { /* ... */ };
```

Users program against `ICharacter *` — they never need to know it's a Character. That decoupling is the whole point of interfaces.

## The Materia system — reading the design

**AMateria** — abstract base of all magic items:

```cpp
class AMateria
{
protected:
    std::string _type;
public:
    AMateria(std::string const &type);
    virtual ~AMateria(void);
    std::string const &getType(void) const;
    virtual AMateria *clone(void) const = 0;    // each child copies itself
    virtual void use(ICharacter &target);       // has an implementation... but children override
};
```

- `clone() = 0` is pure: `Ice` and `Cure` each return `new Ice(*this)` / `new Cure(*this)`. This is the **factory+prototype pattern**: new materias are made by cloning templates, without the caller knowing the concrete class.
- `use()` is virtual but implemented — children override to print their own effect.
- Copying a Materia into another: copying the type "doesn't make sense" (subject hint) — write `operator=` so it copies nothing (or nothing meaningful), keeping the existing type.

**Character** — implements `ICharacter`: 4 inventory slots (`AMateria *_inventory[4]`), equip into the first empty slot (0→3), ignore full-inventory/invalid-slot operations, `use(idx, target)` calls `_inventory[idx]->use(target)`. `unequip` must **not** delete — set the slot to NULL and (your choice) stash the pointer somewhere to delete later, so no leak. Deep copies: copy constructor/assignment must clone the other character's materias, deleting the old ones first.

**MateriaSource** — implements `IMateriaSource`: `learnMateria` *clones* the given materia into its 4 template slots; `createMateria(type)` clones the matching template (or returns NULL for unknown types).

The full main is in the subject; trace it and make sure every `new` has a `delete` (including unequipped materias, which is the classic leak).

## Pattern map (say these during the defense)

- **Polymorphism:** `Animal *` calling `makeSound()` runs the child's version.
- **Abstract class:** `Animal` with `makeSound() = 0` — not instantiable.
- **Interface:** `ICharacter` — all pure virtual, implemented by `Character`.
- **Prototype/factory:** `MateriaSource` learns templates; `createMateria` clones them.
- **Encapsulation:** private attributes + public functions everywhere.
- **Inheritance:** ClapTrap family, Animals, Materias.

---

# Part 15 — Deep copies, the Rule of Three, memory leaks

## The Rule of Three (the OCF, generalized)

If your class manages a resource (memory from `new`, a file...), the compiler-generated copies are *shallow* — you must write all three yourself:

1. **Destructor** — free the resource.
2. **Copy constructor** — deep-copy the resource into the new object.
3. **Copy assignment operator** — free your resource, deep-copy the other's, return `*this`.

Rule of thumb: need one of them → need all three. (C++ programmers call this the "Rule of Three/Five/Zero" — for these modules, three.) Classes without resources (Fixed, Point, ClapTrap) still write all four OCF members explicitly because the subject says so.

## Leak-hunting checklist for your modules

- Every `new` → exactly one `delete`; every `new[]` → one `delete[]`.
- Deleting through a **base pointer** → base destructor must be `virtual`.
- Deep copies mean each object deletes *its own* copy.
- `unequip` doesn't delete (subject rule) → keep the pointer somewhere and delete it at the end.
- Check with AddressSanitizer: compile your test main with `c++ -std=c++98 -g -fsanitize=address -Wall -Wextra -Werror *.cpp && ./a.out` — leaks print at exit.

---

# Part 16 — Makefiles for C++

Same rules as your C Makefiles: `$(NAME)`, `all`, `clean`, `fclean`, `re` — and never relink.

```makefile
NAME    = phonebook
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS    = main.cpp PhoneBook.cpp Contact.cpp
OBJS    = $(SRCS:.cpp=.o)
HEADER  = PhoneBook.hpp Contact.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

Notes:

- `CXX`/`CXXFLAGS` are the C++ conventions (C used `CC`/`CFLAGS`).
- `$<` = first prerequisite (the `.cpp`); `$@` = the target.
- Listing headers as prerequisites makes objects rebuild when headers change (not norm-required, but handy).
- In these 5 modules there is no `-lm` or extra libs — you never link anything beyond the standard library.

---

# Part 17 — Evaluation cheat-sheet & checklist

## The 30-second definitions (say these in your defense)

- **Class/object:** blueprint vs instance; attributes (data) + member functions (behavior).
- **Encapsulation:** `private` data behind a `public` interface; the class controls its own state.
- **Constructor/destructor:** automatic init/cleanup; initializer list initializes; chaining base-first, destroy reverse.
- **OCF / Rule of Three:** default ctor, copy ctor, `operator=`, dtor — all four, always (M02+), deep copies when resources exist.
- **static:** belongs to the class, shared by all objects; static functions need no object and touch no non-static state.
- **const:** promise not to modify; const member functions are the only ones callable on const objects; const reference parameters = cheap + read-only.
- **Reference vs pointer:** alias, can't be null, can't rebind, no deref syntax — vs address that can be null/reassigned. Reference for "always there", pointer for "maybe".
- **Stack vs heap:** automatic scope lifetime vs `new`/`delete` manual lifetime; stack by default, heap to outlive scope.
- **new/delete vs malloc/free:** constructors/destructors run; never mix them.
- **Overloading vs overriding:** same name different params (compile time) vs same signature in a derived class (runtime with virtual).
- **virtual:** call chosen by the object's real type at runtime (vtable); needed for polymorphism through base pointers; **virtual destructor** in polymorphic bases.
- **Pure virtual / abstract / interface:** `= 0`, no instantiation, children must implement; all-pure = interface.
- **Diamond problem:** two paths to one base → duplicate/ambiguous base; fixed by virtual inheritance; most-derived class constructs the virtual base.
- **Deep vs shallow copy:** copy the pointed-to resource, not the pointer; shallow = shared resource + double-free.
- **Member function pointer:** `void (Harl::*f)(void)`; call `(this->*f)()` — Harl's dispatch table.

## Pre-evaluation checklist (every exercise)

- [ ] Compiles with `-Wall -Wextra -Werror -std=c++98`, zero warnings
- [ ] No printf/malloc/free, no C++11, no STL, no `using namespace`, no `friend`, no code in headers, include guards present
- [ ] Every class: OCF from Module 02 on; messages in ctors/dtors where the subject wants them
- [ ] Attributes private (or protected in derived-class modules); getters const
- [ ] Every `new` has a `delete`; run an ASan build to prove no leaks
- [ ] Output matches the subject's examples **character for character** (including newlines)
- [ ] You can explain every line of your code, and you've written your own extra tests
- [ ] Makefile has `all/clean/fclean/re`, doesn't relink; executable has a relevant name

## Suggested learning order

1. Read this guide once, fast, to see the map.
2. Do Module 00 with the guide open at Parts 1–4; do the exercises *before* rereading — struggle first.
3. Module 01 (Parts 5–8): draw the stack/heap diagrams; explain to a peer why newZombie uses the heap.
4. Module 02 (Parts 9–10): OCF until it's muscle memory; the Fixed arithmetic table is the heart of it.
5. Module 03 (Parts 11–12): watch the constructor/destructor chains in your own output.
6. Module 04 (Parts 13–15): the big payoff — reread Parts 13–14 until "why virtual destructor?" is an instant answer.
7. Before each evaluation, reread Part 17 and try to answer the 30-second definitions out loud.

**The meta-skill:** every module's exercises are examples of the same few ideas (encapsulation → lifetime → copying → hierarchy → runtime binding). If you can re-explain each exercise with those words, you've actually learned C++ — not just passed a module. Good luck, and by Odin, use your brain!
