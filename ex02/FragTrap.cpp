#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->_attackDamage = 20;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
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