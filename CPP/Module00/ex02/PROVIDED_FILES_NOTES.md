# Module00 / ex02 — Line-by-line notes for the provided files

The subject provides `Account.hpp` and `tests.cpp` — you must **not** modify them.
These notes explain every line so you can read them with confidence. Your own
`Account.cpp` has the same explanations as inline comments directly in the file.

---

## Account.hpp — the class declaration

```cpp
#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
```
- Two mechanisms doing the same job: `#pragma once` (modern shortcut) and
  classic include guards. Both prevent the header from being included twice,
  which would redeclare the class and break compilation.

```cpp
class Account {
public:
    typedef Account t;
```
- `typedef Account t;` creates an alias: `Account::t` is another name for
  `Account`. It exists only for the convenience of `tests.cpp`.

```cpp
    static int  getNbAccounts( void );
    static int  getTotalAmount( void );
    static int  getNbDeposits( void );
    static int  getNbWithdrawals( void );
    static void displayAccountsInfos( void );
```
- Five **static member functions**: they belong to the class, not to an
  object. You call them as `Account::getNbAccounts()` — no account needed.
  They read the shared (static) statistics.

```cpp
    Account( int initial_deposit );
    ~Account( void );
```
- The normal constructor (creates an account with a starting deposit) and
  the destructor (prints the "closed" line).

```cpp
    void    makeDeposit( int deposit );
    bool    makeWithdrawal( int withdrawal );
    int     checkAmount( void ) const;
    void    displayStatus( void ) const;
```
- The per-account operations. The trailing `const` on `checkAmount` and
  `displayStatus` means "does not modify the account" — that's why they can
  be called through `std::mem_fun_ref` on the accounts in the test.

```cpp
private:
    static int  _nbAccounts;        // shared: number of accounts created
    static int  _totalAmount;       // shared: sum of all amounts
    static int  _totalNbDeposits;   // shared: total deposits
    static int  _totalNbWithdrawals;// shared: total withdrawals
    static void _displayTimestamp( void );
```
- The four **static attributes**: one shared copy for the whole program
  (the global statistics). Declared here, defined in Account.cpp.

```cpp
    int _accountIndex;   // this account's number (0, 1, 2, ...)
    int _amount;         // money currently in THIS account
    int _nbDeposits;     // deposits made on THIS account
    int _nbWithdrawals;  // withdrawals made on THIS account

    Account( void );     // private default constructor: outsiders
                         // can never create an "empty" account
};
#endif /* __ACCOUNT_H__ */
```
- The four per-object attributes (each account has its own copy) plus the
  private timestamp helper. Making the default constructor private forbids
  code outside the class from calling `Account a;` with no deposit.

---

## tests.cpp — what the provided main actually does

```cpp
#include <vector>
#include <algorithm>
#include <functional>
```
- The STL headers used by the test (allowed here: this file is provided —
  the no-STL rule applies to code YOU write).

```cpp
typedef std::vector<Account::t>  accounts_t;
typedef std::vector<int>         ints_t;
typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;
```
- Type aliases to keep the code short:
  - `accounts_t` = a growable array of Accounts (`Account::t` = `Account`).
  - `ints_t` = a growable array of ints.
  - `acc_int_t` = a pair of two iterators (one into each array) used to walk
    both arrays side by side.

```cpp
int const amounts[] = { 42, 54, 957, 432, 1234, 0, 754, 16576 };
size_t const amounts_size( sizeof(amounts) / sizeof(int) );
accounts_t accounts( amounts, amounts + amounts_size );
```
- 8 starting deposits. `sizeof(amounts)/sizeof(int)` = number of elements
  (total bytes / bytes per int). The `accounts` vector is built by copying
  the range `[amounts, amounts + 8)` — each value creates an Account via
  the `Account(int)` constructor (that's the 8 "created" log lines).

```cpp
accounts_t::iterator acc_begin = accounts.begin();
accounts_t::iterator acc_end   = accounts.end();
```
- Iterators = generalized pointers into the vector. `begin()` points at the
  first element; `end()` points one PAST the last (the standard C++ loop
  convention: valid elements live in `[begin, end)`).

```cpp
int const d[] = { 5, 765, 564, 2, 87, 23, 9, 20 };
...ints_t deposits( d, d + d_size ); ...
int const w[] = { 321, 34, 657, 4, 76, 275, 657, 7654 };
...ints_t withdrawals( w, w + w_size ); ...
```
- Same pattern: the deposit amounts and withdrawal amounts, one per account.

```cpp
Account::displayAccountsInfos();
std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
```
- `displayAccountsInfos()` prints the global statistics line.
- `std::for_each(first, last, f)` applies the function `f` to every element
  in the range — a loop in disguise.
- `std::mem_fun_ref(&Account::displayStatus)` wraps a member function into
  such a callable: for each account `a`, it calls `a.displayStatus()`.
  Net effect: print the status of every account.

```cpp
for ( acc_int_t it( acc_begin, dep_begin );
      it.first != acc_end && it.second != dep_end;
      ++(it.first), ++(it.second) ) {
    (*(it.first)).makeDeposit( *(it.second) );
}
```
- A "parallel walk" over both arrays:
  - `it` is a pair holding an account iterator (`it.first`) and a deposit
    iterator (`it.second`), both starting at the beginning.
  - Loop while neither has reached its end.
  - The comma expression `++(it.first), ++(it.second)` advances BOTH
    iterators after each turn.
  - `*(it.first)` = the account, `*(it.second)` = the deposit amount:
    so each account `i` deposits `deposits[i]`.
- The identical loop afterwards calls `makeWithdrawal` the same way.

```cpp
return 0;
```
- At the end of `main`, the two vectors are destroyed automatically: every
  Account destructor runs (in whatever order the vector frees them), which
  is the block of "closed" lines at the end of the log.

---

## Why the output has timestamps in brackets

Every message starts with `_displayTimestamp()` printing
`[YYYYMMDD_HHMMSS] ` — e.g. `[19920104_091532]`. The log file you were given
shows the same format with 1992 dates because that's when the tests were
run; your output matches except for the timestamps, exactly as the subject
allows.
