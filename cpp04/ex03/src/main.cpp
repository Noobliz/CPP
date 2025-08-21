#include "../header/AMateria.hpp"
#include "../header/Ice.hpp"
#include "../header/Cure.hpp"
#include "../header/Character.hpp"
#include "../header/MateriaSource.hpp"


int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    //src->learnMateria(new Ice);
    ICharacter* me = new Character("me");
    AMateria* tmp;
    std::cout<<std::endl;
    std::cout<<"---------[INVENTORY FULL]----------"<<std::endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp); //no space

    std::cout<<std::endl;
    std::cout<<"---------[UNEQUIP AND STORE]----------"<<std::endl;
    me->unequip(1);

    ICharacter* bob = new Character("bob");
    bob->equip(src->createMateria("ice"));
    bob->equip(src->createMateria("cure"));
    bob->unequip(0);//stocked in materiaHandler from an other instance

    std::cout<<std::endl;
    std::cout<<"|---------[USE EXISTING/UNEXISTING]----------|"<<std::endl;
    me->use(0, *bob);
    me->use(1, *bob);//no materia here
    me->use(-630, *bob);
    me->equip(NULL);

    std::cout<<std::endl;
    std::cout<<"|---------[ASSIGNEMENT DEEP COPY]----------|"<<std::endl;
    me->equip(src->createMateria("cure")); //me is full at this point
    *static_cast<Character*>(bob) = *static_cast<Character*>(me);//assignement
    me->unequip(3);
    tmp = src->createMateria("ice");
    me->equip(src->createMateria("cure"));
    bob->equip(tmp);

    std::cout<<std::endl;
    std::cout<<"|---------[COPY CONSTRUCTOR DEEP COPY]----------|"<<std::endl;
    Character jack("jack");
    jack.equip(src->createMateria("cure"));
    Character jackCopy(jack);
    jack.unequip(0);
    jackCopy.use(0, jack);//works because of deep copy



    delete bob;
    delete me;
    delete src;
}