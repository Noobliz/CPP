
#include "../header/FragTrap.hpp"

int main()
{
    //ClapTrap jean("jean");
    FragTrap bob("bob");
    FragTrap lol("lol");
    FragTrap Ernest(lol);
    FragTrap same("same");
    same = bob;
    same.attack("something");
    same.takeDamage(50);
    same.highFivesGuys();
    same.beRepaired(500);
}