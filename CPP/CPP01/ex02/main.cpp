/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by kelle             #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>    // std::cout and std::endl to print the results
#include <string>      // std::string, the type of the variable we point/ref to

int main(void)
{
	// A string variable initialized to "HI THIS IS BRAIN", as required by the subject.
	std::string brain = "HI THIS IS BRAIN";

	// stringPTR: a POINTER to the string. It stores the ADDRESS of 'brain' and can be
	// re-assigned later, can be NULL, and must be dereferenced (*) to read the value.
	std::string *stringPTR = &brain; // '&' takes the address of brain

	// stringREF: a REFERENCE to the string. It is an ALIAS: once bound at initialization,
	// it can never point to something else, can never be null, and is dereferenced implicitly.
	std::string &stringREF = brain;  // No '&' taken here: brain and stringREF are the same object

	// --- Addresses section: all three must be the exact same memory address ---
	std::cout << "Address of brain     (variable): " << &brain << std::endl;
	std::cout << "Address held by stringPTR        : " << stringPTR << std::endl;
	std::cout << "Address held by stringREF        : " << &stringREF << std::endl;

	// --- Values section: all three must print the same content ---
	std::cout << "Value of brain       (variable): " << brain << std::endl;
	std::cout << "Value pointed by stringPTR      : " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF      : " << stringREF << std::endl;

	return (0); // Tell the OS the program ended successfully
}
