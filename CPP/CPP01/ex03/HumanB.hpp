/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by kelle             #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP // Include guard start: prevents double inclusion of this header
#define HUMANB_HPP // Define a macro so a second #include is ignored

#include <string>    // std::string for the human's name
#include "Weapon.hpp" // Needed because HumanB stores and calls members of Weapon

// HumanB: a human who MAY sometimes not have a weapon, because the weapon is NOT taken
// in its constructor: it can be given later thanks to setWeapon.
// Note the KEY design choice below: the weapon is stored by POINTER, not by reference.
// Why a pointer? A reference could never represent "no weapon" (it must be bound at birth
// and can never be null), while a pointer can be NULL until setWeapon is called.
class HumanB
{
private:                       // Everything below is only accessible inside the class itself
	std::string _name;         // The human's name, printed in the attack message
	Weapon *_weapon;           // POINTER to the weapon: starts as NULL ("unarmed") until setWeapon

public:                        // Everything below is accessible from outside the class
	HumanB(const std::string &name); // Does NOT take a weapon: this human can be unarmed
	~HumanB();                 // Destructor: nothing to clean up, kept for canonical form
	void setWeapon(Weapon &weapon); // Gives a weapon to the human (stores its address)
	void attack(void) const;   // Prints "<name> attacks with their <weapon type>" (or is unarmed)
};

#endif // HUMANB_HPP // Include guard end: marks the end of the guarded region
