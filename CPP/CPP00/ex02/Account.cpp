// std::cout for all the required output messages
#include <iostream>
// std::time, std::strftime, std::localtime for the timestamp display
#include <ctime>

// The class we are implementing (declared in the provided Account.hpp)
#include "Account.hpp"

// ----------------------------------------------------------------------------
// STATIC ATTRIBUTES — defined (and initialized) here, once.
// A static member is only DECLARED in the header; it must be DEFINED in a
// .cpp file. These live outside any object: ONE copy shared by all accounts.
// They start at 0 because the program hasn't created anything yet.
// ----------------------------------------------------------------------------

// Total number of Account objects ever created
int	Account::_nbAccounts = 0;
// Sum of the amounts of every existing account
int	Account::_totalAmount = 0;
// Total number of deposits made on all accounts
int	Account::_totalNbDeposits = 0;
// Total number of withdrawals made on all accounts
int	Account::_totalNbWithdrawals = 0;

// ----------------------------------------------------------------------------
// CONSTRUCTOR — runs when an Account is created with an initial deposit.
// The initializer list (after ':') initializes each attribute directly.
// ----------------------------------------------------------------------------

Account::Account(int initial_deposit)
	// This account gets the next available index:
	// the first account sees _nbAccounts == 0 -> index 0, and so on
	: _accountIndex(_nbAccounts),
	  // The account starts holding exactly the initial deposit
	  _amount(initial_deposit),
	  // A fresh account has made no deposits and no withdrawals yet
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
	// One more account exists in total
	_nbAccounts++;
	// Its deposit joins the global total
	_totalAmount += initial_deposit;
	// Print the "[YYYYMMDD_HHMMSS] " timestamp prefix
	_displayTimestamp();
	// Then the required "created" line, e.g.:
	// [19920104_091532] index:0;amount:42;created
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created" << std::endl;
}

// ----------------------------------------------------------------------------
// PRIVATE DEFAULT CONSTRUCTOR — declared in Account.hpp but never meant to be
// used (the subject's tests only create accounts WITH a deposit).
// It must still be implemented because the class declares it.
// ----------------------------------------------------------------------------

Account::Account(void)
	// All attributes initialized to zero
	: _accountIndex(0),
	  _amount(0),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
}

// ----------------------------------------------------------------------------
// DESTRUCTOR — runs when an Account object dies (e.g. a std::vector of
// accounts is destroyed at the end of main). Prints the "closed" line.
// ----------------------------------------------------------------------------

Account::~Account(void)
{
	// Timestamp prefix first
	_displayTimestamp();
	// e.g. [19920104_091532] index:0;amount:42;closed
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

// ----------------------------------------------------------------------------
// STATIC GETTERS — they read the static attributes.
// They are static: called on the CLASS (Account::getNbAccounts()), they
// need no object. They must not be const (const applies to objects).
// ----------------------------------------------------------------------------

int	Account::getNbAccounts(void)
{
	// How many accounts exist
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	// Sum of all account amounts
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	// Total deposits over all accounts
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	// Total withdrawals over all accounts
	return (_totalNbWithdrawals);
}

// ----------------------------------------------------------------------------
// makeDeposit — add money to THIS account and update the global totals.
// ----------------------------------------------------------------------------

void	Account::makeDeposit(int deposit)
{
	// Save the amount BEFORE the deposit:
	// the required output line starts with "p_amount:" (previous amount)
	int	p_amount = _amount;

	// The deposit is added to this account's amount
	_amount += deposit;
	// This account has made one more deposit
	_nbDeposits++;
	// Global total of money grows too
	_totalAmount += deposit;
	// Global deposit counter grows too
	_totalNbDeposits++;
	// Timestamp prefix
	_displayTimestamp();
	// e.g. [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
}

// ----------------------------------------------------------------------------
// makeWithdrawal — try to remove money. Refused if it would overdraw.
// Returns true if accepted, false if refused.
// ----------------------------------------------------------------------------

bool	Account::makeWithdrawal(int withdrawal)
{
	// Amount before the withdrawal (for the "p_amount:" output)
	int		p_amount = _amount;
	// A withdrawal is accepted only if the account can cover it
	bool	accepted = (withdrawal <= p_amount);

	// Timestamp prefix is printed in BOTH cases (accepted or refused)
	_displayTimestamp();
	// Start of the line, e.g. [..] index:1;p_amount:819;withdrawal:
	// (no newline yet — the rest depends on the decision below)
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";withdrawal:";
	if (accepted)
	{
		// Remove the money from this account
		_amount = p_amount - withdrawal;
		// This account's withdrawal counter
		_nbWithdrawals++;
		// Global totals decrease
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		// Finish the line, e.g. 321;amount:498;nb_withdrawals:1
		std::cout << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals
			<< std::endl;
	}
	else
	{
		// Not enough money: the log just says "refused"
		std::cout << "refused" << std::endl;
	}
	// Tell the caller whether it worked
	return (accepted);
}

// ----------------------------------------------------------------------------
// checkAmount — "how much do I hold?" A const member function:
// it reads the object without modifying it.
// ----------------------------------------------------------------------------

int	Account::checkAmount(void) const
{
	return (_amount);
}

// ----------------------------------------------------------------------------
// displayStatus — print this account's current state (called per account
// by the tests, via std::for_each).
// ----------------------------------------------------------------------------

void	Account::displayStatus(void) const
{
	// Timestamp prefix
	_displayTimestamp();
	// e.g. [19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}

// ----------------------------------------------------------------------------
// displayAccountsInfos — print the GLOBAL (static) statistics.
// Static function: called as Account::displayAccountsInfos(), no object.
// ----------------------------------------------------------------------------

void	Account::displayAccountsInfos(void)
{
	// Timestamp prefix
	_displayTimestamp();
	// e.g. [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
	std::cout << "accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
		<< std::endl;
}

// ----------------------------------------------------------------------------
// _displayTimestamp — private helper shared by every message.
// Prints "[YYYYMMDD_HHMMSS] " using the current system time.
// The exact format must match the provided log file.
// ----------------------------------------------------------------------------

void	Account::_displayTimestamp(void)
{
	// Holds the current time as an opaque number (seconds since 1970)
	std::time_t	now;
	// Character buffer that will receive the formatted date string.
	// 20 bytes is enough: "19920104_091532" = 15 chars + '\0' + margin
	char		buffer[20];

	// Grab the current time
	now = std::time(NULL);
	// Format it into the buffer:
	// %Y = 4-digit year, %m = month, %d = day, "_" literal,
	// %H = hour, %M = minute, %S = second -> "19920104_091532"
	// localtime converts the raw time into calendar fields
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S",
		std::localtime(&now));
	// Print the final prefix, e.g. "[19920104_091532] "
	std::cout << "[" << buffer << "] ";
}
