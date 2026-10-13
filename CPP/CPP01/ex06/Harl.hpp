/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelle <kelle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by kelle             #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by kelle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP // Include guard start: prevents double inclusion of this header
#define HARL_HPP // Define a macro so a second #include is ignored

#include <string> // std::string is used for the level parameters and the messages

// Harl: same complainer as ex05, upgraded with a FILTER system.
// complain() prints one level (as before); filter() prints the requested level
// AND every level above it, so you can ignore the noise below your chosen threshold.
class Harl
{
private:                       // Everything below is only accessible inside the class itself
	// The four private complaint functions, one per level (same as ex05):
	void debug(void);          // Level 0 "DEBUG": contextual information for problem diagnosis
	void info(void);           // Level 1 "INFO": extensive, trace-friendly information
	void warning(void);        // Level 2 "WARNING": potential issue, can be handled or ignored
	void error(void);          // Level 3 "ERROR": unrecoverable, needs manual intervention

public:                        // Everything below is accessible from outside the class
	Harl();                    // Default constructor: kept for class completeness
	~Harl();                   // Destructor: nothing to clean up, kept for canonical form
	void complain(std::string level); // Dispatches ONE complaint for the given level
	void filter(std::string level);   // Prints the level AND every level above it
};

#endif // HARL_HPP // Include guard end: marks the end of the guarded region
