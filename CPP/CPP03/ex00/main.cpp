/* ========================================================================== */
/*                                                                            */
/*   main.cpp  -- Test program for Exercise 00 (ClapTrap)                     */
/*                                                                            */
/*   This program creates ClapTrap objects and calls every member function    */
/*   to prove the behavior required by the subject. Read the output: the      */
/*   constructor/destructor messages let you follow the object lifetimes.     */
/*                                                                            */
/* ========================================================================== */

/* Our own class header: brings the ClapTrap declaration into this file.      */
#include "ClapTrap.hpp"
/* iostream for std::cout (printing) and std::endl (end of line + flush).     */
#include <iostream>

/* main() is where a C++ program starts executing.                            */
int	main(void)
{
	/* --- Test 1: construction with a name --------------------------------- */
	/* This line creates the object "hero" on the STACK: the constructor      */
	/* runs here, and the destructor will run automatically at the closing    */
	/* brace of main (this is called RAII: no manual memory management!).     */
	ClapTrap	hero("HERO");

	/* --- Test 2: a normal attack ------------------------------------------ */
	/* HERO attacks a target named "training bot": costs 1 energy, prints     */
	/* the subject's message format with 0 points of damage (default value).  */
	hero.attack("training bot");

	/* --- Test 3: taking damage -------------------------------------------- */
	/* HERO loses 3 hit points: 10 - 3 = 7 remaining.                         */
	hero.takeDamage(3);

	/* --- Test 4: repairing ------------------------------------------------ */
	/* Repair for 2: costs 1 energy, 7 + 2 = 9 hit points.                    */
	hero.beRepaired(2);

	/* --- Test 5: attacking until energy runs out -------------------------- */
	/* HERO has 10 - 2 = 8 energy points left; we loop 8 times to spend them  */
	/* all, then one extra attack should be REFUSED (no energy message).      */
	/* "for (int i = 0; i < 9; i++)" repeats the block 9 times (i = 0..8).    */
	for (int i = 0; i < 9; i++)
	{
		hero.attack("training bot");
	} /* End of the loop body. */

	/* --- Test 6: copy constructor ----------------------------------------- */
	/* "clone" is built as an exact copy of "hero": watch the copy-ctor       */
	/* message and observe that both objects live independently afterwards.   */
	ClapTrap	clone(hero);

	/* The clone attacks on its own (still no energy, it inherited HEROs).    */
	clone.attack("training bot");

	/* --- Test 7: copy assignment operator --------------------------------- */
	/* "victim" is first created normally...                                  */
	ClapTrap	victim("VICTIM");
	/* ...then REPLACED by an assignment from "hero". Watch the operator=     */
	/* message: this is the copy assignment, not the copy constructor.        */
	victim = hero;

	/* --- Test 8: a dead robot does nothing -------------------------------- */
	/* 4 damage is more than the robot can survive if applied after damage;   */
	/* we apply enough damage to reach 0 hit points...                        */
	victim.takeDamage(1000);
	/* ...then both attack AND repair must be refused (0 HP messages).        */
	victim.attack("training bot");
	victim.beRepaired(5);

	/* --- End of main ------------------------------------------------------ */
	return (0);
	/* Returning 0 tells the operating system the program ended correctly.   */
	/* After this line, destructors run automatically (watch the output!).   */
} /* Scope of main closes here: hero, clone and victim are destroyed now.     */
