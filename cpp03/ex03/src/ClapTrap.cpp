
#include "../header/ClapTrap.hpp"


ClapTrap::ClapTrap(): _hitPoints(10), _energyPoints(10), _attackDamage(10){

}

ClapTrap::ClapTrap(const std::string &name) 
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(10)
{
    std::cout<<"ClapTrap "<<_name<<" is created with default constructor"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name),
      _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints),
      _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap " << _name << " copied!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap " << _name << " assigned!" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destroyed!" << std::endl;
}

void    ClapTrap::attack (const std::string &target){
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout<<"ClapTrap "<<_name<<" can't attack"<<std::endl;
        return ;
    }
    _energyPoints--;
    std::cout<<"ClapTrap "<<_name<<" attacks "<< target
    <<" dealing "<<_attackDamage<<" damage!"<<std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount){
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
        return;
    }
    _hitPoints -= amount;
    if (_hitPoints < 0)
        _hitPoints = 0;
    std::cout << "ClapTrap " << _name << " takes " << amount
              << " damage! Remaining HP: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can’t repair itself!"<< std::endl;
        return;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount
              << " HP. Total HP: " << _hitPoints << std::endl;
}