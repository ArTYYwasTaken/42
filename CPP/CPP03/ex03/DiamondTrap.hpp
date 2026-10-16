/* ========================================================================== */
/*                                                                            */
/*   DiamondTrap.hpp  -- Header of the DiamondTrap class (Exercise 03)        */
/*                                                                            */
/*   THE TRICK of this exercise: DiamondTrap inherits from FragTrap AND       */
/*   ScavTrap, which both inherit from ClapTrap. Without virtual              */
/*   inheritance there would be TWO ClapTrap parts inside a DiamondTrap       */
/*   (one through each parent) -> ambiguity and double construction.          */
/*   Because FragTrap and ScavTrap inherit VIRTUALLY from ClapTrap, a         */
/*   DiamondTrap contains exactly ONE shared ClapTrap part.                   */
/*                                                                            */
/* ========================================================================== */

/* Include guards: prevent the file from being read twice by the compiler.    */
#ifndef DIAMONDTRAP_HPP /* If DIAMONDTRAP_HPP is not defined yet...           */
# define DIAMONDTRAP_HPP /* ...define the macro and continue parsing.          */

/* DiamondTrap uses both parents, so both parents' headers are required       */
/* (each one already includes ClapTrap.hpp themselves).                        */
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
/* std::string is needed for the attack() signature and the _name attribute.  */
#include <string>

/* MULTIPLE inheritance: the declaration lists TWO base classes, separated    */
/* by a comma. Construction order follows the declaration order (virtual      */
/* bases first, then FragTrap, then ScavTrap).                                */
class DiamondTrap : public FragTrap, public ScavTrap
{
	/* PRIVATE section: DiamondTrap owns ONE extra attribute: its own name.   */
	/* The subject requires this attribute to have EXACTLY the same variable  */
	/* name as ClapTrap's (_name): it therefore SHADOWS (hides) the inherited  */
	/* one. This is why the subject mentions the -Wshadow / -Wno-shadow       */
	/* compiler flags: they let you see/hear about such shadowing.            */
	private:
		/* DiamondTrap's own name (the "diamond" personality name).          */
		std::string			_name;

	/* PUBLIC interface of DiamondTrap.                                        */
	public:
		/* --- Orthodox Canonical Form (mandatory four) ------------------ */
		/* Default constructor.                                              */
		DiamondTrap();
		/* Copy constructor.                                                 */
		DiamondTrap(const DiamondTrap &other);
		/* Copy assignment operator.                                         */
		DiamondTrap		&operator=(const DiamondTrap &other);
		/* Destructor.                                                       */
		~DiamondTrap();

		/* --- Subject-mandated member functions ------------------------- */
		/* Name constructor: builds a DiamondTrap named <name>.               */
		DiamondTrap(const std::string &name);
		/* attack(): comes "from ScavTrap" per the subject. Both parents     */
		/* override attack(), so DiamondTrap re-declares it and ROUTES the   */
		/* call to ScavTrap::attack to avoid the name ambiguity.              */
		void				attack(const std::string &target);
		/* whoAmI(): DiamondTrap's own special ability: prints both names.    */
		void				whoAmI();
};

#endif /* DIAMONDTRAP_HPP -- closes the include-guard block.                  */
