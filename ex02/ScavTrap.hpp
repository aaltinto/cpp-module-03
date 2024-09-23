#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap& copy);
        ~ScavTrap();
        void guardGate();
        void attack(const std::string &target);
        ScavTrap &operator=(ScavTrap& const copy);
    
};