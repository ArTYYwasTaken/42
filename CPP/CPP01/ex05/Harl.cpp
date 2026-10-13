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

// complain: dispatches Harl to the right complaint function WITHOUT if/else chains.
//
// How it works: we build a small table pairing each level name with a POINTER TO MEMBER
// FUNCTION. A pointer to a member of Harl taking no arguments and returning void has the type
// "void (Harl::*)(void)", and it is called with the special (this->*pf)() syntax,
// because such a pointer always needs to know WHICH object it acts on.
//
// Note we do NOT use 'using namespace' (forbidden) and no if/else if forest (the whole point).
void Harl::complain(std::string level)
{
	// The two lookup tables: names[i] goes with functions[i], same index, same order.
	// const keeps both tables read-only; the arrays live only during this function call.
	const char *names[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	// Walk the table: compare the requested level with each known level name.
	// No <algorithm> allowed at this module, so a plain loop (not std::find) is used.
	for (size_t i = 0; i < 4; i++)
	{
		// std::string and const char* compare equal when the contents match exactly.
		if (level == names[i])
		{
			// Call the member function pointed to: (this->*functions[i])()
			// 'this' supplies the object, '.*'/'->*' dereferences the member pointer,
			// the extra parentheses are required by the grammar.
			(this->*functions[i])();
			return; // Level found and complain-ed: nothing more to do
		}
	}

	// If we arrive here, the level was unknown: Harl has nothing clever to say about it.
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
