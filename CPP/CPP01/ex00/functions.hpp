/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by kelle             #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Note: this header exists because the subject REQUIRES newZombie() and randomChump()
// to live in their own .cpp files, so main.cpp needs a place to learn their prototypes.

#ifndef FUNCTIONS_HPP // Include guard start: prevents double inclusion
#define FUNCTIONS_HPP // Define a macro so a second #include is ignored

#include <string> // std::string is used in both function prototypes
#include "Zombie.hpp" // Zombie is the return type of newZombie, so the full class is needed

// newZombie: creates a zombie on the HEAP and returns a pointer to it (see newZombie.cpp).
Zombie *newZombie(std::string name);

// randomChump: creates a zombie on the STACK, announces it, and destroys it (see randomChump.cpp).
void randomChump(std::string name);

#endif // FUNCTIONS_HPP // Include guard end
