/* ========================================================================== */
/*                                                                            */
/*   ScavTrap.hpp  -- Header of the ScavTrap class (Exercise 01)               */
/*                                                                            */
/*   ScavTrap is a DERIVED class: it INHERITS from ClapTrap. This means       */
/*   it automatically gets all of ClapTrap's attributes and functions,        */
/*   then adds/changes what makes ScavTrap special. This is the heart of      */
/*   OOP inheritance: write once, reuse everywhere.                           */
/*                                                                            */
/* ========================================================================== */

/* Include guards: avoid double inclusion, exactly like in ClapTrap.hpp.      */
#ifndef SCAVTRAP_HPP /* If this macro is not defined yet...                  */
# define SCAVTRAP_HPP /* ...define it and continue reading the file.         */

/* We MUST include ClapTrap.hpp here: ScavTrap derives from ClapTrap, so the  */
/* compiler needs the full ClapTrap declaration to understand "public         */
/* ClapTrap" below. Headers must be self-sufficient (subject requirement).    */
#include "ClapTrap.hpp"
/* std::string is used in the attack() signature (inherited from ClapTrap     */
/* but redeclared/overridden here).                                           */
#include <string>

/* "class ScavTrap : public ClapTrap" reads as:                               */
/*   "ScavTrap IS-A ClapTrap, and everyone may use it as a ClapTrap".         */
/*   public inheritance keeps all public members public in the child.         */
class ScavTrap : public ClapTrap
{
	/* Nothing private here: ScavTrap reuses ClapTrap's attributes thanks    */
	/* to the PROTECTED _setStats() helper found in the ClapTrap base class. */

	/* PUBLIC interface of ScavTrap.                                          */
	public:
		/* --- Orthodox Canonical Form (4 special member functions) ------- */
		/* Default constructor: creates a ScavTrap with default name.       */
		ScavTrap();
		/* Copy constructor: builds a new ScavTrap copied from another.     */
		ScavTrap(const ScavTrap &other);
		/* Copy assignment operator: copies an existing ScavTrap's state    */
		/* into an already-built ScavTrap. Returns *this for chaining.      */
		ScavTrap			&operator=(const ScavTrap &other);
		/* Destructor: prints a message (subject wants visible lifetimes).  */
		~ScavTrap();

		/* --- Subject-mandated member functions ------------------------- */
		/* Name constructor: builds a ScavTrap named <name>.                 */
		ScavTrap(const std::string &name);
		/* attack(): has the SAME signature as ClapTrap::attack, so it       */
		/* OVERRIDES (replaces) the base version: calling attack() on a      */
		/* ScavTrap now runs THIS version, with ScavTrap's own message.      */
		void				attack(const std::string &target);
		/* guardGate(): ScavTrap's special ability, announced by the subject.*/
		void				guardGate();
};

#endif /* SCAVTRAP_HPP -- closes the include-guard block.                     */
