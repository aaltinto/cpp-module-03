#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap trap("Buddy");
    ClapTrap test;
    ClapTrap tryHard(test);

    test = trap;

    tryHard.takeDamage(10000);
    tryHard.beRepaired(100);
    trap.attack("Hose");
    test.attack("Ben");
}