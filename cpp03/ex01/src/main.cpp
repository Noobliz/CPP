
#include "../header/ScavTrap.hpp"

int main()
{
    //ClapTrap jean("jean");
    ScavTrap bob("bob");
    ScavTrap lol("lol");
    ScavTrap Ernest(lol);
    ScavTrap same("same");
    same = bob;
    same.attack("something");
    same.takeDamage(100);
    same.guardGate();
}