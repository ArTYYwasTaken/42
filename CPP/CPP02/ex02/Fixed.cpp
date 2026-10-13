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
** ===========================================================================
**   EVERY OPERATOR EXPLAINED: the comparisons and ADD/SUB are exact
**   integer work on the raw values (both operands share the 2^8 scale);
**   MUL and DIV need a rescale because their natural result is scaled
**   by 2^16 or 2^0; ++/-- move exactly one raw unit = one eps = 1/256.
** ===========================================================================
*/

/* ------------------------------- CTORS etc ------------------------------ */

Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/* Shift left by 8: keep the integer, append an (empty) fractional part. */
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractBits;
}

/* Round to nearest representable step: value * 256 -> nearest raw int. */
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

/* ------------------------------- BACK CONVERSIONS ----------------------- */

float	Fixed::toFloat(void) const
{
	return ((float)_fixedPointValue / (float)(1 << _fractBits));
}

int		Fixed::toInt(void) const
{
	return (_fixedPointValue >> _fractBits);
}

/* --------------------------- RAW ACCESS (ex00) -------------------------- */

int		Fixed::getRawBits(void) const
{
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

/*
** ========================== COMPARISON OPERATORS =========================
** Since both operands are fixed-point numbers with the SAME scale (8
** fractional bits), comparing their raw ints is exactly comparing the
** real values they represent...
**
**      a < b   <=>   a._raw < b._raw        (+/- the sign bit: for negative
**                                            values the two's-complement
**                                            int order is conserved)
**
** Six operators, all const (comparisons never modify their operands) and
** all returning bool. I write them in terms of each other where natural:
**   >= is !( < ),  <= is !( > ),  == is !( != )  ...  etc.
** This prevents the six functions from ever disagreeing with each other.
*/
bool	Fixed::operator>(const Fixed &rhs) const
{
	return (_fixedPointValue > rhs._fixedPointValue);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (_fixedPointValue < rhs._fixedPointValue);
}

/* A >= B when it is NOT true that A < B. */
bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (!(*this < rhs));
}

/* A <= B when it is NOT true that A > B. */
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

/*
** ========================== ARITHMETIC OPERATORS =========================
** All four returns BY VALUE: a brand-new Fixed (constructed inside the
** function, copied out by return value optimization - fine, the copy
** constructor is part of OCF and cheap).
*/

/*
** ADDITION (and subtraction, symmetrical):
** Both operands share the SAME scale, so simply adding their raw values
** gives a correctly scaled result. Example, eps = 1/256:
**    1.5  -> raw 384 ;  2.25 -> raw 576 ;  384 + 576 = 960 = 3.75. OK.
** No rescale needed. The returned Fixed provokes exactly ONE
** "Float/Int constructor + copy constructor + destructor" sequence when
** chained in an expression like `Fixed(5.05f) * Fixed(2)` in main.
*/
Fixed	Fixed::operator+(const Fixed &rhs) const
{
	/* Build the raw sum directly; a default Fixed is raw 0, so we could
	** also write `Fixed result; result = *this + rhs;` - same result,
	** but the version below avoids the extra default-construct step. */
	Fixed	result;

	/* No copy constructor trace needed, we return by value. */
	result._fixedPointValue = _fixedPointValue + rhs._fixedPointValue;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	Fixed	result;

	result._fixedPointValue = _fixedPointValue - rhs._fixedPointValue;
	return (result);
}

/*
** MULTIPLICATION:
** Multiplying two raw values multiplies the scales too.
**    (a / 256) * (b / 256)  ==  (a*b) / 65536  ==  (a*b / 256) / 256.
** The product `a*b` is over-scaled by 2^8, so we shift it back 8 bits
** right to restore the fixed-point scale. Shifting drops the low bits:
** to keep the precision we round instead, so we promote to a 64-bit
** intermediate, multiply, add half the divisor, and shift.
** (The 64-bit intermediate protects against overflow of a*b on huge
** values; the rounding bonus is standard fixed-point practice.)
*/
Fixed	Fixed::operator*(const Fixed &rhs) const
{
	/* Promote to long long BEFORE multiplying to avoid int overflow. */
	long long	product = (long long)_fixedPointValue
						* (long long)rhs._fixedPointValue;

	/* product is scaled by 2^16. Shift right to scale 2^8, rounding to
	** nearest by adding half of the divisor before the shift (only for
	** positive products; negative ones round the same way when the
	** divisor is added BEFORE the shift in arithmetic shift land - we
	** do the simplest correct-enough version: add half eps for positive,
	** subtract half eps for negative, so the rounding is symmetric). */
	if (product >= 0)
	{
		product += (1 << (_fractBits - 1)); /*  +128: round to nearest  */
	}
	else
	{
		product -= (1 << (_fractBits - 1)); /*  -128 for negatives      */
	}
	/* Arithmetic shift: divides by 2^8, back to the fixed-point scale.
** The quotient `raw_A * raw_B` is scaled 2^16, so >> 8 restores 2^8:
** the value obtained IS the raw field of the result, no further scaling
** (going through the int constructor would shift 8 more bits - a bug I
** had on first write: Fixed(int) re-multiplies by 256 by design). */
	Fixed	result;

	result._fixedPointValue = (int)(product >> _fractBits);
	return (result);
}

/*
** DIVISION:
** a / b in real space is (a_raw / 256) / (b_raw / 256), i.e. it produces
** a value whose raw scale is NEUTRAL (2^0). To land back on a 2^8 scale
** we pre-multiply the numerator by 256 (skip the promotion because
** `num * 256 * 256` would overflow int on big values: use long long).
** Division by zero is stated by the subject as "acceptable that the
** program crashes", so we do not guard it - the CPU will fault.
*/
Fixed	Fixed::operator/(const Fixed &rhs) const
{	/*              a_raw * 256       a_raw
** (a/256)/(b/256) = ----------- = a_raw ---   (x256)  =  (a_raw << 8) / b_raw
**                 b_raw / 256     2^8  b_raw
** The integer division may truncate the last bits: acceptable at 1/256
** precision. The quotient is ALREADY the raw field of the result. */
	long long	numerator = (long long)_fixedPointValue << _fractBits;

	Fixed	result;

	result._fixedPointValue = (int)(numerator / rhs._fixedPointValue);
	return (result);
}

/*
** ===================== INCREMENT / DECREMENT OPERATORS ===================
** "increase the value by the smallest representable eps, such that
**  1 + eps > 1":  here eps = 1/256, i.e. exactly ONE raw unit. So ++ is
** a +1 on the raw int, and -- is a -1.
*/

/* PREFIX: ++a. Performs the increment, RETURNS THE NEW VALUE, by
** reference (returning `*this` avoids a useless copy and matches the
** built-in behaviour, where ++i is an lvalue). */
Fixed	&Fixed::operator++(void)
{
	_fixedPointValue += 1;
	return (*this);
}

/* POSTFIX: a++. The dummy `int` argument distinguishes the signature.
** Sequence: SAVE the old value, THEN increment, return the OLD one,
** by value (it cannot be by reference: the saved copy is a local that
** dies at the end of this function). */
Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);   /* copy constructor: remembers the previous state */

	_fixedPointValue += 1;  /* then modify the object */
	return (old);           /* and return the pre-increment copy */
}

/* PREFIX: --a. Identical to prefix ++ with a -1 step. */
Fixed	&Fixed::operator--(void)
{
	_fixedPointValue -= 1;
	return (*this);
}

/* POSTFIX: a--. Save-then-decrement-then-return-old, by value. */
Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);

	_fixedPointValue -= 1;
	return (old);
}

/*
** ============================ STATIC MIN/MAX =============================
** `static` in the declaration means the function is not bound to one
** object. The two `min` overloads coexist happily because their
** parameter lists differ (const-ness is part of the overload set).
** Returning `Fixed&` (not a copy) matters: an expression like
** `Fixed::min(a, b) = something` keeps its meaning, exactly like with
** std::min/std::max from the STL we cannot use yet.
*/
Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	/* operator< is reused: if lhs < rhs, lhs IS the minimum. */
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

/* ---------------------------- operator<< -------------------------------- */

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
