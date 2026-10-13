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
	/* Default constructor: prints "Default constructor called". */
	Fixed a;
	/* Int constructor: 10 stored as raw 10 << 8 = 2560 (10.0 exactly). */
	Fixed const b(10);
	/* Float constructor: 42.42f rounded to raw 10860 (42.421875 exactly). */
	Fixed const c(42.42f);
	/* Copy constructor of c (prints "Copy constructor called"). */
	Fixed const d(b);

	/* TEMPORARY object Fixed(1234.4321f) built by the float constructor,
	** its value copied into `a` by copy-assignment, then the temporary
	** destroyed. This is why the trace shows:
	**   Float constructor / Copy assignment / Destructor. */
	a = Fixed(1234.4321f);

	/* operator<< prints a.toFloat() = 1234.43 (print rounds to 2 digits
	** because the closest 1/256 step is 1234.43 COMMERCIAL value: raw is
	** 316014, i.e. 1234.4297 approx -> iostream prints "1234.43"). */
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	/* toInt drops the fractional part toward zero. */
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return (0);
	/* The 4 stack objects are destroyed in reverse order (c, b, a, d
	** declared last is "d", so trace is: d, c, b, a -> 4 Destructor lines). */
}
