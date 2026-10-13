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
** ============================== FIXED-POINT ================================
** Integers store whole numbers with no fractional part. Floating-point
** numbers store a sign, an exponent and a mantissa, which gives them a huge
** range but a non-uniform precision. A FIXED-POINT number is a different
** compromise: we take a plain integer and we *decide by convention* that the
** lowest N bits of it represent the FRACTIONAL part, while everything above
** represents the INTEGER part.
**
** With 8 fractional bits, the raw value is the real number scaled by 2^8:
**
**     raw_value = round(real_value * 256)
**     real_value = raw_value / 256
**
** The smallest step we can represent is therefore 1/256 = 0.00390625, and
** it is UNIFORM across the whole range (that is what "fixed" means: the
** binary point does not move, unlike the floating point of a float/double).
** ============================================================================ */

#ifndef FIXED_HPP
# define FIXED_HPP

/*
** Include guards ("#ifndef ... #define ... #endif") avoid the problem of
** double inclusion: if this header is included twice in the same
** translation unit, the second time FIXED_HPP is already defined, so the
** whole content is skipped. Every header must be independently includable.
*/

# include <iostream> /* std::cout used in the constructor/destructor traces */

class Fixed
{
	/*
	** ------------------------------ PRIVATE ------------------------------
	** Everything below is inaccessible from outside the class: the raw
	** representation is an implementation detail that callers must never
	** touch directly, otherwise our abstraction is worthless.
	** ---------------------------------------------------------------------
	*/

	private:
		/* The fixed-point number itself: an int whose lowest 8 bits are
		** the fractional part. */
		int					_fixedPointValue;

		/* Number of fractional bits. STATIC: shared by every Fixed object
		** (it belongs to the class, not to one instance). CONST: it can
		** never change. It must be initialized IN PLACE, because a static
		** const int of integral type may only be initialized inside the
		** class definition (TIP from the C++ modules). */
		static const int	_fractBits = 8;

	/*
	** ------------------------------ PUBLIC -------------------------------
	** The interface of the class.
	** ---------------------------------------------------------------------
	*/

	public:
		/* ----------------- Orthodox Canonical Form -----------------
		** From Module 02 on, EVERY class must implement these four
		** member functions (unless stated otherwise):
		**   1. Default constructor         Fixed();
		**   2. Copy constructor            Fixed(const Fixed &src);
		**   3. Copy assignment operator    Fixed &operator=(const Fixed &rhs);
		**   4. Destructor                  ~Fixed();
		** ----------------------------------------------------------- */

		/* 1. Default constructor: value initialized to 0. */
		Fixed(void);

		/* 2. Copy constructor: build a NEW object as an exact copy of an
		** existing one. Takes a reference (no copy of the argument itself)
		** to const (we promise not to modify the source). */
		Fixed(const Fixed &other);

		/* 3. Copy assignment operator: replace the content of an EXISTING
		** object with the content of another one. Returns a reference to
		** *this so that assignments can be chained: a = b = c; */
		Fixed	&operator=(const Fixed &other);

		/* 4. Destructor: last function called on an object, right before
		** its memory is released. Use it to free anything the object owns. */
		~Fixed(void);

		/* --------------------- Raw bits accessors --------------------- */

		/* Returns the raw integer value. TRAILING CONST: the function
		** promises not to modify the object it is called on, which lets it
		** be called on const Fixed instances. */
		int		getRawBits(void) const;

		/* Overwrites the raw value with the given integer. Not const,
		** of course: it modifies the object. */
		void	setRawBits(int const raw);
};

#endif /* FIXED_HPP */
