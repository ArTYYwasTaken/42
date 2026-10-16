/* ========================================================================== */
/*                                                                            */
/*   ClapTrap.hpp  -- Header file of the ClapTrap class (Exercise 00)         */
/*                                                                            */
/*   A ClapTrap is a robot that can attack, take damage and repair itself.    */
/*   This header only DECLARES the class: it describes what attributes        */
/*   (data) and member functions (behavior) every ClapTrap will have.         */
/*   The real CODE of the functions lives in ClapTrap.cpp.                    */
/*                                                                            */
/* ========================================================================== */

/* Include guards: these 3 lines prevent the compiler from reading this file  */
/* twice in the same compilation unit (double inclusion), which would cause   */
/* "redefinition of class" errors. This is mandatory per the subject.         */
#ifndef CLAPTRAP_HPP /* If the macro CLAPTRAP_HPP is not yet defined...     */
# define CLAPTRAP_HPP /* ...then define it now, and read the file.           */

/* <string> is included because the class stores its name in a std::string.  */
/* Every header must include its own dependencies so it can be used alone.   */
#include <string> /* std::string type                                       */

/* The class declaration. Class names are written in UpperCamelCase.         */
class ClapTrap
{
	/* PRIVATE section: only the class's own member functions may touch      */
	/* these attributes. The subject explicitly requires PRIVATE attributes. */
	private:
		/* This is the robot's name, given by the user of the class.         */
		/* std::string is the C++ way to store text (never char* in C++).    */
		std::string			_name;
		/* Hit points = the robot's health. Initialized to 10 (see .cpp).    */
		/* "unsigned int" because a number of points can never be negative.  */
		unsigned int		_hitPoints;
		/* Energy points = fuel for actions. Initialized to 10 (see .cpp).   */
		unsigned int		_energyPoints;
		/* Attack damage = how much damage one attack causes. Starts at 0.   */
		unsigned int		_attackDamage;

	/* PROTECTED section: visible to this class AND to classes that derive   */
	/* from it (ScavTrap, FragTrap...). We put a "setter" here so derived    */
	/* classes can reconfigure the 3 stats used above WITHOUT breaking the   */
	/* "private attributes" rule asked by the subject.                       */
	protected:	/* Writes new values into the 3 private attributes of ClapTrap.          */
	/* Used by the derived classes to get their own stat values.             */
	void					_setStats(unsigned int hitPoints,
		unsigned int energyPoints, unsigned int attackDamage);
	/* Read-only access to the 3 stats for the DERIVED classes only.         */
	/* The attributes stay private, but a child class may ask the values:    */
	/* a protected getter is the polite way to share data inside a family    */
	/* of classes without opening it to the whole world (public lacks the    */
	/* control; direct friends are forbidden by the subject).               */
	unsigned int			_getHitPoints() const;
	unsigned int			_getEnergyPoints() const;
	unsigned int			_getAttackDamage() const;
	/* Removes exactly 1 energy point; used by every derived robot's own     */
	/* attack() (each attack costs 1 energy, per the subject).               */
	void					_spendOneEnergyPoint();

	/* PUBLIC section: the interface anyone outside the class may use.       */
	public:
		/* --- Orthodox Canonical Form (mandatory from Module 02 to 09) ---  */
		/* Default constructor: creates a ClapTrap with no name given.       */
		ClapTrap();
		/* Parameterized constructor: creates a ClapTrap with a given name.  */
		ClapTrap(const std::string &name);
		/* Copy constructor: creates a new ClapTrap as an exact copy of      */
		/* an existing one (needed for the Orthodox Canonical Form).         */
		ClapTrap(const ClapTrap &other);
		/* Copy assignment operator: replaces the content of an existing     */
		/* ClapTrap with the content of another one. Returns *this so that   */
		/* chains like a = b = c; work.                                      */
		ClapTrap			&operator=(const ClapTrap &other);
		/* Destructor: called automatically when the object dies; must       */
		/* print a message so evaluators can see the object was destroyed.   */
		~ClapTrap();

		/* --- The three subject-mandated actions ------------------------- */
		/* attack(): damages <target> using this->_attackDamage points and   */
		/* costs 1 energy point. Does nothing if no HP or no energy left.    */
		void				attack(const std::string &target);
		/* takeDamage(): removes <amount> hit points from this robot.        */
		void				takeDamage(unsigned int amount);
		/* beRepaired(): regains <amount> hit points; also costs 1 energy.   */
		void				beRepaired(unsigned int amount);

		/* --- Small public read-only helper ----------------------------- */
		/* getName(): returns the robot's name without allowing callers to   */
		/* MODIFY it (const reference = read-only access). DiamondTrap will  */
		/* need this in ex03 to print its "ClapTrap name".                   */
		const std::string	&getName() const;
};

#endif /* CLAPTRAP_HPP -- closes the include-guard block opened above.       */
