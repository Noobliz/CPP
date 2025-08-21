#include "../header/Cure.hpp"

Cure::Cure(){
    this->type = "cure";
}

Cure::Cure(std::string const &type)
{
    (void)type;
    this->type = "cure";
}

Cure::Cure(const Cure &other): AMateria(other)
{
    (void)other;
    this->type = "cure";
}
Cure &Cure::operator=(const Cure &other){
    (void)other;
    return (*this);
}

Cure::~Cure(){
    //std::cout<<"destructor Cure called"<<std::endl;
}

Cure* Cure::clone() const
{
    Cure *cloned = new Cure(*this);
    return cloned;
}

void Cure::use(ICharacter &target)
{
    std::cout<<"* heals "<<target.getName()<<" wounds *"<<std::endl;
}