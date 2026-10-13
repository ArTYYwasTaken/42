/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by kelle             #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP // Include guard start: prevents double inclusion of this header
#define WEAPON_HPP // Define a macro so a second #include is ignored

#include <string> // std::string is used for the weapon's type attribute

// Weapon class: holds a type of weapon that humans can carry and attack with,
// and whose type can be changed later at runtime.
class Weapon
{
private:                    // Everything below is only accessible inside the class itself
	std::string _type;      // The weapon's type, e.g. "crude spiked club"

public:                     // Everything below is accessible from outside the class
	Weapon();               // Default constructor: creates a weapon with an empty type
	Weapon(const std::string &type);    // Parametric constructor: creates a weapon with a given type
	~Weapon();                          // Destructor: nothing to clean up, but kept for canonical form
	const std::string &getType(void) const; // Returns a CONSTANT REFERENCE to the type (read-only, no copy)
	void setType(const std::string &type);  // Overwrites the type with the new value passed in
};

#endif // WEAPON_HPP // Include guard end: marks the end of the guarded region
