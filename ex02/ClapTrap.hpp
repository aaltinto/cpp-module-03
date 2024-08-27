#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	protected:
		std::string 	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
    public:
		ClapTrap(std::string name = NULL);
		ClapTrap(ClapTrap& copy);
		~ClapTrap();
		ClapTrap &operator=(ClapTrap const &copy);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		std::string	getName(void) const;
		unsigned int getDamage(void) const;
		unsigned int getEnergy(void) const;
		unsigned int getHitPoints(void) const;
};

#endif