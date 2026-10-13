/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by kelle             #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp" // Need the Zombie class definition to create a Zombie object

// randomChump: creates a zombie ON THE STACK and makes it announce itself.
// The stack is the right choice here because the zombie is only needed INSIDE this function:
// it is destroyed automatically (and its destructor prints a message) when the function returns.
// No manual memory management needed: no leak is possible with stack allocation.
void randomChump(std::string name)
{
	Zombie z = Zombie(name); // 'z' is a stack variable: constructed here, destroyed at the end of the scope
	z.announce();            // Make the zombie introduce itself while it still exists
}                            // <-- end of scope: z's destructor is called here automatically
