/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by kelle             #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"   // Include the class definition so the compiler knows the members
#include <iostream>   // std::cout and std::endl are used to print Harl's complaints
#include <cstddef>    // size_t is used for counting the table entries

// Default constructor: Harl needs no state, the four functions are just messages.
Harl::Harl(void)
{
}

// Destructor: nothing dynamic is owned by Harl, so nothing to free here.
Harl::~Harl(void)
{
}

// debug: the "DEBUG" level message, exactly as given in the subject.
void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	std::cout << std::endl; // Blank line to separate this complaint from the next one
}

// info: the "INFO" level message, exactly as given in the subject.
void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl; // Blank line separator
}

// warning: the "WARNING" level message, exactly as given in the subject.
void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
	std::cout << std::endl; // Blank line separator
}

// error: the "ERROR" level message, exactly as given in the subject.
void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl; // Blank line separator
}

// complain: dispatches ONE complaint using pointers to member functions (same trick as ex05).
// This function is reused by filter() for each individual level to be printed.
void Harl::complain(std::string level)
{
	// Lookup tables: names[i] goes with functions[i], same index, same order.
	const char *names[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	// Compare the requested level with each known level name and call the matching function.
	for (size_t i = 0; i < 4; i++)
	{
		if (level == names[i]) // Exact string comparison between the level and the table entry
		{
			(this->*functions[i])(); // Pointer-to-member call: needs 'this' and the (this->*pf)() syntax
			return;                  // Done: the level was found and printed
		}
	}

	// Unknown level: Harl's generic fallback message.
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

// filter: prints the requested level AND every level ABOVE it.
//
// THE TRICK of this exercise is to use a SWITCH statement: convert the level string to its
// integer index, then fall through the switch on purpose. In C++, cases fall through when
// there is no 'break', so "case 2" executes both warning() AND error(): exactly the
// "this level and above" behavior the subject asks for.
void Harl::filter(std::string level)
{
	// Convert the level name into a small integer code the switch can work with.
	// -1 means "unknown level" and will hit the default case of the switch.
	int code = -1;
	if (level == "DEBUG")    // Index 0 in the level hierarchy
		code = 0;
	else if (level == "INFO")     // Index 1
		code = 1;
	else if (level == "WARNING")  // Index 2
		code = 2;
	else if (level == "ERROR")    // Index 3
		code = 3;

	switch (code) // Switch on the numeric level code
	{
		case 0: // "DEBUG" was asked: everything must be printed, from debug up to error
			complain("DEBUG"); // No 'break' here, we want to keep printing the next levels
			// fall through
		case 1: // Reached when "INFO" or higher was asked
			complain("INFO"); // Keep printing: WARNING and ERROR must follow
			// fall through
		case 2: // Reached when "WARNING" or higher was asked
			complain("WARNING"); // Fall through to the last level
			// fall through
		case 3: // Reached when "ERROR" (or any higher level) was asked
			complain("ERROR"); // Last level, then...
			break;             // ...break stops the fall-through before the default case
		default:               // Received for any unknown level (code == -1)
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break; // End of the switch, nothing left to print
	}
}
