#include "../header/MateriaHandler.hpp"
#include <iostream>

MateriaHandler::MateriaHandler() : _count(0) {
    for (int i = 0; i < 100; i++) {
        _droppedMateria[i] = NULL;
    }
}

MateriaHandler::MateriaHandler(const MateriaHandler &other)
{
    (void)other;
}

MateriaHandler& MateriaHandler::operator=(const MateriaHandler &other)
{
    (void)other;
    return *this;
}

//local static (not on stack so not destroyed at end of scope, just at end of program)
MateriaHandler& MateriaHandler::getInstance()
{
    static MateriaHandler instance; 
    return instance;
}

void MateriaHandler::addDroppedMateria(AMateria* materia)
{
    if (_count < 100 && materia != NULL) {
        _droppedMateria[_count] = materia;
        _count++;
        std::cout << "Materia "<<materia->getType()<<" stored in handler (total: " << _count << ")" << std::endl;
    }
}

void MateriaHandler::cleanup()
{
    int count = 0;
    for (int i = 0; i < _count; i++) {
        if(_droppedMateria[i] != NULL)
        {
            delete _droppedMateria[i];
            _droppedMateria[i] = NULL;
            count++;
        }
    }
    _count = 0;
    std::cout << "All dropped materia cleaned up (total: "<<count<<")" << std::endl;
}

MateriaHandler::~MateriaHandler() {
    cleanup();
}
