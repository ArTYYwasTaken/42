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
** FIXED, 8 FRACTIONAL BITS, full ex02 operator set.
** BSP needs a REAL numeric type: cross products of Fixed coordinates,
** and the comparison operators to decide "strictly left/right of a
** directed edge".
*/

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		/* Real value scaled by 2^8. */
		int					_fixedPointValue;
		static const int	_fractBits = 8;

	public:
		/* ---------------- Orthodox Canonical Form ---------------- */
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed	&operator=(const Fixed &other);
		~Fixed(void);

		/* Converting constructors (int / float, as ex01). */
		Fixed(const int value);
		Fixed(const float value);

		/* Back conversions. */
		float	toFloat(void) const;
		int		toInt(void) const;

		/* ------------ ex02: comparison operators -------------- */
		bool	operator>(const Fixed &rhs) const;
		bool	operator<(const Fixed &rhs) const;
		bool	operator>=(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;
		bool	operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;

		/* ------------- ex02: arithmetic operators ------------- */
		Fixed	operator+(const Fixed &rhs) const;
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;

		/* -------- ex02: increment / decrement (one eps) -------- */
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		/* --------------- ex02: static min / max ---------------- */
		static Fixed		&min(Fixed &lhs, Fixed &rhs);
		static const Fixed	&min(const Fixed &lhs, const Fixed &rhs);
		static Fixed		&max(Fixed &lhs, Fixed &rhs);
		static const Fixed	&max(const Fixed &lhs, const Fixed &rhs);

		/* Raw access: bsp.cpp works on raw ints inside evaluate(). */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif /* FIXED_HPP */
