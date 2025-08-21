
#include "../header/WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("Wrong living creature"){
    std::cout<<"Wrong Animal default constructor called"<<std::endl;

}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
    this->type = other.type;
    std::cout<<"WrongAnimal copy constructor called"<<std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout<<"WrongAnimal assignment operator called"<<std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout<<type<<" destructor called"<<std::endl;
}

std::string WrongAnimal::getType() const{
    return (type);
}

void WrongAnimal::makeSound() const{
    std::cout<<this->type<<" screams : Wrong BOAAAR\n";
}


