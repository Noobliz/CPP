
#pragma once
#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &other);
        Brain &operator=(const Brain& other);
        ~Brain();

        void    setIdeas(const std::string idea, int index);
        std::string getIdeas(int index)const;
};

