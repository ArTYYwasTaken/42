// We implement the class declared in this header,
// so include it first (it brings std::string with it)
#include "Contact.hpp"

// Default constructor. Called when a Contact is created
// (e.g. "Contact contact;" inside addContact()).
// Nothing to do: std::string members are empty by default.
Contact::Contact(void)
{
}

// Destructor. Called when the Contact dies (end of scope).
// Nothing to free: std::string cleans itself up.
Contact::~Contact(void)
{
}

// Store "value" into the field at "field_index".
// "Contact::" means this function belongs to the Contact class.
bool	Contact::setField(int field_index, const std::string &value)
{
	// Reject out-of-range indexes instead of corrupting memory
	if (field_index < 0 || field_index >= CONTACT_FIELD_COUNT)
		return (false);
	// Assign the value into the array slot (std::string copies it)
	_fields[field_index] = value;
	// Success
	return (true);
}

// Return the field at "field_index", read-only.
const std::string	&Contact::getField(int field_index) const
{
	// A function-local static: ONE shared empty string that lives
	// for the whole program. We need it because we must return a
	// reference (something that exists) even for a bad index.
	static const std::string	empty;

	// Guard against a bad index: return the shared empty string
	if (field_index < 0 || field_index >= CONTACT_FIELD_COUNT)
		return (empty);
	// Valid index: return the real field.
	// Returning a reference means "no copy is made" — the caller
	// gets a direct, read-only view of the string inside the Contact.
	return (_fields[field_index]);
}

// A contact is complete when all 5 fields are non-empty.
bool	Contact::isComplete(void) const
{
	// Walk over every field index
	for (int i = 0; i < CONTACT_FIELD_COUNT; ++i)
	{
		// empty() is true for "" — one empty field breaks completeness
		if (_fields[i].empty())
			return (false);
	}
	// None was empty: the contact is complete
	return (true);
}
