#pragma once
# include "ICharacter.hpp"
# include "AMateria.hpp"


class Character: public ICharacter{
    private:
        std::string _name;
        AMateria *_Inventory[4];
        int _NbMateria;
        AMateria *_bag[100];
    public:
        Character(std::string const &name);
        Character(const Character &other);
        Character &operator=(const Character &other);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        void    printMateria();
};
