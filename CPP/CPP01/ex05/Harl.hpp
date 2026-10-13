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

#include <string> // std::string is used for the level parameter and the messages

// Harl: the famous complainer. Each complaint level has its own dedicated function.
// The interesting part of this exercise: complain() must CALL the right function without
// a forest of if/else if/else, by using POINTERS TO MEMBER FUNCTIONS instead.
class Harl
{
private:                       // Everything below is only accessible inside the class itself
	// The four private complaint functions required by the subject, one per level:
	void debug(void);          // Level "DEBUG": contextual information for problem diagnosis
	void info(void);           // Level "INFO": extensive, trace-friendly information
	void warning(void);        // Level "WARNING": potential issue, can be handled or ignored
	void error(void);          // Level "ERROR": unrecoverable, needs manual intervention

public:                        // Everything below is accessible from outside the class
	Harl();                    // Default constructor: kept for class completeness
	~Harl();                   // Destructor: nothing to clean up, kept for canonical form
	void complain(std::string level); // Dispatches to the right function for the given level
};

#endif // HARL_HPP // Include guard end: marks the end of the guarded region
