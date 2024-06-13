#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name)
{
	this->_energyPoints = 10;
	this->_hitPoints = 10;
	this->_attackDamage = 0;
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

unsigned int ClapTrap::getDamage(void) const
{
	return this->_attackDamage;
}

std::string ClapTrap::getName(void) const
{
	return this->_name;
}

void    ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing ";
	std::cout << this->getDamage() << " points of damage" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitPoints += amount;
}