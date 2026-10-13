/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by student           #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
** ============================ DEFAULT CONSTRUCTOR ==========================
** x and y are `Fixed const`: they can never be ASSIGNED, only INITIALIZED.
** The ONLY place where a member can be initialized is the member
** initializer list after the colon. That is why every constructor of this
** class is a pure initializer-list constructor, and why the constructor
** body is empty (no code left to run).
**
** Fixed has a default constructor, so `x()` would happen implicitly; we
** write it anyway to show exactly where the 0 comes from.
** ========================================================================== */
Point::Point(void) : x(0), y(0)
{
	/* Empty: all members were initialized in the list above. */
}

/*
** ========================= FLOATS CONSTRUCTOR ==============================
** The two float parameters are converted on the fly by Fixed's float
** constructor (roundf(value * 256)); each conversion result initializes
** one of the const members in one shot.
** ========================================================================== */
Point::Point(const float a, const float b) : x(a), y(b)
{
}

/*
** ============================ COPY CONSTRUCTOR =============================
** Member-wise copy-CONSTRUCTION of x and y from the other point. This is
** initialization of const members - perfectly legal (execution order
** follows the DECLARATION order of the members, which is x then y).
** Called twice in main: triangles passed BY VALUE to bsp().
** ========================================================================== */
Point::Point(const Point &other) : x(other.x), y(other.y)
{
}

/*
** ========================= COPY ASSIGNMENT OPERATOR ========================
** Furniture required by the Orthodox Canonical Form, but there is a
** subtlety: x and y are CONST, so they cannot be written after
** construction. operator= cannot do anything but return *this.
**
** Why keep it at all?
**   - The subject demands all four OCF members;
**   - Without an explicit one, C++ would DELETE the implicit operator=
**     (a class with const members + no user operator= is non-assignable:
**     `Point p1, p2; p1 = p2;` would fail to compile), which would break
**     the "Orthodox Canonical Form" contract.
**
** Self-assignment check first, as everywhere: `p = p` just returns p.
** ========================================================================== */
Point	&Point::operator=(const Point &other)
{
	(void)other; /* The parameter is intentionally unused: const members
				 ** cannot be reassigned. The (void) cast silences
				 ** -Wunused-parameter under -Wextra -Werror. */
	return (*this);
}

/*
** ================================ DESTRUCTOR ===============================
** Nothing to release (no pointers, no resources): Fixed members destroy
** themselves automatically.
** ========================================================================== */
Point::~Point(void)
{
}

/*
** ================================= GETTERS =================================
** Return by value (a copy): cheap (an int), and it decouples the caller
** from the internal representation. Trailing const: works on const Points.
** ========================================================================== */
Fixed	Point::getX(void) const
{
	return (x);
}

Fixed	Point::getY(void) const
{
	return (y);
}
