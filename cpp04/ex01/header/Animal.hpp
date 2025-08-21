
#pragma once
#include <iostream>

class Animal{
    protected:
        std::string type;
    public:
        Animal();
        //Animal(const std::string &type);
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        //virtual to avoid incmplete destruct, because will be used in polymorph context
        virtual ~Animal(); 
        virtual void makeSound() const;
        std::string getType() const;
};




