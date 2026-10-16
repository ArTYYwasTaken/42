/* ========================================================================== */
/*                                                                            */
/*   DiamondTrap.cpp  -- Implementation of DiamondTrap (Exercise 03)          */
/*                                                                            */
/*   Construction order with virtual inheritance (read this twice!):          */
/*   1. The VIRTUAL BASE, ClapTrap, is built first, directly by the           */
/*      MOST-DERIVED class (DiamondTrap) -- the base-part calls written in    */
/*      ScavTrap's/FragTrap's own initialization lists are SKIPPED here.       */
/*   2. Then FragTrap is constructed (its ClapTrap call is skipped).          */
/*   3. Then ScavTrap is constructed (its ClapTrap call is skipped).          */
/*   4. Then DiamondTrap's own body runs and sets the final stats.            */
/*   Destruction is the exact reverse: DiamondTrap, ScavTrap, FragTrap,       */
/*   then the shared ClapTrap LAST. This is the "created once, only once".    */
/*                                                                            */
/* ========================================================================== */

/* The class this file implements.                                             */
#include "DiamondTrap.hpp"
/* Printing utilities (std::cout / std::endl).                                 */
#include <iostream>

/* ------------------------- Default constructor --------------------------- */
/* Initialization list: the virtual base ClapTrap is initialized FIRST        */
/* (order is enforced by C++ no matter how we write the list). We give it     */
/* "unnamed" + the "_clap_name" suffix, mirroring the subject's rule for      */
/* the named constructor; DiamondTrap's own _name is set in the body.         */
DiamondTrap::DiamondTrap() : ClapTrap("unnamed_clap_name"),
	FragTrap(), ScavTrap()
{
	/* FragTrap's body may have set stats for a FragTrap; ScavTrap's body    */
	/* after it may have set ScavTrap stats. The FINAL stats of DiamondTrap  */
	/* must be exactly: 100 hit points (Frag), 50 energy (Scav),            */
	/* 30 attack damage (Frag) -- per the subject's list -- so we fix them   */
	/* here, after the whole parent chain is done: our word is the last.     */
	_setStats(100, 50, 30);
	/* DiamondTrap did not receive a name: use the default one.              */
	this->_name = "unnamed";
	/* Construction trace message specific to DiamondTrap.                   */
	std::cout << "DiamondTrap default constructor called for " \
<< this->_name << std::endl;
}

/* ---------------------- Name parameterized constructor ------------------- */
/* The famous trick, step by step:                                            */
/*  - ClapTrap("NAME_clap_name"): the shared ancestor gets the parameter      */
/*    name + the "_clap_name" suffix exactly as the subject demands.          */
/*    Because ClapTrap is a VIRTUAL base, this call is made ONLY once and     */
/*    ONLY by DiamondTrap: the parents' own ClapTrap(...) calls are ignored.  */
/*  - FragTrap(name) / ScavTrap(name): their bodies still run (printing       */
/*    their messages and setting THEIR default stats), but the named-ctor     */
/*    part of them that would touch ClapTrap is skipped.                      */
/*  - The join order must match the declaration order: virtual base,          */
/*    FragTrap, ScavTrap (otherwise -Wreorder would fail under -Werror).      */
DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap( \
name + "_clap_name"),
	FragTrap(name), ScavTrap(name)
{
	/* First, fix the final stats for a DiamondTrap:                         */
	/*  - hit points come from FragTrap    -> 100                            */
	/*  - energy points come from ScavTrap -> 50                             */
	/*  - attack damage comes from FragTrap -> 30                            */
	_setStats(100, 50, 30);
	/* Store the robot's public personality name (our OWN _name attribute,   */
	/* not the ClapTrap one -- the ClapTrap one holds the "_clap_name"       */
	/* version and is reachable only through getName()).                     */
	this->_name = name;
	/* DiamondTrap's construction message.                                    */
	std::cout << "DiamondTrap constructor called, I am " \
<< this->_name << std::endl;
}

/* --------------------------- Copy constructor ---------------------------- */
/* Copying must follow the same chain: the virtual base is copied by           */
/* DiamondTrap itself (that copy is done exactly once), and each parent       */
/* copy constructor still runs to copy the parts they are responsible of.     */
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other),
	FragTrap(other), ScavTrap(other)
{
	/* Copy DiamondTrap's own attribute: the personality name.                */
	this->_name = other._name;
	/* Copy-ctor trace message.                                               */
	std::cout << "DiamondTrap copy constructor called for " \
<< this->_name << std::endl;
}

/* ----------------------- Copy assignment operator ------------------------ */
/* For assignments we chain the operator= of every part of the object:        */
/* the shared ClapTrap part, then both parents, then our own attribute.       */
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	/* Copy the SHARED base part exactly once (keep it explicit so the       */
	/* "everything must be assigned" rule is visible and self-evident).      */
	ClapTrap::operator=(other);
	/* Then let each parent copy its own responsibilities...                  */
	FragTrap::operator=(other);
	ScavTrap::operator=(other);
	/* NOTE: those two each call ClapTrap::operator= again internally.        */
	/* That is harmless here (it re-copies the SAME already-correct values),  */
	/* and it keeps each class simple; the printed trace simply shows the     */
	/* shared base being touched more than once during a full copy.          */
	/* Finally copy DiamondTrap's own _name attribute...                      */
	this->_name = other._name;
	/* ...print the trace message...                                          */
	std::cout << "DiamondTrap copy assignment operator called for " \
<< other._name << std::endl;
	/* ...and return ourselves so "a = b = c;" keeps working.                 */
	return (*this);
}

/* ------------------------------ Destructor ------------------------------- */
/* Destructor order is the REVERSE of construction: DiamondTrap first,        */
/* parents after, SHARED ClapTrap last (only one ClapTrap destructor call!).  */
DiamondTrap::~DiamondTrap()
{
	/* Destruction trace message.                                             */
	std::cout << "DiamondTrap destructor called for " << this->_name \
<< std::endl;
}

/* --------------------------- attack() function --------------------------- */
/* Both parents define attack(), so an unscoped call would be ambiguous.      */
/* The subject says DiamondTrap attacks like a ScavTrap, so we route the      */
/* request to ScavTrap::attack: no code duplicated, no ambiguity.             */
void DiamondTrap::attack(const std::string &target)
{
	/* Explicit scope resolution "::" selects ScavTrap's implementation.      */
	ScavTrap::attack(target);
}

/* --------------------------- whoAmI() ability ---------------------------- */
/* Prints BOTH names: the DiamondTrap personality name and the ClapTrap name  */
/* (the one with the "_clap_name" suffix, stored inside the shared ancestor). */
void DiamondTrap::whoAmI()
{
	/* Inside this class, the plain "_name" refers to DiamondTrap's OWN       */
	/* private attribute (the child's declaration SHADOWS the inherited one). */
	/* The ClapTrap-level name is fetched with the public getName() getter,   */
	/* since ClapTrap's _name is private and only accessible through it.      */
	std::cout << "DiamondTrap " << this->_name \
<< " says: I am " << this->_name \
<< ", and my ClapTrap name is " << this->getName() << "!" << std::endl;
}
