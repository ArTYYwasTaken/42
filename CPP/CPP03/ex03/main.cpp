/* ========================================================================== */
/*                                                                            */
/*   main.cpp  -- Test program for Exercise 03 (DiamondTrap)                  */
/*                                                                            */
/*   The output proves the three key requirements of the exercise:            */
/*   1. ONE AND ONLY ONE "ClapTrap constructor" line per DiamondTrap.          */
/*   2. destruction chain reversed: DiamondTrap, ScavTrap, FragTrap,           */
/*      then the SHARED ClapTrap destroyed last, exactly once.                */
/*   3. correct final stats: 100 HP (Frag), 50 EP (Scav), 30 AD (Frag).       */
/*                                                                            */
/* ========================================================================== */

/* All four robot headers are available; DiamondTrap includes the two parents */
/* (which include ClapTrap). Adding ClapTrap.hpp here would be redundant but   */
/* harmless; we include it anyway to show headers are independent.             */
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
/* Printing utilities.                                                         */
#include <iostream>

/* Program entry point.                                                        */
int	main(void)
{
	/* --- Test 1: ordinary diamonds ---------------------------------------- */
	/* Watch closely: exactly ONE "ClapTrap constructor called for" line      */
	/* appears for DIAMOND, followed by FragTrap's and ScavTrap's parts.      */
	DiamondTrap	diamond("DIAMOND");

	/* --- Test 2: who am I -------------------------------------------------- */
	/* Both names are printed: the diamond name and the "_clap_name" one.     */
	diamond.whoAmI();

	/* --- Test 3: inherited stats check ------------------------------------ */
	/* attack should say 30 points of damage (FragTrap value), the message    */
	/* should be ScavTrap's loud one, and it costs 1 energy point (Scav).     */
	diamond.attack("glass golem");

	/* --- Test 4: take damage and repair through the shared ancestor ------- */
	/* These come from ClapTrap; with virtual inheritance there is only one   */
	/* copy of this function in the object, so no ambiguity: it just works.   */
	diamond.takeDamage(20);
	diamond.beRepaired(10);

	/* --- Test 5: both special abilities from both parents ----------------- */
	/* guardGate() comes from ScavTrap and highFivesGuys() from FragTrap;     */
	/* each name resolves to a single function, so both compile and run.      */
	diamond.guardGate();
	diamond.highFivesGuys();

	/* --- Test 6: copy, like a true Orthodox Canonical Form citizen -------- */
	/* twin is BORN as a copy (one shared ClapTrap part, copied once!).        */
	DiamondTrap	twin(diamond);
	twin.whoAmI();

	/* clone takes diamond's state via assignment (all parts chained).        */
	DiamondTrap	clone = twin;
	clone = diamond;
	clone.whoAmI();
	clone.attack("glass golem");

	/* --- Test 7: default constructor path ---------------------------------- */
	/* nameless diamond: "unnamed" + the "_clap_name" suffix for the ancestor. */
	DiamondTrap	nameless;
	nameless.whoAmI();

	/* --- Test 8: the diamond is a fighter too: exhaust the 50 energy points */
	/* Let the loop empty all energy points so the last attacks get refused,  */
	/* proving that DiamondTrap shares ScavTrap's attack bookkeeping.         */
	for (int i = 0; i < 55; i++)
	{
		diamond.attack("glass golem");
	} /* Loop body ends; refusal messages show up at the tail of the output. */

	/* --- End of main; watch the destruction chain ------------------------- */
	return (0);
	/* For every DiamondTrap the destructor order is: DiamondTrap first,      */
	/* then ScavTrap (Scav + shared Clap formerly skipped), then FragTrap,     */
	/* then exactly ONE "ClapTrap destructor" line -- the shared ancestor.    */
} /* All stack objects die here automatically, in reverse construction order.  */
