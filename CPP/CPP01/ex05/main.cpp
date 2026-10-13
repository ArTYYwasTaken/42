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

#include "Harl.hpp" // Use the Harl class to make him complain

int main(void)
{
	Harl harl;            // One Harl instance is enough to test all four levels

	harl.complain("DEBUG");   // Must print the [ DEBUG ] block
	harl.complain("INFO");    // Must print the [ INFO ] block
	harl.complain("WARNING"); // Must print the [ WARNING ] block
	harl.complain("ERROR");   // Must print the [ ERROR ] block
	harl.complain("banana");  // Unknown level: must print the fallback message

	return (0); // Tell the OS the program ended successfully
}
