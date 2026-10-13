/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by kelle             #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp" // Include the class definition so the compiler knows the members
#include <iostream>   // std::cout and std::endl are used to print the attack message

// Constructor: takes only the name. The weapon pointer starts as NULL because HumanB
// "may not always have a weapon": he is unarmed until setWeapon is called.
HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL)
{
}

// Destructor: the weapon is NOT owned by HumanB (it lives elsewhere, e.g. in main),
// so HumanB must NOT delete it: it would destroy someone else's object.
HumanB::~HumanB(void)
{
}

// setWeapon: arms the human by remembering the address of the weapon passed in.
// From now on the pointer "points at" a real weapon and attack() can use it.
void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon; // Store the address of the weapon '&' takes the object's address
}

// attack: prints "<name> attacks with their <weapon type>".
// The NULL check first: without it, an unarmed HumanB would dereference NULL and crash.
// If unarmed, we fall back to a different message instead of crashing the program.
void HumanB::attack(void) const
{
	if (_weapon == NULL) // Check whether the human has been armed yet
	{
		std::cout << _name << " attacks with their ... bare hands" << std::endl;
		return; // Do not touch _weapon below, it points to nothing
	}
	// '->' dereferences the pointer to call getType on the pointed-to weapon object.
	// Like HumanA, the CURRENT type is read, so a late setType still shows up here.
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
