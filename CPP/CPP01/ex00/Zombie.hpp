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

#ifndef ZOMBIE_HPP // Include guard start: prevents double inclusion of this header (would cause a 0 grade)
#define ZOMBIE_HPP // Define a macro so a second #include is ignored

#include <string> // std::string is used for the zombie's name attribute

// Zombie class: represents one zombie with a name that can announce itself.
class Zombie
{
private:                     // Everything below is only accessible inside the class itself
	std::string _name;       // The zombie's name, stored as a private std::string attribute

public:                      // Everything below is accessible from outside the class
	Zombie();                // Default constructor: creates a zombie with no name yet
	Zombie(std::string name);           // Parametric constructor: creates a zombie already named
	~Zombie();                          // Destructor: called when the zombie dies (must print its name)
	void announce(void) const;          // Prints "<name>: BraiiiiiiinnnzzzZ..." on the standard output
	void setName(std::string name);     // Setter used after default construction to give the zombie its name
};

#endif // ZOMBIE_HPP // Include guard end: marks the end of the guarded region
