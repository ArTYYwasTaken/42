/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 00:00:00 by student           #+#    #+#             */
/*   Updated: 2026/10/11 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ============================ POINT =======================================
** A 2D point whose coordinates are Fixed numbers. The members are `const`:
** a point is immutable by design - you do not MOVE a point, you create
** another one. That const-ness has a big consequence for the constructors
** and for operator= (see Point.cpp):
**
**   - a const member CAN be initialized (in the ctor initializer list,
**     exactly once, at construction time);
**   - a const member CANNOT be reassigned later, not even inside
**     operator=. So the copy assignment operator is physically unable to
**     change this->x or this->y... but the compiler still demands that we
**     DECLARE one (Orthodox Canonical Form + C++ rule: the implicit
**     operator= would have been deleted, so we provide our own).
** ============================================================================ */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp" /* Point stores Fixed members, so this header MUST
						** include its own dependencies to be self-sufficient. */

class Point
{
	/* ------------------------------- PRIVATE ------------------------------
	** x and y: the two coordinates. `Fixed const` = once constructed, they
	** can only be read back (through the public getters below).
	** ---------------------------------------------------------------------- */
	private:
		Fixed const	x;
		Fixed const	y;

	public:
		/* --------------- Orthodox Canonical Form --------------- */

		/* Default constructor: x and y initialized to 0.
		** The initializer list is MANDATORY here: const members cannot be
		** assigned in the constructor body. */
		Point(void);

		/* Floats constructor: builds the point (a, b). Again, initializer
		** list only - Fixed has no "set after construction" interface that
		** a const member could use. */
		Point(const float a, const float b);

		/* Copy constructor: member-wise initialization, works naturally
		** with const members since it INITIALIZES them. */
		Point(const Point &other);

		/* Copy assignment: see the explanation in Point.cpp. It cannot
		** write x/y; it still returns *this and guards self-assignment. */
		Point	&operator=(const Point &other);

		/* Destructor. */
		~Point(void);

		/* ---------------- Useful extras (allowed by the subject) -------- */

		/* Getters: return copies of the coordinates. Trailing const, they
		** never modify the point. */
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

/*
** BSP - Binary Space Partitioning, point-in-triangle test.
** Declared in this header so every user of Point can find it; DEFINED in
** bsp.cpp (a function implementation may never live in a header file,
** except for templates - subject's general rules).
**
**     a, b, c: the three vertices of the triangle,
**     point:   the point to test,
**     returns: true iff `point` is STRICTLY inside the triangle abc.
**              Vertices and edges return false (strict inclusion only).
*/
bool	bsp(const Point a, const Point b, const Point c, const Point point);

#endif /* POINT_HPP */
