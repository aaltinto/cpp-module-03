#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap(std::string name);
        FragTrap(FragTrap& copy);
        ~FragTrap();
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
        void highFivesGuys();
        FragTrap &operator=(const FragTrap& copy);
    
};