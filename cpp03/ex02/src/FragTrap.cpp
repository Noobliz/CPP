#include "../header/FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
    this->_attackDamage = 30;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
    std::cout << "FragTrap (default) created." << std::endl;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name){
    this->_attackDamage = 30;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
   std::cout << "FragTrap " << _name << " created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy):ClapTrap(copy){
    std::cout << "FragTrap from ClapTrap " << _name 
        << " copied." << std::endl;
}

// not possible like this if default constructor of claptrap is private
// FragTrap::FragTrap(const FragTrap &copy)
// {
//     *this = copy;
//     std::cout << this->_name << ": FragTrap Copy constructor called" << std::endl;
// }

FragTrap	&FragTrap::operator=(FragTrap const &copy)
{
    if(this != &copy)
    {
        ClapTrap::operator=(copy); 
        std::cout << "FragTrap " << _name << " assigned." << std::endl;
    }
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destroyed." << std::endl;
}
void FragTrap::highFivesGuys()
{
    if (this->_hitPoints <= 0)
        std::cout<<"no high five because "<<_name<<" is dead!"<<std::endl;
    else
        std::cout<<"a positive high-fives request on the standard output."<<std::endl;
}

