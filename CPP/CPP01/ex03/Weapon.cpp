/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by kelle             #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp" // Include the class definition so the compiler knows the members

// Default constructor: leaves the type empty, the weapon can be named later with setType.
Weapon::Weapon(void)
{
}

// Parametric constructor: initializes the type at construction time via the initializer list.
Weapon::Weapon(const std::string &type) : _type(type)
{
}

// Destructor: std::string cleans itself up, so there is nothing manual to free here.
Weapon::~Weapon(void)
{
}

// getType: returns a CONSTANT REFERENCE to the private attribute.
// A reference avoids copying the whole string (cheap), and 'const' guarantees the caller
// cannot modify the weapon's type through the returned reference (read-only access).
const std::string &Weapon::getType(void) const
{
	return (_type); // Return the internal string by const reference
}

// setType: replaces the current type with the new one passed as a parameter.
// This is exactly what makes the test program print "some other type of club" on the 2nd attack.
void Weapon::setType(const std::string &type)
{
	_type = type; // Overwrite the private attribute with the new value
}
