#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap& copy);
        ~ScavTrap();
        void guardGate();
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
        ScavTrap &operator=(const ScavTrap& copy);
    
};