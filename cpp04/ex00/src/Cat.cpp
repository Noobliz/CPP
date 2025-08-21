
#include "../header/Cat.hpp"

Cat::Cat(){
    this->type = "Cat";
    std::cout<<"Cat default constructor called"<<std::endl;

}

Cat::Cat(const Cat &other): Animal(other){
    this->type = other.type;
    std::cout<<this->type<<" copy type called"<<std::endl;
}

Cat &Cat::operator=(const Cat &other){
    if (this != &other)
    {
        this->type = other.type;
        std::cout<<this->type<<" assignement type called"<<std::endl;
    }
    return *this;
}

Cat::~Cat(){
    std::cout<<this->type
    <<" destructor called"<<std::endl;
}

void Cat::makeSound() const{
    std::cout<<"MEOW"<<std::endl;
}