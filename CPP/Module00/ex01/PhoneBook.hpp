// Include guard: same pattern as Contact.hpp — prevents double inclusion
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

// std::string is used in this header (for member function parameters)
#include <string>

// Contact class: the PhoneBook stores an array of Contact objects
#include "Contact.hpp"

// Maximum number of contacts the phonebook can hold (subject rule)
#define PHONEBOOK_MAX_CONTACTS 8

// Class that manages the collection of contacts and the user interaction
// for ADD and SEARCH. It OWNS the contacts (composition: a PhoneBook
// "has an array of Contacts").
class PhoneBook
{

public:
	// Usable from outside (main.cpp calls these two)

	PhoneBook(void);
	~PhoneBook(void);

	// Prompts the user field by field and saves a new contact.
	// When the phonebook is full, it replaces the oldest contact.
	void	addContact(void);
	// Displays the 4-column list, then asks for an index and
	// prints the full contact. const = it doesn't modify the phonebook.
	void	searchContacts(void) const;

private:
	// Only PhoneBook itself may touch these

	// Fixed array of 8 Contact objects — no dynamic allocation
	// (forbidden in this exercise). Built once, at construction.
	Contact	_contacts[PHONEBOOK_MAX_CONTACTS];
	// How many contacts are actually stored (0 at startup)
	int		_contactCount;

	// Internal helpers: "private" because main() never needs them.
	// They print the 4-column table and one full contact.
	void	displayList(void) const;
	void	displayContact(int index) const;

};

#endif
