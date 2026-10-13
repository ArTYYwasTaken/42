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
** FIXED-POINT, 8 FRACTIONAL BITS ( eps = 1/256 = 0.00390625 )
**   real -> raw : raw = round(real * 256)
**   raw -> real : real = raw / 256
** ex02 turns the class into a real numeric type: comparisons, the four
** arithmetic operations and ++/-- by the smallest representable step.
*/

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream> /* operator<< below and traces in the .cpp            */
# include <cmath>    /* roundf, again the only authorized <cmath> function */

class Fixed
{
	private:
		/* Real value scaled by 2^8. All operators below work directly on
		** this integer: ADD/SUB are done raw-to-raw (both operands share
		** the same scale, the fractions just carry/borrow correctly);
		** MUL and DIV rescale because their result would be off by 2^8. */
		int					_fixedPointValue;

		/* Same class constant as before, initialized in place. */
		static const int	_fractBits = 8;

	public:
		/* ---------------- Orthodox Canonical Form ---------------- */

		Fixed(void);
		Fixed(const Fixed &other);
		Fixed	&operator=(const Fixed &other);
		~Fixed(void);

		/* ---------------- Converting constructors ---------------- */

		Fixed(const int value);    /* raw = value << 8            */
		Fixed(const float value);  /* raw = roundf(value * 256)   */

		/* ------------------- Back conversions --------------------- */

		float	toFloat(void) const;
		int		toInt(void) const;

		/* --------------- NEW: comparison operators ---------------
		** Overloading `>` and friends gives our type the same natural
		** syntax `a > b` as built-in numbers. Returns plain bool, takes
		** const& operands: read-only, no copy made.
		** Implemented by comparing the RAW values (both share the same
		** scale 2^8, so integer comparison == real comparison; safer
		** and faster than going through toFloat).
		*/
		bool	operator>(const Fixed &rhs) const;
		bool	operator<(const Fixed &rhs) const;
		bool	operator>=(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;
		bool	operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;

		/* --------------- NEW: arithmetic operators ---------------
		** Each returns a NEW Fixed by value (never a reference: the
		** result is a freshly computed number, not one of the operands).
		** The right operand is const&; these are const member functions
		** because adding two numbers must not change either of them.
		*/
		Fixed	operator+(const Fixed &rhs) const;
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;

		/* --------- NEW: increment/decrement operators ---------
		** ++/-- move the value by the smallest representable step
		** eps = 1/256, i.e. exactly ONE unit of the raw int.
		**
		**   ++a (prefix):  increment, return the NEW   value, by ref
		**   a++ (postfix): increment, return the OLD   value, BY VALUE
		**     - the dummy `int` parameter is what tells C++ "this is the
		**       postfix version"; you never pass it, the compiler only
		**       uses it to choose the overload;
		**     - postfix can't return a reference to what no longer
		**       exists (the old value), hence the copy by value.
		*/
		Fixed	&operator++(void);      /* prefix  ++a */
		Fixed	operator++(int);        /* postfix a++ */
		Fixed	&operator--(void);      /* prefix  --a */
		Fixed	operator--(int);        /* postfix a-- */

		/* --------------- NEW: static min / max ---------------
		** STATIC member functions: they do not touch any individual
		** object (no `this`), so they are prefixed `Fixed::` instead of
		** being called on an instance.
		** Volatile-fixed-what? No: `volatile` is part of 42's usual
		** C++ min/max signature (copied from C++ standards history);
		** the subject only asks the two const/non-const pairs below.
		*/
		static Fixed		&min(Fixed &lhs, Fixed &rhs);
		static const Fixed	&min(const Fixed &lhs, const Fixed &rhs);
		static Fixed		&max(Fixed &lhs, Fixed &rhs);
		static const Fixed	&max(const Fixed &lhs, const Fixed &rhs);

		/* --------------- Raw access (kept since ex00) --------------- */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

/* operator<< from ex01: unchanged, still a free function. */
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif /* FIXED_HPP */
