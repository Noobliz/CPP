
#include "../header/Cat.hpp"

Cat::Cat(){
    std::cout<<"Cat default constructor called"<<std::endl;
    this->type = "Cat";
    this->brain = new(std::nothrow) Brain();

}

Cat::Cat(const Cat &other): Animal(other){
    std::cout<<this->type<<" copy type called"<<std::endl;
    this->type = other.type;
    this->brain = new(std::nothrow) Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other){
    if (this != &other)
    {
        std::cout<<this->type<<" assignement type called"<<std::endl;
        this->type = other.type;
        delete this->brain;
        this->brain = new(std::nothrow) Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat(){
    delete this->brain;
    std::cout<<this->type
    <<" destructor called"<<std::endl;
}

void Cat::makeSound() const{
    std::cout<<"MEOW"<<std::endl;
}

void    Cat::setIdea(const std::string idea, int index){
    if (this->brain)
        this->brain->setIdeas(idea, index);

}

std::string Cat::getIdea(int index)const{
    if (this->brain)
        return this->brain->getIdeas(index);
    return "";
}