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

#include "Weapon.hpp" // Need Weapon to create the clubs
#include "HumanA.hpp" // Need HumanA for the always-armed test case
#include "HumanB.hpp" // Need HumanB for the possibly-unarmed test case

// This main is exactly the code from the subject:
// executing it must print an attack with "crude spiked club" followed by a second attack
// with "some other type of club" for BOTH test cases (A and B).
int main(void)
{
	{ // Scope 1: everything here dies at the closing brace
		Weapon club = Weapon("crude spiked club"); // The weapon the human will hold
		HumanA bob("Bob", club);                   // HumanA takes the weapon in its constructor
		bob.attack();                              // Prints: Bob attacks with their crude spiked club
		club.setType("some other type of club");   // Change the weapon's type AFTER bob was built
		bob.attack();                              // Must print the NEW type: this proves HumanA
		                                           // holds a reference that still sees the original
	} // club and bob are destroyed here in reverse order of creation (bob first, then club)

	{ // Scope 2: second test case
		Weapon club = Weapon("crude spiked club"); // A fresh weapon for this scope
		HumanB jim("Jim");                         // HumanB is created UNARMED (no weapon yet)
		jim.setWeapon(club);                       // He gets armed later, via setWeapon
		jim.attack();                              // Prints: Jim attacks with their crude spiked club
		club.setType("some other type of club");   // Change the type again after arming him
		jim.attack();                              // Must print the NEW type, same reason as HumanA
	} // club and jim are destroyed here

	return (0); // Tell the OS the program ended successfully
}
