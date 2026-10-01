// std::cout / std::cin for user interaction
#include <iostream>
// std::setw — sets column width for the formatted table
#include <iomanip>
// std::istringstream — used to parse the index typed by the user
#include <sstream>
// std::string
#include <string>

// The two classes of the exercise
#include "Contact.hpp"
#include "PhoneBook.hpp"

// Helper: ask the user for ONE field, re-asking until the input is
// non-empty (the subject forbids empty fields in a saved contact).
// "static" at file scope = this function is only visible in this file.
static std::string	promptField(const std::string &field_name)
{
	// Buffer that receives the line the user types
	std::string	line;

	// Loop forever (we leave via return or a failed getline)
	while (true)
	{
		// Show the prompt, e.g. "First name: "
		std::cout << field_name << ": ";
		// getline reads a WHOLE line (spaces included) from the keyboard.
		// It returns false when reading fails (EOF, i.e. Ctrl+D) —
		// in that case return "" to signal "abandon".
		if (!std::getline(std::cin, line))
			return ("");
		// Non-empty line: this is our answer
		if (!line.empty())
			return (line);
		// Empty input: warn and loop back to re-ask
		std::cout << "A saved contact can't have empty fields." << std::endl;
	}
}

// Helper: prepare a string for a 10-character column.
// Longer than 10 chars -> keep 9 characters and add a dot ('.')
// (subject rule for truncation).
static std::string	formatColumn(const std::string &text)
{
	if (text.length() > 10)
		// substr(0, 9) = the first 9 characters, then append "."
		return (text.substr(0, 9) + ".");
	// Short enough: use it as-is (setw will pad it)
	return (text);
}

// Constructor. The initializer list ": _contactCount(0)" initializes
// the counter to 0 = "empty phonebook at startup" (subject rule).
// The _contacts array is built automatically (8 default Contacts).
PhoneBook::PhoneBook(void) : _contactCount(0)
{
}

// Destructor. Nothing to free: no pointers, no new/delete anywhere.
PhoneBook::~PhoneBook(void)
{
}

// ADD command: read the 5 fields, then save the contact.
void	PhoneBook::addContact(void)
{
	// A temporary contact, filled before being stored
	Contact			contact;
	// The prompts to show, one per field index
	// (0..4, same order as the FIELD_* macros in Contact.hpp)
	const char		*field_names[CONTACT_FIELD_COUNT] = {
		"First name", "Last name", "Nickname",
		"Phone number", "Darkest secret"
	};

	// Ask for each field, one at a time
	for (int i = 0; i < CONTACT_FIELD_COUNT; ++i)
	{
		// promptField loops internally until the line is non-empty
		std::string	value = promptField(field_names[i]);

		// An empty value means the user hit EOF (Ctrl+D):
		// abort the creation, nothing is saved
		if (value.empty())
		{
			std::cout << "Contact creation aborted." << std::endl;
			return;
		}
		// Store the value into field number i of the temporary contact
		contact.setField(i, value);
	}
	// Phonebook already full? (subject: replace the OLDEST contact)
	if (_contactCount == PHONEBOOK_MAX_CONTACTS)
	{
		// Shift every contact one slot to the left:
		// slot 0 (oldest) is overwritten by slot 1, etc.
		for (int i = 1; i < PHONEBOOK_MAX_CONTACTS; ++i)
			_contacts[i - 1] = _contacts[i];
		// The new contact lands in the last slot
		_contacts[PHONEBOOK_MAX_CONTACTS - 1] = contact;
	}
	else
	{
		// Not full: append at the first free slot and count it
		_contacts[_contactCount] = contact;
		++_contactCount;
	}
	std::cout << "Contact saved." << std::endl;
}

// Print the 4-column table: index, first name, last name, nickname.
// Each column is 10 characters wide, separated by '|', right-aligned.
void	PhoneBook::displayList(void) const
{
	// Make every following output right-aligned (subject requirement).
	// This setting sticks until changed.
	std::cout << std::right;
	// Header row. setw(10) applies to the NEXT printed item only,
	// so it must be repeated before each column.
	std::cout << "|" << std::setw(10) << "Index"
		<< "|" << std::setw(10) << "First name"
		<< "|" << std::setw(10) << "Last name"
		<< "|" << std::setw(10) << "Nickname"
		<< "|" << std::endl;
	// One row per stored contact
	for (int i = 0; i < _contactCount; ++i)
	{
		// Column 1: the index (an int, printed right-aligned in 10 chars)
		std::cout << "|" << std::setw(10) << i
			// Columns 2-4: the fields, truncated to 10 chars by
			// formatColumn() before setw pads them
			<< "|" << std::setw(10)
			<< formatColumn(_contacts[i].getField(FIELD_FIRST_NAME))
			<< "|" << std::setw(10)
			<< formatColumn(_contacts[i].getField(FIELD_LAST_NAME))
			<< "|" << std::setw(10)
			<< formatColumn(_contacts[i].getField(FIELD_NICKNAME))
			// _contacts[i] is an object, so access with '.' (not '->')
			<< "|" << std::endl;
	}
}

// Print one contact, one field per line (including the darkest secret).
void	PhoneBook::displayContact(int index) const
{
	// A const reference to the chosen contact:
	// no copy, and it cannot be modified through it
	const Contact	&contact = _contacts[index];

	// Print all 5 fields, one per line
	std::cout << "First name: "
		<< contact.getField(FIELD_FIRST_NAME) << std::endl;
	std::cout << "Last name: "
		<< contact.getField(FIELD_LAST_NAME) << std::endl;
	std::cout << "Nickname: "
		<< contact.getField(FIELD_NICKNAME) << std::endl;
	std::cout << "Phone number: "
		<< contact.getField(FIELD_PHONE_NUMBER) << std::endl;
	std::cout << "Darkest secret: "
		<< contact.getField(FIELD_DARKEST_SECRET) << std::endl;
}

// SEARCH command: show the list, then show the requested contact.
void	PhoneBook::searchContacts(void) const
{
	// Raw line typed by the user
	std::string			line;
	// Stream that lets us read from a string ("in-memory stream")
	std::istringstream	iss;
	// Parsed index
	int					index;
	// Receives any character found after the number, used to
	// detect inputs like "1abc" or "1 2"
	char				trailing;

	// Nothing stored yet -> nothing to display
	if (_contactCount == 0)
	{
		std::cout << "The phonebook is empty." << std::endl;
		return;
	}
	// Show the 4-column table first (subject requirement)
	displayList();
	// Ask which entry to display
	std::cout << "Index: ";
	// EOF while asking: just give up quietly
	if (!std::getline(std::cin, line))
		return;
	// Feed the typed line into the parsing stream
	iss.str(line);
	// Two checks in one condition:
	// 1. "iss >> index" fails if the line doesn't START with a number
	// 2. "iss >> trailing" SUCCEEDS if anything is left after the
	//    number (letters, spaces...) -> also invalid
	// Note: "!(a) || (b)" — evaluate 1, and only if it passed, try 2
	if (!(iss >> index) || (iss >> trailing))
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	// The number must point at an existing contact
	if (index < 0 || index >= _contactCount)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	// All checks passed: display the full contact
	displayContact(index);
}
