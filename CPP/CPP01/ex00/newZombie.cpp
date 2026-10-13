/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by kelle             #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" // Need the Zombie class definition to create a Zombie object

// newZombie: creates a zombie ON THE HEAP (with new) so it survives after this function returns.
// The heap (free store) is the right choice here because the object must outlive the function's scope:
// the caller receives the pointer and can keep using the zombie anywhere in the program.
// The price to pay: the caller is responsible for calling 'delete' on it, or it leaks.
Zombie *newZombie(std::string name)
{
	Zombie *z = new Zombie(name); // 'new' allocates memory on the heap AND calls the constructor
	return (z);                   // Return the pointer so the zombie can be used outside this scope
}
