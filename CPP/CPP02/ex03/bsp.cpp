/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp   (Binary Space Partitioning point-in-triangle test)        */
/*   By: student <student@student.42.fr>                                      */
/*   Created: 2026/10/11 00:00:00 by student                                  */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
** ======================= point_InTriangle helper (STATIC) ==================
** Signature note: the subject forces `bool bsp(Point const a, ...)` -
** points passed BY VALUE. To avoid useless recomputation every call, our
** internal helpers take references; the public bsp() copies nothing less
** than the subject demands, and the helpers work on the copies directly.
**
** --------------------------------------------------------------------------
** THEORY: same-side test with the 2D CROSS PRODUCT
** --------------------------------------------------------------------------
** The 2D cross product of two vectors u = (ux, uy) and v = (vx, vy) is:
**
**     cross(u, v) = ux * vy - uy * vx
**
** Its SIGN tells you on which side of u the vector v lies
** (counter-clockwise positive / clockwise negative / zero = collinear).
**
** So: walking the triangle's outline a -> b -> c -> back to a, the point
** P is INSIDE the triangle only if it is on the SAME side of all three
** directed edges ab, bc, ca. Strictly inside (the subject wants vertices
** and edges to return "false") = not just same side, but NEVER zero:
** zero means collinear, i.e. ON the edge (or ON a vertex).
**
** Why choose cross products instead of "area fractions" (barycentric
** coordinates)? Both give exactly the same answer, but the cross product
** needs no division: it is multiplication-only, so no rounding headaches
** with our 8-bit fixed-point grid, and fewer operations.
** ========================================================================== */

/*
** File-local helper (static linkage, never exposed in any header).
** Everything stays in EXACT integer arithmetic: raw values are integers
** scaled by 256, so the raw cross product is the real cross product
** times 65536=2^16 - a constant positive factor that never changes the
** SIGN, which is all we care about.
*/
static int	crossSignRaw(int ax, int ay, int bx, int by, int px, int py)
{
	/* 64-bit intermediate: (bx-ax) and (by-ay) may each be large, and
	** their product may exceed int range for big fixed coordinates.
	** raw values are "integers scaled by 256", so the RAW cross product
	** is the REAL cross product scaled by 256*256 = 65536 - a positive
	** constant scale factor, which never changes a SIGN. */
	long long	cross = (long long)(bx - ax) * (py - ay)
					  - (long long)(by - ay) * (px - ax);
	if (cross > 0)
	{
		return (1);
	}
	if (cross < 0)
	{
		return (-1);
	}
	return (0);
}

/*
** ============================ THE PUBLIC FUNCTION ==========================
** Called exactly like the subject says:   bsp(a, b, c, point)
** Parameters are copies (subject-imposed signature) of immutable Points.
** ========================================================================== */
bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	/* Convert each vertex's raw coordinates ONCE (Fixed -> int, 8 bits
	** of fraction). From here on it is pure, exact integer math. */
	int	ax = a.getX().getRawBits();
	int	ay = a.getY().getRawBits();
	int	bx = b.getX().getRawBits();
	int	by = b.getY().getRawBits();
	int	cx = c.getX().getRawBits();
	int	cy = c.getY().getRawBits();
	int	px = point.getX().getRawBits();
	int	py = point.getY().getRawBits();

	/* Sign of cross(AB, AP): on which side of edge (a->b) is P? */
	int	s1 = crossSignRaw(ax, ay, bx, by, px, py);
	/* Edge (b->c): ...and where relative to edge (b->c)? */
	int	s2 = crossSignRaw(bx, by, cx, cy, px, py);
	/* Edge (c->a): ...and the last edge closes the loop. */
	int	s3 = crossSignRaw(cx, cy, ax, ay, px, py);

	/*
	** INSIDE STRICTLY == all three edges see P on their same side
	** (all +1 = CCW inside, or all -1 = CW inside, depending on the
	** vertex order). Any 0 means P is ON an edge (or vertex) -> false.
	** Mixed non-zero signs mean P is on different sides -> outside.
	*/
	if (s1 == 0 || s2 == 0 || s3 == 0)
	{
		return (false); /* On an edge or on a vertex: NOT strictly inside */
	}
	if ((s1 > 0 && s2 > 0 && s3 > 0) || (s1 < 0 && s2 < 0 && s3 < 0))
	{
		return (true);
	}
	return (false);
}
