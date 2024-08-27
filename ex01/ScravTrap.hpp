#include "ClapTrap.hpp"

class ScravTrap : public ClapTrap {
    public:
        ScravTrap(std::string name);
        ScravTrap(ScravTrap& copy);
        ~ScravTrap();
        void guardGate();
        void attack(const std::string &target);
    
};