#pragma once

#include "AMateria.hpp"

class Cure : public AMateria{
    private:
    
    public:
        Cure();
        Cure(std::string const &type);
        Cure(const Cure& other);
        Cure &operator = (const Cure &other);
        ~Cure();
        Cure *clone() const;
        void use (ICharacter &target);
};