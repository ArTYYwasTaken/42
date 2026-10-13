/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by student           #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FIXED-POINT NUMBERS, 8 FRACTIONAL BITS
**   raw = round(real * 2^8)   <=>   real = raw / 2^8
** The int stores the real value scaled by 256; the 8 lowest bits are the
** fractional part (the smallest step is 1/256 = 0.00390625).
*/

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream> /* std::ostream, needed for the << overload below     */
# include <cmath>    /* roundf, allowed by the subject for this exercise  */

class Fixed
{
	private:
		/* The real number scaled by 2^8 (8 lowest bits = fraction). */
		int					_fixedPointValue;

		/* Class-wide constant shared by all instances. A static const int
		** of integral type must be initialized here, in place. */
		static const int	_fractBits = 8;

	public:
		/* ---------------- Orthodox Canonical Form ---------------- */

		/* Default constructor: value = 0.0 */
		Fixed(void);

		/* Copy constructor: new object built as an exact copy */
		Fixed(const Fixed &other);

		/* Copy assignment operator: contents of an existing object replaced,
		** returns *this so `a = b = c` chains correctly. */
		Fixed	&operator=(const Fixed &other);

		/* Destructor: frees nothing here, but is part of OCF. */
		~Fixed(void);

		/* --------------- NEW: converting constructors ---------------
		** A one-argument constructor doubles as an implicit conversion
		** function from its parameter type to the class type. That is
		** why in the subject's ex01 main, `a = Fixed(1234.4321f)` first
		** prints "Float constructor called" then "Copy assignment...".
		*/

		/* From constant int: no true fraction exists, so the raw value is
		** simply the integer shifted 8 bits left (i.e. * 256). */
		Fixed(const int value);

		/* From constant float: multiply by 256, then ROUND to the nearest
		** representable step (roundf is the only <cmath> function allowed).
		** Rounding is why 42.42f becomes 42.421875 exactly, not 42.42. */
		Fixed(const float value);

		/* --------------- NEW: back-conversion functions --------------- */

		/* Fraction back to a float: just divide the raw value by 2^8. */
		float	toFloat(void) const;

		/* Round toward zero: drop the 8 fractional bits. */
		int		toInt(void) const;

		/* Raw accessors kept from ex00. */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		/* ------------- NEW: stream insertion operator -------------
		** `std::cout << a` works because operator<< is overloaded:
		**   - it cannot be a member function of Fixed (the LEFT operand is
		**     the std::ostream, not a Fixed), so it is a free function;
		**   - it takes the stream by reference and returns the SAME stream
		**     by reference, which is what allows chaining:
		**     `cout << a << b << c` == ((cout << a) << b) << c;
		**   - the Fixed operand is `const&`: read-only, no copy.
		*/
};

/* Declared as a free (non-member) function, OUTSIDE the class. */
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif /* FIXED_HPP */
