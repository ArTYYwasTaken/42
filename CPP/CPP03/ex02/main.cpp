/* ========================================================================== */
/*                                                                            */
/*   main.cpp  -- Test program for Exercise 02 (FragTrap)                     */
/*                                                                            */
/*   Same style of tests as ex01 but for the FragTrap family member:          */
/*   chaining, overriding, special ability, copying, energy exhaustion.       */
/*                                                                            */
/* ========================================================================== */

/* Both robot headers are included so we can also check that ScavTrap and     */
/* FragTrap coexist in the same program.                                       */
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
/* Printing utilities.                                                         */
#include <iostream>

/* Program entry point.                                                        */
int	main(void)
{
	/* --- Test 1: a base, a Scav and a Frag side by side ------------------- */
	/* Each construction prints its chaining trace: ClapTrap part FIRST,      */
	/* then the derived part (ScavTrap or FragTrap). Read the output order.   */
	ClapTrap	base("BASE");
	ScavTrap	guard("GUARD");
	FragTrap	brawler("BRAWLER");

	/* --- Test 2: different attack damage values --------------------------- */
	/* ClapTrap: 0 damage, ScavTrap: 20, FragTrap: 30. Watch the numbers!     */
	base.attack("punching bag");
	guard.attack("punching bag");
	brawler.attack("punching bag");

	/* --- Test 3: FragTrap's special ability ------------------------------- */
	/* Only FragTrap has highFivesGuys(); call it to see its message.         */
	brawler.highFivesGuys();

	/* --- Test 4: inherited generic functions on FragTrap ------------------ */
	/* takeDamage and beRepaired continue to come FROM ClapTrap unchanged.    */
	brawler.takeDamage(25);
	brawler.beRepaired(10);

	/* --- Test 5: copy constructor then assignment ------------------------- */
	/* twin is born as a copy of brawler (ClapTrap part copied first again).  */
	FragTrap	twin(brawler);
	/* clone is assigned later: watch the two operator= messages.             */
	FragTrap	clone = twin;
	clone = brawler;
	/* The fresh copy acts by itself.                                         */
	clone.attack("punching bag");

	/* --- Test 6: 100 attacks to exhaust 100 energy points ----------------- */
	/* brawler has spent 3-4 energy points so far; a 100-round loop covers    */
	/* them all and shows the "cannot attack" refusals at the very end.       */
	for (int i = 0; i < 100; i++)
	{
		brawler.attack("punching bag");
	} /* Loop body ends; the refusals will appear in the printed output.     */

	/* --- End of main; destruction is REVERSED construction ---------------- */
	return (0);
	/* Watch the trace: clone and twin die BEFORE brawler; inside each one   */
	/* the FragTrap destructor prints first, then the ClapTrap one.           */
} /* Scope closes, all objects destructed automatically (no leaks possible).   */
