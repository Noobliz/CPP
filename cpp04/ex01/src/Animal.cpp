#include "../header/Animal.hpp"

Animal::Animal():type("living creature"){
    std::cout<<"Animal default constructor called"<<std::endl;

}

Animal::Animal(const Animal &other){
    this->type = other.type;
    std::cout<<"Animal copy constructor called"<<std::endl;
}

Animal &Animal::operator=(const Animal &other){
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout<<"Animal assignment operator called"<<std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout<<"Animal destructor called"<<std::endl;
}
std::string Animal::getType() const{
    return (type);
}

void Animal::makeSound() const{
    std::cout<<"silence\n";
}
