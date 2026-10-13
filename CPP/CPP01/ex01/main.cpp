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

#include "Zombie.hpp"     // Use the Zombie class in the horde test
#include "functions.hpp" // Learn the prototype of zombieHorde()

int main(void)
{
	int N = 5;                        // Number of zombies we want in the horde

	Zombie *horde = zombieHorde(N, "Chump"); // One allocation holding all N zombies

	// Make every zombie in the horde announce itself, one after another.
	for (int i = 0; i < N; i++)
	{
		horde[i].announce();          // '.' works directly because horde[i] is a real Zombie object
	}

	// Mandatory: free the whole horde with delete[] (the brackets call every destructor of the array).
	// Forgetting the brackets would leak memory and only destroy the first zombie.
	delete[] horde;
	return (0);                      // Tell the OS the program ended successfully
}
