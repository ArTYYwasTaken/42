/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by kelle             #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP // Include guard start: prevents double inclusion of this header
#define ZOMBIE_HPP // Define a macro so a second #include is ignored

#include <string> // std::string is used for the zombie's name attribute

// Zombie class: represents one zombie with a name that can announce itself.
class Zombie
{
private:                     // Everything below is only accessible inside the class itself
	std::string _name;       // The zombie's name, stored as a private std::string attribute

public:                      // Everything below is accessible from outside the class
	Zombie();                            // Default constructor: creates an unnamed zombie
	~Zombie();                           // Destructor: called on death (must print the zombie's name)
	void announce(void) const;           // Prints "<name>: BraiiiiiiinnnzzzZ..." on the standard output
	void setName(std::string name);      // Setter used right after default construction to name the zombie
};

#endif // ZOMBIE_HPP // Include guard end: marks the end of the guarded region
