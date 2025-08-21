
#include "../header/DiamondTrap.hpp"

int main() {
    DiamondTrap a("Seagull");
    DiamondTrap b("Pigeon");
    
    a.attack("an ornithologist");
    a.whoAmI();
    
    b = a;
    b.whoAmI();
}