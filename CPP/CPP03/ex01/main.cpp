/* ========================================================================== */
/*                                                                            */
/*   main.cpp  -- Test program for Exercise 01 (ScavTrap)                     */
/*                                                                            */
/*   Watch the output carefully: the construction/destruction CHAINING        */
/*   (ClapTrap built first, destroyed last) is the main point of this ex.     */
/*                                                                            */
/* ========================================================================== */

/* ScavTrap's header (which itself includes ClapTrap.hpp).                    */
#include "ScavTrap.hpp"
/* iostream for std::cout and std::endl.                                       */
#include <iostream>

/* Program entry point.                                                        */
int	main(void)
{
	/* --- Test 1: build a ClapTrap and a ScavTrap -------------------------- */
	/* Order matters here: "base" is a plain ClapTrap, "guard" is a           */
	/* ScavTrap whose constructor FIRST builds the ClapTrap base part.        */
	ClapTrap	base("BASE");
	ScavTrap	guard("GUARD");

	/* --- Test 2: compare the two attack() versions ------------------------ */
	/* base.attack() runs the CLAPTRAP version (weak robot, 0 damage).        */
	base.attack("training bot");
	/* guard.attack() runs the SCAVTRAP override (loud message, 20 damage).   */
	guard.attack("training bot");
	/* This proves OVERRIDING works: same call, two different behaviors.      */

	/* --- Test 3: ScavTrap's special ability ------------------------------- */
	/* Only ScavTrap has guardGate(); a ClapTrap could not call this.         */
	guard.guardGate();

	/* --- Test 4: inherited functions still work --------------------------- */
	/* takeDamage/beRepaired are INHERITED from ClapTrap: no code copied,     */
	/* yet ScavTrap gets them for free. This is why inheritance is great.     */
	guard.takeDamage(15);
	guard.beRepaired(5);

	/* --- Test 5: copy constructor and assignment -------------------------- */
	/* twin is created as a copy of guard (base part copied first!).          */
	ScavTrap	twin(guard);
	/* clone gets guard's state through assignment (base operator= chained).  */
	ScavTrap	clone = twin;
	clone = guard;
	/* The copy attacks too, to prove it holds its own state.                 */
	clone.attack("training bot");

	/* --- Test 6: energy exhaustion on the strong robot --------------------- */
	/* guard had a few energy points spent above; burn them all with a loop.  */
	/* 50 initial energy minus 3 attacks used before = 47 remaining (approx; */
	/* takeDamage/beRepaired consumed some too). Loop enough times so the     */
	/* LAST calls are refused: watch the "no energy" messages appear.         */
	for (int i = 0; i < 50; i++)
	{
		guard.attack("training bot");
	} /* End of energy-draining loop. */

	/* --- End of main: watch the DESTRUCTION order ------------------------- */
	return (0);
	/* Destruction runs in REVERSE construction order, i.e. base LAST:       */
	/* clone, twin, guard (ScavTrap part then ClapTrap part), then base.      */
	/* This reverse order is exactly what the subject asks you to show.       */
} /* All objects die here; read their destructor messages bottom-up.           */
