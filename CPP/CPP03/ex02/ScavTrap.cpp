/* ========================================================================== */
/*                                                                            */
/*   ScavTrap.cpp  -- Implementation of ScavTrap (Exercise 01)                */
/*                                                                            */
/*   Key idea of this exercise: CONSTRUCTION CHAINING. When you create a      */
/*   ScavTrap, C++ first calls the ClapTrap (base) constructor, THEN the      */
/*   ScavTrap constructor body. Destruction happens in REVERSE order.         */
/*   This order is fixed by the language and visible in our printed trace.    */
/*                                                                            */
/* ========================================================================== */

/* ScavTrap's own declaration.                                                */
#include "ScavTrap.hpp"
/* std::cout / std::endl for all printed messages of this class.              */
#include <iostream>

/* ------------------------- Default constructor --------------------------- */
/* The initialization list starts with "ClapTrap()": this is the BASE          */
/* constructor. C++ runs it FIRST, before any line of this body executes.      */
/* ClapTrap is always built first because a ScavTrap "is a" ClapTrap: you      */
/* cannot build the special parts before the common parts exist.               */
ScavTrap::ScavTrap() : ClapTrap()
{
	/* After the base is built with ClapTrap's defaults, we overwrite the    */
	/* 3 stats with SCAVTRAP's values: 100 HP, 50 energy, 20 attack damage.  */
	/* _setStats is protected in ClapTrap: accessible here but not outside.  */
	_setStats(100, 50, 20);
	/* Print our own message; this proves the ScavTrap part got constructed. */
	std::cout << "ScavTrap default constructor called for <unnamed>" \
<< std::endl;
}

/* ---------------------- Name parameterized constructor ------------------- */
/* Call the base constructor WITH THE NAME so the ClapTrap part receives      */
/* it directly (see the ClapTrap constructor message printed before ours).    */
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	/* Then adjust the stats to ScavTrap's own required values.              */
	_setStats(100, 50, 20);
	/* ScavTrap's construction message (different wording than ClapTrap's,   */
	/* as the subject requires "different messages").                        */
	std::cout << "ScavTrap constructor called, I am " \
<< this->getName() << std::endl;
}

/* --------------------------- Copy constructor ---------------------------- */
/* Copying starts by copying the ClapTrap part (base copy constructor),       */
/* then continues with the ScavTrap-specific part.                            */
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	/* Print the message proving this derived copy constructor ran.          */
	std::cout << "ScavTrap copy constructor called for " \
<< this->getName() << std::endl;
}

/* ----------------------- Copy assignment operator ------------------------ */
/* First assigns the ClapTrap part (operator= of the base), then nothing      */
/* else is needed here because ScavTrap owns no shareable data of its own.    */
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	/* Explicitly call the BASE class operator= to copy hit/energy/etc.      */
	ClapTrap::operator=(other);
	/* Print the assignment message so evaluators can track assignments.     */
	std::cout << "ScavTrap copy assignment operator called for " \
<< other.getName() << std::endl;
	/* Return *this so "a = b = c;" chains keep working.                     */
	return (*this);
}

/* ------------------------------ Destructor ------------------------------- */
/* The ClapTrap destructor will automatically run AFTER this body:            */
/* destruction is the exact mirror image of construction.                     */
ScavTrap::~ScavTrap()
{
	/* Print a destruction message specific to ScavTrap.                     */
	std::cout << "ScavTrap destructor called for " << this->getName() \
<< std::endl;
}

/* --------------------------- attack() override --------------------------- */
/* Since this function exists in BOTH classes with the same signature,        */
/* this ScavTrap version SHADOWS (hides) ClapTrap::attack for ScavTrap        */
/* objects. The rules (energy cost, dead check) stay the same; only the       */
/* printed message changes.                                                   */
void ScavTrap::attack(const std::string &target)
{
	/* Dead robots still cannot fight, same rule as the base class.          */
	/* _hitPoints is PRIVATE in ClapTrap, so we read it through the           */
	/* PROTECTED getter inherited for exactly this purpose.                  */
	if (this->_getHitPoints() == 0)
	{
		std::cout << "ScavTrap " << this->getName() \
<< " cannot attack: no hit points left!" << std::endl;
		return ;
	}
	/* Same for running out of energy: no power means no attack.             */
	/* Energy is read through its protected getter too.                      */
	if (this->_getEnergyPoints() == 0)
	{
		std::cout << "ScavTrap " << this->getName() \
<< " cannot attack: no energy points left!" << std::endl;
		return ;
	}
	/* One successful attack costs exactly 1 energy point... but the energy  */
	/* attribute is private, so changing it is ClapTrap's job: we call the   */
	/* protected _spendOneEnergyPoint() helper inherited from the base.      */
	this->_spendOneEnergyPoint();
	/* ScavTrap's own louder attack message (subject wants a different one). */
	std::cout << "ScavTrap " << this->getName() << " furiously attacks " \
<< target << ", causing " << this->_getAttackDamage() \
<< " points of damage!" << std::endl;
}

/* --------------------------- guardGate() ability ------------------------- */
/* ScavTrap's special move: enters "Gate keeper mode".                        */
void ScavTrap::guardGate()
{
	/* Guard mode costs nothing, it just prints a status message.            */
	std::cout << "ScavTrap " << this->getName() \
<< " is now in Gate keeper mode!" << std::endl;
}
