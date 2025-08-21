#include "../header/ClapTrap.hpp"

int main()
{
    ClapTrap bob("Bob");
    ClapTrap georges(bob);
    ClapTrap ernest("ernest");
    ClapTrap lol("lol");

    for (int i = 0; i < 9; i++)
        bob.attack("nothing");

    lol = bob;
    lol.attack("void");
    bob.takeDamage(5);
    bob.beRepaired(3);
    bob.beRepaired(10);
    bob.attack("nothing again");
}