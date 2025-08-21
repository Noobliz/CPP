#include "../header/AAnimal.hpp"

AAnimal::AAnimal():type("living creature"){
    std::cout<<"AAnimal default constructor called"<<std::endl;

}

AAnimal::AAnimal(const AAnimal &other){
    this->type = other.type;
    std::cout<<"AAnimal copy constructor called"<<std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other){
    if (this != &other)
    {
        this->type = other.type;
    }
    std::cout<<"AAnimal assignment operator called"<<std::endl;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout<<"AAnimal destructor called"<<std::endl;
}
std::string AAnimal::getType() const{
    return (type);
}

void AAnimal::makeSound() const{
    std::cout<<"silence\n";
}
