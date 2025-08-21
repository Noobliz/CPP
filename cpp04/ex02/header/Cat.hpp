#pragma once

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat: public AAnimal{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        ~Cat();
        void    makeSound() const;
        void    setIdea(const std::string idea, int index);
        std::string getIdea(int index)const;

};