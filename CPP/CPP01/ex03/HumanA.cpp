/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by kelle             #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp" // Include the class definition so the compiler knows the members
#include <iostream>   // std::cout and std::endl are used to print the attack message

// Constructor: the weapon reference MUST be initialized here, in the initializer list.
// In C++98 a reference member has no default state: it must be bound at construction.
HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

// Destructor: no dynamic allocation is owned by HumanA, so nothing to free here.
HumanA::~HumanA(void)
{
}

// attack: prints "<name> attacks with their <weapon type>".
// Reading _weapon.getType() follows the reference back to the ORIGINAL weapon object,
// so if the weapon's type was changed since, the CURRENT type is what gets printed.
void HumanA::attack(void) const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
