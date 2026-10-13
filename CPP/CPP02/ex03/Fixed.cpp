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

/* ----------------------------- CONSTRUCTORS ----------------------------- */

Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = (int)roundf(value * (1 << _fractBits));
}

Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_fixedPointValue = other._fixedPointValue;
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/* ---------------------------- CONVERSIONS ------------------------------- */

float	Fixed::toFloat(void) const
{
	return ((float)_fixedPointValue / (float)(1 << _fractBits));
}

int		Fixed::toInt(void) const
{
	return (_fixedPointValue >> _fractBits);
}

int		Fixed::getRawBits(void) const
{
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

/* ----------------------- COMPARISON OPERATORS ----------------------------
** Raw ints share the same scale, so the integer order IS the real order.
*/

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (_fixedPointValue > rhs._fixedPointValue);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (_fixedPointValue < rhs._fixedPointValue);
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (!(*this < rhs));
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (!(*this > rhs));
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (_fixedPointValue == rhs._fixedPointValue);
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (!(*this == rhs));
}

/* ----------------------- ARITHMETIC OPERATORS ----------------------------
** + and -: raw-to-raw is already correctly scaled (both 2^8).
** * and /: rescale, see the detailed comments in ex02/Fixed.cpp.
*/

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	Fixed	result;

	result._fixedPointValue = _fixedPointValue + rhs._fixedPointValue;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	Fixed	result;

	result._fixedPointValue = _fixedPointValue - rhs._fixedPointValue;
	return (result);
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	/* (a/b) * (c/d) in real space == over-scaled product in raw space. */
	long long	product = (long long)_fixedPointValue
						* (long long)rhs._fixedPointValue;

	/* Restore scale 2^8, rounding to nearest (symmetric for negatives).
** The result's raw field IS the shifted product: building a Fixed via
** its int constructor would shift 8 bits AGAIN - wrong by x256. */
	if (product >= 0)
	{
		product += (1 << (_fractBits - 1));
	}
	else
	{
		product -= (1 << (_fractBits - 1));
	}
	Fixed	result;

	result._fixedPointValue = (int)(product >> _fractBits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	/* Pre-multiply numerator by 2^8 to land on a 2^8-scale quotient;
** the quotient already IS the raw field (see ex02 for the algebra). */
	long long	numerator = (long long)_fixedPointValue << _fractBits;

	Fixed	result;

	result._fixedPointValue = (int)(numerator / rhs._fixedPointValue);
	return (result);
}

/* ------------------- INCREMENT / DECREMENT (one eps=1/256) --------------- */

Fixed	&Fixed::operator++(void)
{
	_fixedPointValue += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);

	_fixedPointValue += 1;
	return (old);
}

Fixed	&Fixed::operator--(void)
{
	_fixedPointValue -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);

	_fixedPointValue -= 1;
	return (old);
}

/* --------------------------- STATIC MIN / MAX ---------------------------- */

Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
	{
		return (lhs);
	}
	return (rhs);
}

const Fixed	&Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs < rhs)
	{
		return (lhs);
	}
	return (rhs);
}

Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
	{
		return (lhs);
	}
	return (rhs);
}

const Fixed	&Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs > rhs)
	{
		return (lhs);
	}
	return (rhs);
}

/* ------------------------------ operator<< ------------------------------ */

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
