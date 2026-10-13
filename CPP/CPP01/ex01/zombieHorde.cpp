/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by kelle             #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" // Need the Zombie class definition to allocate a horde of them

// zombieHorde: allocates N zombies in ONE SINGLE allocation (new Zombie[N], not N separate news).
// It then initializes each of them with the name passed as a parameter, and returns a pointer
// to the FIRST zombie of the horde, so the caller can use and later delete the whole array.
Zombie *zombieHorde(int N, std::string name)
{
	// Guard: a non-positive count would make 'new Zombie[N]' meaningless (or even invalid),
	// so return NULL early to signal "there is no horde".
	if (N <= 0)
		return (NULL);

	// ONE SINGLE allocation for the whole horde: 'new Zombie[N]' default-constructs all N zombies
	// in one contiguous block of memory on the heap. The expression evaluates to a pointer to
	// the first element, which is exactly what the function must return.
	Zombie *horde = new Zombie[N];

	// Initialize each zombie individually: the subject requires every one of them to receive the name.
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name); // horde[i] IS a Zombie object, so '.' is used (no '->' needed)
	}

	// Return the pointer to the first zombie. The caller can announce them all (horde[i].announce())
	// and must free them with 'delete[]' (with the brackets!) so every destructor is called.
	return (horde);
}
