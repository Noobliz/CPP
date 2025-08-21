#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        ~Dog();
        void    makeSound() const;
        void    setIdea(const std::string idea, int index);
        std::string getIdea(int index)const;
};