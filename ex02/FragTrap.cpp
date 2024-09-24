#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->_attackDamage = 30;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    std::cout << "Constructor called for FragTrap " << this->getName() << std::endl;
}

FragTrap::FragTrap(FragTrap& copy): ClapTrap(copy)
{
    std::cout << "Copy constructor called for FragTrap " << this->getName() << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor called for FragTrap " << this->getName() << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->getName() << " is requesting a positive high fives" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (this->getHitPoints() <= 0)
	{
		std::cout << "FragTrap " << this->getName() << " has no hit points left" << std::endl;
		return;
	}
	if (this->getEnergy() <= 0)
	{
		std::cout << "FragTrap " << this->getName() << " has no energy left" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing ";
	std::cout << this->getDamage() << " points of damage" << std::endl;
	this->_energyPoints -= 1;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "FragTrap " << this->getName() << " already dead" << std::endl;
		return ;
	}
	if (this->_hitPoints <= amount)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "FragTrap " << this->getName() << " has taken " << amount << " points of damage\n"
			<< this->getName() << " has " << this->getHitPoints() << " hit points left" << std::endl;

}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << "FragTrap " << this->getName() << " is dead. Can't be repaired" << std::endl;
		return;
	}
	if (this->getEnergy() <= 0)
	{
		std::cout << "FragTrap " << this->getName() << " has no energy left. Can't be repaired" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->getName() << " repaired " << amount << " points" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	std::cout << this->getName() << " has " << this->getHitPoints() << " hit points" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& copy)
{
    this->_attackDamage = copy._attackDamage;
    this->_energyPoints = copy._energyPoints;
    this->_hitPoints = copy._hitPoints;
    this->_name = copy._name;
    return *this;
}