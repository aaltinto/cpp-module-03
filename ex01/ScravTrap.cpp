#include "ScravTrap.hpp"

ScravTrap::ScravTrap(std::string name): ClapTrap(name)
{
    this->_attackDamage = 20;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    std::cout << "Constructor called for ScravTrap " << this->getName() << std::endl;
}

ScravTrap::ScravTrap(ScravTrap& copy): ClapTrap(copy)
{
    std::cout << "Copy constructor called for ScravTrap " << this->getName() << std::endl;
}

ScravTrap::~ScravTrap()
{
    std::cout << "Destructor called for ScravTrap " << this->getName() << std::endl;
}

void ScravTrap::guardGate()
{
    std::cout << "ScravTrap " << this->getName() << " in gate keeper mode" << std::endl;
}

void ScravTrap::attack(const std::string &target)
{
    if (this->getHitPoints() <= 0)
	{
		std::cout << "ScravTrap " << this->getName() << " has no hit points left" << std::endl;
		return;
	}
	if (this->getEnergy() <= 0)
	{
		std::cout << "ScravTrap " << this->getName() << " has no energy left" << std::endl;
		return;
	}
	std::cout << "ScravTrap " << this->getName() << " attacks " << target << ", causing ";
	std::cout << this->getDamage() << " points of damage" << std::endl;
	this->_energyPoints -= 1;
}