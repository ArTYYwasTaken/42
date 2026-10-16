/* ========================================================================== */
/*                                                                            */
/*   FragTrap.hpp  -- Header of the FragTrap class (Exercise 02)              */
/*                                                                            */
/*   FragTrap is a SECOND child of ClapTrap, done exactly like ScavTrap      */
/*   in ex01 was: a different robot personality for the same base class.      */
/*   Comparing ex01 and ex02 shows why inheritance avoids code duplication.   */
/*                                                                            */
/* ========================================================================== */

/* Include guards: prevent double inclusion, same as every other header.      */
#ifndef FRAGTRAP_HPP /* If FRAGTRAP_HPP is not defined yet...                  */
# define FRAGTRAP_HPP /* ...define it and keep reading.                      */

/* FragTrap NEEDS ClapTrap.hpp: it inherits from ClapTrap, so the full        */
/* base class declaration must be known here (headers are self-sufficient).   */
#include "ClapTrap.hpp"
/* std::string for the attack() parameter type.                                */
#include <string>

/* Another public inheritance: FragTrap IS-A ClapTrap, just like ScavTrap.    */
class FragTrap : public ClapTrap
{
	/* No new attributes: FragTrap reuses ClapTrap's attributes and only      */
	/* changes their STARTING VALUES (100 HP, 100 energy, 30 damage).         */

	/* PUBLIC interface of FragTrap.                                          */
	public:
		/* --- Orthodox Canonical Form (mandatory four) ------------------ */
		/* Default constructor.                                             */
		FragTrap();
		/* Copy constructor.                                                 */
		FragTrap(const FragTrap &other);
		/* Copy assignment operator, returns *this to allow chaining.        */
		FragTrap			&operator=(const FragTrap &other);
		/* Destructor, prints a message to trace object lifetime.            */
		~FragTrap();

		/* --- Subject-mandated member functions ------------------------- */
		/* Name constructor called with the robot's name.                    */
		FragTrap(const std::string &name);
		/* attack(): overrides ClapTrap::attack with FragTrap's own message. */
		void				attack(const std::string &target);
		/* highFivesGuys(): FragTrap's special ability (asks for high fives).*/
		void				highFivesGuys(void);
};

#endif /* FRAGTRAP_HPP -- closes the include-guard block.                     */
