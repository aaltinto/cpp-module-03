#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name)
{
	this->_energyPoints = 10;
	this->_hitPoints = 10;
	this->_attackDamage = 0;
	std::cout << "Constructor called for ClapTrap " << this->getName() << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& copy)
{
	std::cout << "Copy constructor called for ClapTrap "\
			<< this->getName()\
			<< std::endl;
	this->_name = copy.getName();
	this->_attackDamage = copy.getDamage();
	this->_energyPoints = copy.getEnergy();
	this->_hitPoints = copy.getHitPoints();
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for ClapTrap "\
			<< this->getName()\
			<< std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy)
{
	std::cout << "ClapTrap copy assignment operator called"\
			<< std::endl;
	this->_name = copy.getName();
	this->_hitPoints = copy.getHitPoints();
	this->_energyPoints = copy.getEnergy();
	this->_attackDamage = copy.getDamage();
	return *this;
}

unsigned int ClapTrap::getDamage(void) const
{
	return this->_attackDamage;
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

unsigned int ClapTrap::getEnergy(void) const
{
	return this->_energyPoints;
}

std::string ClapTrap::getName(void) const
{
	return this->_name;
}

void    ClapTrap::attack(const std::string &target)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " is dead. Can't attack" << std::endl;
		return;
	}
	if (this->getEnergy() <= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " has no energy left. Can't attack" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing ";
	std::cout << this->getDamage() << " points of damage" << std::endl;
	this->_energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " already dead" << std::endl;
		return ;
	}
	if (this->_hitPoints <= amount)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->getName() << " has taken " << amount << " points of damage\n"
			<< this->getName() << " has " << this->getHitPoints() << " hit points left" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " is dead. Can't be repaired" << std::endl;
		return;
	}
	if (this->getEnergy() <= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " has no energy left. Can't be repaired" << std::endl;
		return;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
}