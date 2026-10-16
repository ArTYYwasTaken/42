/* ========================================================================== */
/*                                                                            */
/*   ClapTrap.cpp  -- Implementation (the actual code) of ClapTrap (ex00)     */
/*                                                                            */
/*   Every member function declared in ClapTrap.hpp gets its real body here.  */
/*   Note the "ClapTrap::" prefix: it tells the compiler that the function     */
/*   belongs to the ClapTrap class.                                           */
/*                                                                            */
/* ========================================================================== */

/* We include ClapTrap.hpp so the compiler knows the class declaration.       */
/* We include <iostream> for std::cout (printing to the standard output).     */
#include "ClapTrap.hpp"
#include <iostream> /* std::cout, std::endl                                  */

/* ------------------------- Default constructor --------------------------- */
/* Syntax "ClapTrap::ClapTrap() : ..." uses an INITIALIZATION LIST: the       */
/* attributes are initialized directly with values, instead of assigned       */
/* later. This is the idiomatic (and often faster) C++ way.                   */
ClapTrap::ClapTrap() : _name("unnamed"), _hitPoints(10), _energyPoints(10),
	_attackDamage(0)
{
	/* The subject asks constructors to print a message so evaluators can    */
	/* trace object creation. std::endl ends the line AND flushes the        */
	/* output buffer. Every displayed message ends with a newline (subject). */
	std::cout << "ClapTrap default constructor called for <unnamed>" \
<< std::endl;
}

/* ---------------------- Parameterized constructor ------------------------ */
/* Takes the name from the caller. The other 3 stats keep their required      */
/* default values: 10 hit points, 10 energy points, 0 attack damage.          */
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	/* Print which name is being constructed so the trace is easy to read.   */
	std::cout << "ClapTrap constructor called for " << this->_name << std::endl;
}

/* --------------------------- Copy constructor ---------------------------- */
/* Builds a brand new object that copies an existing one. We use the          */
/* initialization list to copy each attribute from "other" one by one.        */
/* This is better than copying everything in the body because attributes      */
/* are constructed directly with their copied values.                         */
ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name),
	_hitPoints(other._hitPoints), _energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage)
{
	/* Message proves to evaluators that the copy constructor was used.      */
	std::cout << "ClapTrap copy constructor called for " << this->_name \
<< std::endl;
}

/* ----------------------- Copy assignment operator ------------------------ */
/* Handles "a = b;" when BOTH a and b already exist. The copy constructor      */
/* would handle "ClapTrap a = b;" (creation), this one handles assignment.    */
/* Returning "ClapTrap &" and "*this" allows chained assignments a=b=c;.       */
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	/* Printing here shows evaluators the assignment really happened.        */
	std::cout << "ClapTrap copy assignment operator called for " \
<< other._name << std::endl;
	/* Self-assignment guard: if someone does a = a, copying onto itself     */
	/* is useless (and with std::string self-copy can be dangerous), so we   */
	/* return early if the two addresses are identical.                      */
	if (this != &other)
	{
		/* Copy each attribute from 'other' into ourselves.                  */
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	/* Return the object itself so the assignment can be chained.            */
	return (*this);
}

/* ------------------------------ Destructor ------------------------------- */
/* Called automatically when the object goes out of scope or is deleted.      */
/* No dynamic memory is allocated manually here (no "new"), so there is       */
/* nothing to free: std::string cleans its own memory automatically.          */
ClapTrap::~ClapTrap()
{
	/* Print the robot's name so the destruction chain is visible in tests.  */
	std::cout << "ClapTrap destructor called for " << this->_name << std::endl;
}

/* --------------------------- Protected setter ---------------------------- */
/* Lets derived classes (ScavTrap, FragTrap, DiamondTrap) change the stats    */
/* without the attributes becoming public. "ClapTrap::" prefix required       */
/* at the definition.                                                         */
void ClapTrap::_setStats(unsigned int hitPoints, unsigned int energyPoints,
	unsigned int attackDamage)
{
	/* Store the 3 values into the private attributes.                       */
	this->_hitPoints = hitPoints;
	this->_energyPoints = energyPoints;
	this->_attackDamage = attackDamage;
}

/* ------------------------- Protected stat getters ------------------------- */
/* Each getter just hands back the current value of one attribute. The        */
/* attributes are stored without their name usable directly by children,      */
/* but the children MUST know their own stats for attack() (e.g. how much    */
/* damage to print), so read access goes through these protected helpers.     */
/* "const" again: reading does not modify the object.                        */
unsigned int	ClapTrap::_getHitPoints() const
{
	/* Return the private hit-point counter to the caller (read-only).       */
	return this->_hitPoints;
}

unsigned int	ClapTrap::_getEnergyPoints() const
{
	/* Return the private energy-point counter to the caller (read-only).    */
	return this->_energyPoints;
}	unsigned int	ClapTrap::_getAttackDamage() const
{
	/* Return the private attack-damage value to the caller (read-only).     */
	return this->_attackDamage;
}

/* ----------------------- Protected energy spender ------------------------- */
/* Paying for an action = losing one energy point. Only children of the       */
/* ClapTrap family may call this, because paying is an INTERNAL mechanic;     */
/* outsiders just call attack() or beRepaired(), which pay on their own.      */
void	ClapTrap::_spendOneEnergyPoint()
{
	/* Subtract 1 from the private energy counter and store it back.         */
	this->_energyPoints -= 1;
}

/* --------------------------- attack() function --------------------------- */
/* Const-reference parameter (&target) avoids copying the string: passing     */
/* by const reference is the standard efficient way to receive objects.       */
void ClapTrap::attack(const std::string &target)
{
	/* A dead robot (0 hit points) cannot do anything at all.                */
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack: no hit " \
"points left!" << std::endl;
		/* "return;" quits the function immediately, skipping the rest.      */
		return ;
	}
	/* A robot with no energy left cannot attack either.                     */
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack: no energy " \
"points left!" << std::endl;
		return ;
	}
	/* Here the robot CAN attack. Each attack costs 1 energy point...        */
	this->_energyPoints -= 1;
	/* ...and prints the message format given in the subject.                */
	std::cout << "ClapTrap " << this->_name << " attacks " << target \
<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

/* ------------------------- takeDamage() function ------------------------- */
/* Reduces this robot's hit points by <amount>.                               */
void ClapTrap::takeDamage(unsigned int amount)
{
	/* If the subtraction would go below 0, we clamp it at 0, because        */
	/* unsigned int cannot store negative numbers (it would wrap around      */
	/* to a huge value instead, a classic C/C++ pitfall we must avoid).      */
	if (amount >= this->_hitPoints)
		this->_hitPoints = 0;
	/* Otherwise we simply subtract the damage from the current health.      */
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount \
<< " points of damage! Hit points now: " << this->_hitPoints << std::endl;
}

/* ------------------------- beRepaired() function ------------------------- */
/* Regains <amount> hit points. Repairing costs 1 energy point.               */
void ClapTrap::beRepaired(unsigned int amount)
{
	/* A destroyed robot cannot repair itself either.                        */
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name \
<< " cannot be repaired: no hit points left!" << std::endl;
		return ;
	}
	/* A robot out of energy has no power left to run its repair tools.      */
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name \
<< " cannot be repaired: no energy points left!" << std::endl;
		return ;
	}
	/* Spending 1 energy point for the repair action.                        */
	this->_energyPoints -= 1;
	/* The robot regains the given amount of hit points.                     */
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " is repaired and regains " \
<< amount << " hit points! Hit points now: " << this->_hitPoints << std::endl;
}

/* ------------------------------ getName() ------------------------------- */
/* "const" at the end of the signature promises the compiler (and readers)    */
/* that this function does NOT modify the object; it only reads.              */
const std::string &ClapTrap::getName() const
{
	/* Hand back a read-only view of the private name attribute.             */
	return (this->_name);
}
