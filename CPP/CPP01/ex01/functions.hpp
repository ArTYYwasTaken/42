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

// Note: this header exists because the subject REQUIRES zombieHorde() to live in
// its own zombieHorde.cpp file, so main.cpp needs a place to learn its prototype.

#ifndef FUNCTIONS_HPP // Include guard start: prevents double inclusion
#define FUNCTIONS_HPP // Define a macro so a second #include is ignored

#include <string>     // std::string is used in the function prototype
#include "Zombie.hpp" // Zombie is both the return type and the horde's content: full class needed

// zombieHorde: allocates N zombies in ONE allocation and returns a pointer to the first
// one (see zombieHorde.cpp). The caller must free it with delete[].
Zombie *zombieHorde(int N, std::string name);

#endif // FUNCTIONS_HPP // Include guard end
