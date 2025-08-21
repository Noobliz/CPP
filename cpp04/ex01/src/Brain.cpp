
#include "../header/Brain.hpp"

Brain::Brain(){
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; ++i)
        ideas[i] = "idea not set";
}


Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other)
	{
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain(){
    std::cout<<"brain destructor called"<<std::endl;
}




void    Brain::setIdeas(const std::string idea, int index)
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdeas(int index)const
{
    if (index >= 0 && index < 100)
        return (ideas[index]);
    return "";
}