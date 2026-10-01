// std::cout and std::cin for the command loop
#include <iostream>
// std::string and std::getline
#include <string>

// The PhoneBook class this program is built around
#include "PhoneBook.hpp"

// Program entry point. No command-line arguments needed here.
int	main(void)
{
	// The ONE phonebook instance (the subject demands it be an
	// instance of the PhoneBook class, not a pointer to one).
	// It lives on the stack and is destroyed automatically at the end.
	PhoneBook	phonebook;
	// Buffer for the command the user types
	std::string	command;

	// Main loop: run until EXIT (break) or EOF (break)
	while (true)
	{
		// Show the prompt
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		// Read a whole line. If reading fails (Ctrl+D / EOF),
		// leave the loop so the program exits cleanly.
		if (!std::getline(std::cin, command))
			break;
		// The subject only accepts these three commands:
		if (command == "ADD")
			phonebook.addContact();       // create and save a contact
		else if (command == "SEARCH")
			phonebook.searchContacts();   // list then display one contact
		else if (command == "EXIT")
			break;                        // quit (contacts are lost forever)
		// Any other input is ignored: the loop simply starts over
	}
	// Returning 0 destroys 'phonebook' automatically (its destructor runs)
	return (0);
}
