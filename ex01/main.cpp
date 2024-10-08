#include "ScavTrap.hpp"

void    getStats(ClapTrap& clap)
{
    std::cout << clap.getName() << "'s stats\n"\
    << "Hit points " << clap.getHitPoints() << std::endl\
    << "energy points " << clap.getEnergy() << std::endl;
}

int main(void)
{
    ClapTrap clap("Buddy");
    ScavTrap scrav("Pedro");
    getStats(scrav);
    getStats(clap);
    scrav.guardGate();
    for (int i = 0; i < 10; i++)
    {
        scrav.attack("Anton");
        clap.attack("Jose");
    }
    scrav.takeDamage(10000);
    scrav.beRepaired(110);
    getStats(scrav);
    getStats(clap);
    clap.attack("Jose");
}