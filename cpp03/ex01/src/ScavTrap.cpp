#include "../header/ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
    this->_attackDamage = 20;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
    std::cout << "ScavTrap (default) created." << std::endl;
}


ScavTrap::ScavTrap(const std::string &name): ClapTrap(name){
    this->_attackDamage = 20;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
    std::cout<<"ScavTrap from ClapTrap "<<_name
        <<" created."<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy):ClapTrap(copy){
    std::cout << "ScavTrap from ClapTrap " << _name 
        << " copied." << std::endl;
}


ScavTrap	&ScavTrap::operator=(ScavTrap const &copy)
{
	if (this != &copy)
    {
        ClapTrap::operator=(copy);
        std::cout << "ScavTrap " << _name << " assigned." << std::endl;

    }
    return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " destroyed." << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoints <= 0)
		std::cout << "No gate-keeper mode because: " << this->_name << " is dead" << std::endl;
	else
		std::cout << "ScavTrap from ClapTrap " << this->_name << " mode: Gate keeper" << std::endl;
}

void    ScavTrap::attack (const std::string &target){
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout<<"ScavTrap "<<_name<<" can't attack"<<std::endl;
        return ;
    }
    _energyPoints--;
    std::cout<<"ScavTrap "<<_name<<" attacks "<< target
    <<" dealing "<<_attackDamage<<" damage!"<<std::endl;
}

