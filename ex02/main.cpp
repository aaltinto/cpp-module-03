#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <unistd.h>

int main(void)
{
	ClapTrap trap("Buddy");
	ScavTrap scav("George");
	FragTrap frag("Steve");

	trap.attack("George");
	scav.takeDamage(trap.getDamage());
	scav.attack("Buddy");
	trap.takeDamage(scav.getDamage());
	sleep(1);
	while ((frag.getHitPoints() > 0 && frag.getEnergy() > 0)
		&& (scav.getHitPoints() > 0 && scav.getEnergy() > 0))
	{
		std::cout << "\033[2J";
		std::cout << "\033[H";
		frag.attack("George");
		scav.takeDamage(frag.getDamage());
		if (scav.getHitPoints() < 50)
			scav.beRepaired(25);
		sleep(1);
		std::cout << "\033[2J";
		std::cout << "\033[H";
		scav.attack("Steve");
		frag.takeDamage(scav.getDamage());
		if (frag.getHitPoints() < 50)
			frag.beRepaired(25);
		sleep(1);
	}
}