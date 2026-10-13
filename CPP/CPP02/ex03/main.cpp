/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*   By: student <student@student.42.fr>                                      */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

/*
** Little display helper: a fixed-width table so the output is readable.
**   test(): prints "name ............ [value]" with the name in a 32-char
**   column. Passing the bool by value copies one machine word, trivial.
*/
static void	test(const char *name, bool result)
{
	std::cout << name;
	/* Pad the name column to 32 characters. */
	int	len = 0;
	while (name[len] != '\0')
	{
		len++;
	}
	for (int i = len; i < 32; i++)
	{
		std::cout << ' ';
	}
	std::cout << ": " << (result ? "true" : "false") << std::endl;
}

/*
** ================================ TEST PLAN ================================
** Triangle used everywhere:   A(0, 0)   B(10, 0)   C(0, 10)
** (a right triangle, easy to reason about - P(x, y) is inside iff
**  x > 0 AND y > 0 AND x + y < 10 ... and the bsp() call below must
**  agree with this hand-made rule on every single case.)
** ========================================================================== */
int	main(void)
{
	/* The triangle vertices, fixed-point numbers all the way down. */
	Point	a(0.0f, 0.0f);
	Point	b(10.0f, 0.0f);
	Point	c(0.0f, 10.0f);

	std::cout << "---- INSIDE (must all be true) ----" << std::endl;
	/* Center-ish point: well inside. */
	test("inside center (2,2)",
		bsp(a, b, c, Point(2.0f, 2.0f)));
	/* Near the hypotenuse x+y=10, but strictly below it (9.99 total). */
	test("inside near edge (3,6.99f)",
		bsp(a, b, c, Point(3.0f, 6.99f)));
	/* Fixed-point smallest representable step: 1/256 = 0.00390625.
	** This point is only ONE eps away from both edges - the hardest
	** class of strictly-inside points. */
	test("inside eps-close (0.00390625,0.00390625)",
		bsp(a, b, c, Point(0.00390625f, 0.00390625f)));

	std::cout << "---- OUTSIDE (must all be false) ----" << std::endl;
	/* Beyond the hypotenuse x + y > 10. */
	test("outside hypotenuse (6,6)",
		bsp(a, b, c, Point(6.0f, 6.0f)));
	/* Beyond the right edge x < 0 side. */
	test("outside left (-1,2)",
		bsp(a, b, c, Point(-1.0f, 2.0f)));
	/* Below the bottom edge y < 0. */
	test("outside bottom (2,-1)",
		bsp(a, b, c, Point(2.0f, -1.0f)));

	std::cout << "---- ON THE EDGES / VERTEX (strict: must be false) ----" << std::endl;
	/* Exactly ON the bottom edge (y = 0), between A and B. */
	test("on bottom edge (5,0)",
		bsp(a, b, c, Point(5.0f, 0.0f)));
	/* Exactly ON a vertex (B itself). */
	test("on vertex b",
		bsp(a, b, c, b));
	/* The intersection of edge ab's line and edge bc's line: vertex B. */
	test("vertex coordinates (10,0)",
		bsp(a, b, c, Point(10.0f, 0.0f)));

	std::cout << "---- DEGENERATE INPUTS ----" << std::endl;
	/* A degenerate triangle (all three vertices collinear): no interior
	** exists, every answer must be false - a good sanity check. */
	Point	d(0.0f, 0.0f);
	Point	e(5.0f, 5.0f);
	Point	f(10.0f, 10.0f);
	test("degenerate triangle, p inside-answer",
		bsp(d, e, f, Point(2.0f, 2.0f)));

	/* Windiness: running the test with the SAME triangle but declared
	** clockwise must change nothing (the test is side-based, not
	** orientation-based). Same triangle as before, listed CW. */
	std::cout << "---- ANTI-CLOCKWISE VERTICES ----" << std::endl;
	test("same triangle, CW order (2,2)",
		bsp(c, b, a, Point(2.0f, 2.0f)));

	return (0);
}
