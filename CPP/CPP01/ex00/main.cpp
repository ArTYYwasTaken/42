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

#include "Zombie.hpp"     // Use the Zombie class in both allocation cases
#include "functions.hpp" // Learn the prototypes of newZombie() and randomChump()

int main(void)
{
	Zombie *heapZombie;                         // Pointer that will hold a HEAP-allocated zombie

	heapZombie = newZombie("Foo");              // Heap: created with new, survives this whole main
	heapZombie->announce();                     // '->' arrows the pointer to call announce on the object

	randomChump("Bob");                         // Stack: created, announces, and is destroyed at once

	delete heapZombie;                          // Heap zombies MUST be deleted manually, or they leak
	return (0);                                 // Tell the OS the program ended successfully
}
