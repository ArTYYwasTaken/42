/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by student           #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

/*
** Reproduces the code from the subject so we can compare our output with
** the expected trace.
**
** Timeline of constructions/destructions here (stack objects are destroyed
** in REVERSE order of their declaration):
**   - a: default constructor
**   - b: copy constructor (copy of a)
**   - c: default constructor
**   - c = b: copy assignment operator
**   - 3x getRawBits (via the three cout lines)
**   - end of main: destructors of c, then b, then a (reverse declaration order)
*/
int	main(void)
{
	Fixed	a;        /* Default constructor called            */
	Fixed	b(a);     /* Copy constructor called               */
	Fixed	c;        /* Default constructor called            */

	c = b;            /* Copy assignment operator called       */

	/* Each call prints "getRawBits member function called" first,
	** then the value (0 for all three). */
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
	/* Destructor called (c) / Destructor called (b) / Destructor called (a) */
}
