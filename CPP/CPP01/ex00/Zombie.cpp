/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by kelle             #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"      // Include the class definition so the compiler knows the members
#include <iostream>        // std::cout and std::endl are used to print on screen

// Default constructor: does nothing special, the name stays empty until setName is called.
Zombie::Zombie(void)
{
}

// Parametric constructor: stores the name given as a parameter in the private attribute.
Zombie::Zombie(std::string name) : _name(name) // The initializer list syntax copies 'name' directly into _name
{
}

// Destructor: the subject requires it to print a debug message containing the zombie's name.
// It is called automatically when the zombie goes out of scope (stack) or when delete is used (heap),
// which guarantees the "zombies must be destroyed when you no longer need them" rule.
Zombie::~Zombie(void)
{
	// Print a debugging line so we can see exactly when each zombie is destroyed.
	std::cout << _name << ": destroyed" << std::endl;
}

// announce: prints the zombie's announcement exactly in the format required by the subject.
// 'const' at the end means this function does not modify any member of the class.
void Zombie::announce(void) const
{
	// Print "<name>: BraiiiiiiinnnzzzZ..." (angle brackets are NOT printed, per the subject).
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// setName: allows giving (or renaming) a zombie after it has been created with the default constructor.
void Zombie::setName(std::string name)
{
	_name = name; // Simply overwrite the private attribute with the new value
}
