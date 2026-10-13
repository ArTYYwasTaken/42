/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by student           #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** ======================= THE SHIFTING-arithmetic TRICK ======================
** Raw value  <-> real value   (8 fractional bits):
**
**     real -> raw : raw = round(real * 256)
**     raw -> real : real = raw / 256
**
** Multiplying/dividing by 2^N is EXACTLY a left/right bit shift by N on
** integers, which is why fixed-point is fast: no floating unit involved
** while the number LIVES, only at the conversions in and out.
** ========================================================================== */

/* ------------------------------ DEFS ----------------------------------
** 1 << 8 is 256. We keep it written as a shift so the link with the
** number of fractional bits stays visually obvious.
** ---------------------------------------------------------------------- */

/*
** ============================ DEFAULT CTOR ==============================
** 0 in any representation is 0: raw value 0 = real value 0.0.
*/
Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*
** ============================ INT CONSTRUCTOR ===========================
** An int has no fractional part by definition, so:
**     raw = 42  =>  raw = 42 << 8  =  42 * 256  =  10752
** Real value stored: 10752 / 256 = 42.0 (exactly representable).
*/
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	/* Left shift: append 8 zero bits, i.e. multiply by 2^8. */
	_fixedPointValue = value << _fractBits;
}

/*
** =========================== FLOAT CONSTRUCTOR ==========================
** A float like 42.42f HAS a fractional part. First scale it up by 256
** (42.42 * 256 = 10859.52), then we must keep an INTEGER: we ROUND to the
** nearest one (10860 here), because that is the closest step our fixed
** value can represent (10860 / 256 = 42.421875).
**
** roundf is explicitly authorized by this exercise; plain (int) cast would
** TRUNCATE toward zero instead (10859 -> 42.4140625, worse approximation).
**
** The `static const int` _fractBits is usable here like any other int.
*/
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = (int)roundf(value * (1 << _fractBits));
}

/*
** =========================== COPY CONSTRUCTOR ===========================
** Same as ex00: initialize a brand new object from an existing one.
*/
Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

/*
** ======================= COPY ASSIGNMENT OPERATOR =======================
** Same three steps as ex00:
**   1. self-assignment guard,
**   2. copy members,
**   3. return *this for chaining.
*/
Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_fixedPointValue = other._fixedPointValue;
	}
	return (*this);
}

/*
** ============================== DESTRUCTOR ==============================
*/
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/*
** =============================== toFloat ================================
** Going from raw to real value: divide by 2^8. We cast to float FIRST so
** the division is a floating-point one (integer / integer would truncate).
** No rounding here: our raw value is already the nearest representable
** step, so we just translate it faithfully.
*/
float	Fixed::toFloat(void) const
{
	return ((float)_fixedPointValue / (float)(1 << _fractBits));
}

/*
** =============================== toInt ==================================
** Going from raw to the integer part: drop the 8 fractional bits. A right
** shift does it, rounding toward zero (like a plain (int) cast).
** Ex: 42.421875 == raw 10860 == 10860 >> 8 == 42.
*/
int		Fixed::toInt(void) const
{
	return (_fixedPointValue >> _fractBits);
}

/*
** =========================== getRawBits/setRawBits ======================
** Kept from ex00. Used by ex02 internally: with the arithmetic operators
** added later, the raw int becomes a genuine field users never touch.
*/
int		Fixed::getRawBits(void) const
{
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

/*
** ========================= operator<< OVERLOAD ==========================
** Called when you write `std::cout << a;`
**
** Why a FREE function and why these signature types:
**   - `std::ostream &out`: the left operand, taken by reference because a
**     stream cannot be copied;
**   - `const Fixed &fixed`: the right operand, const& to allow printing
**     const Fixed objects without copying them;
**   - returns `out` itself, so `cout << a << endl` chains.
**
** std::endl prints a newline AND flushes the output buffer. The subject
** asks for the float REPRESENTATION of the value (1 decimal digit is
** nowhere demanded, we print exactly what toFloat gives us).
*/
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
