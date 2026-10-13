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

/* The implementation file must include its own header first: that way, if
** the header has a missing dependency, WE are the first to notice it. */
#include "Fixed.hpp"

/*
** ========================= DEFAULT CONSTRUCTOR ==============================
** Called when an object is created with NO arguments:   Fixed a;
** Memory for the object is allocated BEFORE the constructor body runs;
** the constructor only Initializes it. Here we set the raw value to 0.
** We print a trace because the subject wants to *see* which constructor
** is called at each step of main().
** ========================================================================== */
Fixed::Fixed(void) : _fixedPointValue(0)
{
	/* The "member initializer list" (": _fixedPointValue(0)") initializes
	** the member directly, which is the idiomatic and more efficient way
	** (members of const type or of class type without default
	** constructors REQUIRE it). Assigning in the body would be
	** default-init-then-assign, two steps instead of one. */
	std::cout << "Default constructor called" << std::endl;
}

/*
** =========================== COPY CONSTRUCTOR ===============================
** Called when creating a new object FROM an existing one:
**     Fixed b(a);        // direct initialization
**     Fixed c = a;       // also the copy constructor (NOT operator=!)
**     void f(Fixed x);   // also called when passing by value
**     return aFixed;     // (usually) also when returning by value
** If we did not write one, the compiler would generate a shallow copy for
** us: fine while members are plain ints, wrong as soon as we own a
** pointer to allocated memory. Writing it explicitly is part of the
** Orthodox Canonical Form.
** ========================================================================== */
Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue)
{
	/* We read the PRIVATE member of `other` directly. That is legal:
	** access control applies to CLASSES, not to objects, and we are code
	** of the same class. */
	std::cout << "Copy constructor called" << std::endl;
}

/*
** ======================= COPY ASSIGNMENT OPERATOR ===========================
** Called when an ALREADY-EXISTING object receives another one's value:
**     c = b;
** Differences with the copy constructor: the target object already
** exists on the heap/stack, so we must (1) protect against self
** assignment (a = a) and (2) free any resource currently held before
** taking the new one. Here members are only ints, so a plain copy
** suffices, but the three-step discipline is always shown and expected
** during evaluations.
** ========================================================================== */
Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	/* Step 1 - Self-assignment guard: if the caller wrote `a = a`,
	** copying onto itself is both useless and potentially harmful
	** (imagine freeing the resource before copying it...). */
	if (this != &other)
	{
		/* Step 2 - Copy every member ("this" is a pointer to the object
		** the member function was called on; "*this" dereferences it). */
		_fixedPointValue = other._fixedPointValue;
	}
	/* Step 3 - Return *this by reference so assignment chains:
	** `a = b = c` works exactly like with built-in types. */
	return (*this);
}

/*
** ================================ DESTRUCTOR ================================
** Called automatically when the object goes out of scope, or when it is
** deleted (delete ptr). One constructor may build a resource, the
** destructor must guarantee its release. The compiler-generated default
** would exist, but the Orthodox Canonical Form wants it declared
** explicitly.
** ========================================================================== */
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/*
** ===== getRawBits: return the unscaled integer representation =====
** Trailing `const` = promise that the member function does not modify
** any member of the object; on a const object, ONLY const member
** functions may be called.
** ========================================================================== */
int	Fixed::getRawBits(void) const
{
	/* The subject's example output expects this trace too. */
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointValue);
}

/*
** ===== setRawBits: overwrite the unscaled integer representation =====
** Not const, it writes into the object. The parameter is `int const(raw)`
** as written in the subject: the const here qualifies the local copy of
** the int, so it changes nothing for the caller, it only forbids US from
** modifying `raw` inside the function body.
** ========================================================================== */
void	Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}
