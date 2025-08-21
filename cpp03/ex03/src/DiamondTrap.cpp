
#include "../header/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap(){
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30; 
    std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name")
{
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;
    std::cout<<"DiamondTrap "<<_name<<" is created"<<std::endl;

}
DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name) {
    std::cout << "DiamondTrap " << _name << " copied." << std::endl;
}

DiamondTrap::~DiamondTrap(){
    std::cout<<"DiamondTrap is destroyed"<<std::endl;
 }

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
         _name = other._name;
    }
    std::cout << "DiamondTrap " << _name << " assigned." << std::endl;
    return *this;
}
void DiamondTrap::whoAmI(){
    std::cout<<"My name is "<<this->_name<<std::endl;
    std::cout<<"My grandma is "<<ClapTrap::_name<<std::endl;
}

std::string DiamondTrap::getName(){
    return(_name);
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}
