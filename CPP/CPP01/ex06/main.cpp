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

#include "Harl.hpp"   // Use the Harl class with its filter function
#include <iostream>   // std::cerr to report a wrong argument count

// The program takes exactly ONE parameter: the minimum log level to listen to.
// Its executable must be named harlFilter (see the Makefile's NAME variable).
int main(int argc, char **argv)
{
	// A missing (or extra) argument cannot be filtered: show how to use the program.
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <DEBUG|INFO|WARNING|ERROR>" << std::endl;
		return (1); // Non-zero exit code: the program could not do its job
	}

	Harl harl;          // One Harl instance to run the filter on

	harl.filter(argv[1]); // Print the requested level and every level above it

	return (0);          // Tell the OS the program ended successfully
}
