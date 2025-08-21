#include "../header/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for(int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    if(this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (other._inventory[i] != NULL)
                _inventory[i] = (other._inventory[i])->clone();
        }
    }
}
MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
    {
        if (_inventory[i] != NULL)
            delete _inventory[i];
    }
    std::cout<<"MateriaSource destroyed"<<std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i] != NULL)
            {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
            if (other._inventory[i] != NULL)
                _inventory[i] = other._inventory[i]->clone();
        }
    }
    return *this;
}
void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return ;
    int i = 0;
    while (i < 4 && _inventory[i] != NULL)
        i++;
    if (i >= 4)
    {
        std::cout<<"MateriaSource inventory is full"<<std::endl;
        delete m;
        return ;
    }
    _inventory[i] = m;
    std::cout<<"Materia "<<_inventory[i]->getType()<<" learned."<<std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    int i = 0;
    if (type.empty())
    {
        std::cout<<"type is empty"<<std::endl;
        return NULL;
    }
    while (i < 4 && _inventory[i] != NULL)
    {
        if(_inventory[i]->getType() == type)
            return (_inventory[i]->clone());
        i++;
    }
    std::cout<<"Materia "<<type<<" not found"<<std::endl;
    return (NULL);
}