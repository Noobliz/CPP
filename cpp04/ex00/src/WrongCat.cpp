#include "../header/WrongCat.hpp"

WrongCat::WrongCat(){
    this->type = "WrongCat";
    std::cout<<"WrongCat default constructor called"<<std::endl;

}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other){
    this->type = other.type;
    std::cout<<this->type<<" copy type called"<<std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other){
    if (this != &other)
    {
        this->type = other.type;
        std::cout<<this->type<<" assignement type called"<<std::endl;
    }
    return *this;
}

WrongCat::~WrongCat(){
    std::cout<<"WrongCat destructor called"<<std::endl;
}

void WrongCat::makeSound() const{
    std::cout<<"Wrong Meow"<<std::endl;
}
