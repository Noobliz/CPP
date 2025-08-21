#include "../header/Dog.hpp"

Dog::Dog(){
    std::cout<<"Dog default constructor called"<<std::endl;
    this->type = "Dog";
    this->brain = new(std::nothrow) Brain();

}

Dog::Dog(const Dog &other): AAnimal(other){
    std::cout<<this->type<<" copy type called"<<std::endl;
    this->type = other.type;
    this->brain = new(std::nothrow) Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other){
    if (this != &other)
    {
        std::cout<<this->type<<" assignement type called"<<std::endl;
        this->type = other.type;
        delete this->brain;
        this->brain = new(std::nothrow) Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const{
    std::cout<<"WAF"<<std::endl;
}

Dog::~Dog(){
    delete this->brain;
    std::cout<<this->type
    <<" destructor called"<<std::endl;
}

void    Dog::setIdea(const std::string idea, int index){
    if (this->brain)
        this->brain->setIdeas(idea, index);

}

std::string Dog::getIdea(int index)const{
    if (this->brain)
        return this->brain->getIdeas(index);
    return "";
}