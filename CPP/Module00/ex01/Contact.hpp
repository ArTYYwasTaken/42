// Include guard part 1: "if CONTACT_HPP is not defined yet..."
// It prevents this header from being pasted twice into the same file
// (double inclusion would redeclare the class and fail to compile)
#ifndef CONTACT_HPP
// Include guard part 2: "...then define it now"
# define CONTACT_HPP

// The string class: we store each field as a std::string
#include <string>

// Number of fields a contact has (used to size the array below)
#define CONTACT_FIELD_COUNT 5

/* Contact field indexes */
// Symbolic names for the array positions in _fields[],
// so the code reads getField(FIELD_NICKNAME) instead of getField(2)
#define FIELD_FIRST_NAME 0
#define FIELD_LAST_NAME 1
#define FIELD_NICKNAME 2
#define FIELD_PHONE_NUMBER 3
#define FIELD_DARKEST_SECRET 4

// Class that represents ONE phonebook contact.
// It bundles the data (the 5 fields) with the functions that manage it.
class Contact
{

public:
	// Anything under "public:" can be used from OUTSIDE the class

	Contact(void);
	~Contact(void);

	// Stores "value" into the field number "field_index".
	// Returns true if the index was valid, false otherwise.
	// "const std::string &" = passed by reference (no copy) and read-only.
	bool				setField(int field_index, const std::string &value);
	// Returns the field number "field_index".
	// Returns it by const reference: no copy, and the caller cannot modify it.
	// The trailing "const" = this function never modifies the Contact itself
	// (required to be callable on const Contact objects).
	const std::string	&getField(int field_index) const;
	// Returns true only if every field has been filled (no empty string)
	bool				isComplete(void) const;

private:
	// Anything under "private:" can only be touched by the class itself.
	// This is encapsulation: outside code goes through setField/getField.

	// The 5 fields stored in one fixed-size array
	// (dynamic allocation is forbidden in this exercise, so no new/delete)
	std::string	_fields[CONTACT_FIELD_COUNT];

};

// Include guard part 3: closes the #ifndef opened at the top.
// From here on, CONTACT_HPP is defined, so a second inclusion is skipped.
#endif
