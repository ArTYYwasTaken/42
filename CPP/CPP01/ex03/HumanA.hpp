/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by kelle             #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP // Include guard start: prevents double inclusion of this header
#define HUMANA_HPP // Define a macro so a second #include is ignored

#include <string>    // std::string for the human's name
#include "Weapon.hpp" // HumanA always HAS a weapon: it needs the full class definition

// HumanA: a human who is ALWAYS armed, because the Weapon is taken in its constructor.
// Note the KEY design choice below: the weapon is stored by REFERENCE, not by pointer.
// Why a reference? A reference cannot be null and cannot be re-seated, which matches the fact
// that HumanA always has exactly one weapon. Most importantly, a reference transparently
// sees any change made to the original weapon ( setType), which the test relies on:
// after club.setType("some other type of club"), bob's next attack MUST print the new type.
class HumanA
{
private:                      // Everything below is only accessible inside the class itself
	std::string _name;        // The human's name, printed in the attack message
	Weapon &_weapon;          // REFERENCE to the weapon. MUST be bound in the initializer list,
	                          // because a reference can never exist unbound in C++

public:                       // Everything below is accessible from outside the class
	HumanA(const std::string &name, Weapon &weapon); // Takes the weapon in its constructor (always armed)
	~HumanA();                // Destructor: nothing to clean up, kept for canonical form
	void attack(void) const;  // Prints "<name> attacks with their <weapon type>"
};

#endif // HUMANA_HPP // Include guard end: marks the end of the guarded region
