#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->_attackDamage = 20;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    std::cout << "Constructor called for ScavTrap " << this->getName() << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& copy): ClapTrap(copy)
{
    std::cout << "Copy constructor called for ScavTrap " << this->getName() << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor called for ScavTrap " << this->getName() << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->getName() << " in gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->getHitPoints() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " has no hit points left" << std::endl;
		return;
	}
	if (this->getEnergy() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " has no energy left" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing ";
	std::cout << this->getDamage() << " points of damage" << std::endl;
	this->_energyPoints -= 1;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " already dead" << std::endl;
		return ;
	}
	if (this->_hitPoints <= amount)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ScavTrap " << this->getName() << " has taken " << amount << " points of damage\n"
			<< this->getName() << " has " << this->getHitPoints() << " hit points left" << std::endl;

}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " is dead. Can't be repaired" << std::endl;
		return;
	}
	if (this->getEnergy() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " has no energy left. Can't be repaired" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->getName() << " repaired " << amount << " points" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	std::cout << this->getName() << " has " << this->getHitPoints() << " hit points" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& copy)
{
	this->_attackDamage = copy._attackDamage;
	this->_energyPoints = copy._energyPoints;
	this->_hitPoints = copy._hitPoints;
	this->_name = copy._name;
	return *this;
}