/* ========================================================================== */
/*                                                                            */
/*   FragTrap.cpp  -- Implementation of FragTrap (Exercise 02)                */
/*                                                                            */
/*   Same construction-chaining story as ScavTrap, with different values      */
/*   and messages: the code structure is inherited-friendly, only the         */
/*   numbers and words change.                                                */
/*                                                                            */
/* ========================================================================== */

/* The class this file implements.                                            */
#include "FragTrap.hpp"
/* Printing utilities (std::cout / std::endl).                                 */
#include <iostream>

/* ------------------------- Default constructor --------------------------- */
/* Base first: ClapTrap() runs its own constructor before this body.          */
FragTrap::FragTrap() : ClapTrap()
{
	/* FragTrap's required starting stats: 100 HP, 100 energy, 30 damage.    */
	_setStats(100, 100, 30);
	/* FragTrap-specific construction trace message.                         */
	std::cout << "FragTrap default constructor called for <unnamed>" \
<< std::endl;
}

/* ---------------------- Name parameterized constructor ------------------- */
/* Send the name up to the ClapTrap constructor via the initialization list.   */
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	/* FragTrap's starting stats overwrite ClapTrap's default ones.          */
	_setStats(100, 100, 30);
	/* Own construction message (subject: different from the base's one).    */
	std::cout << "FragTrap constructor called, I am " \
<< this->getName() << std::endl;
}

/* --------------------------- Copy constructor ---------------------------- */
/* Copy the ClapTrap (base) part first, using the base copy constructor.       */
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	/* Message showing that the FragTrap copy part also executed.            */
	std::cout << "FragTrap copy constructor called for " \
<< this->getName() << std::endl;
}

/* ----------------------- Copy assignment operator ------------------------ */
/* Delegate the shared data to ClapTrap's operator= (the base handles everything). */
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	/* Call the base class assignment to copy name + the 3 stats.            */
	ClapTrap::operator=(other);
	/* FragTrap's assignment trace message.                                  */
	std::cout << "FragTrap copy assignment operator called for " \
<< other.getName() << std::endl;
	/* Return a reference to ourselves so assignments can be chained.        */
	return (*this);
}

/* ------------------------------ Destructor ------------------------------- */
/* Runs BEFORE the base destructor (destruction is reversed construction).    */
FragTrap::~FragTrap()
{
	/* Destruction trace message for FragTrap.                                */
	std::cout << "FragTrap destructor called for " << this->getName() \
<< std::endl;
}

/* --------------------------- attack() override --------------------------- */
/* Same signature as the base's attack(): this hides ClapTrap::attack for     */
/* FragTrap objects, exactly like ScavTrap::attack did for ScavTraps.         */
void FragTrap::attack(const std::string &target)
{
	/* No hit points = the robot is broken, it cannot fight.                 */
	/* Read the PRIVATE stats through the protected getters of the base.     */
	if (this->_getHitPoints() == 0)
	{
		std::cout << "FragTrap " << this->getName() \
<< " cannot attack: no hit points left!" << std::endl;
		return ;
	}
	/* No energy = no power to attack with.                                  */
	if (this->_getEnergyPoints() == 0)
	{
		std::cout << "FragTrap " << this->getName() \
<< " cannot attack: no energy points left!" << std::endl;
		return ;
	}
	/* Pay the mandatory 1 energy point through the protected helper.        */
	this->_spendOneEnergyPoint();
	/* FragTrap's energetic attack message.                                   */
	std::cout << "FragTrap " << this->getName() << " punches " << target \
<< ", causing " << this->_getAttackDamage() \
<< " points of damage!" << std::endl;
}

/* ------------------------- highFivesGuys() ability ----------------------- */
/* "void" parameter list = this function takes NO parameters (subject form).  */
void FragTrap::highFivesGuys(void)
{
	/* Print a positive high-fives request, as the subject asks.              */
	std::cout << "FragTrap " << this->getName() \
<< " requests a positive high five!" << std::endl;
}
