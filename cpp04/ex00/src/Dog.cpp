#include "../header/Dog.hpp"

Dog::Dog(){
    this->type = "Dog";
    std::cout<<"Dog default constructor called"<<std::endl;

}

Dog::Dog(const Dog &other): Animal(other){
    this->type = other.type;
    std::cout<<this->type<<" copy type called"<<std::endl;
}

Dog &Dog::operator=(const Dog &other){
    if (this != &other)
    {
        this->type = other.type;
        std::cout<<this->type<<" assignement type called"<<std::endl;
    }
    return *this;
}

void Dog::makeSound() const{
    std::cout<<"WAF"<<std::endl;
}

Dog::~Dog(){
    std::cout<<this->type
    <<" destructor called"<<std::endl;
}