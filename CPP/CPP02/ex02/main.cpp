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

int	main(void)
{
	/* a = 0.0 : default constructor. */
	Fixed a;

	/* Fixed(5.05f) * Fixed(2): float ctor (raw 1293 = 5.05078...),
	** int ctor (raw 512 = 2.0). Product: 1293 * 512 = 662016, scaled
	** 2^16. Rounded: +128 -> 662144, >> 8 = 2587 -> 2587/256 = 10.10156...
	** -> printed "10.1016". The temporary objects are destroyed right
	** after `b` is initialized (copy constructor of the result). */
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	/* postfix vs prefix below:
	**   ++a : increments THEN prints the new value
	**   a++ : prints the OLD value, still increments, but afterwards */
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	/* Static member function, called on the CLASS:
	** max(a, b) sees 0.0078125 (a, after a++) vs 10.1016 (b). */
	std::cout << Fixed::max( a, b ) << std::endl;

	return (0);
}
