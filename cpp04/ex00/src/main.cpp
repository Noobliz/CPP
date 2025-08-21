
#include "../header/Animal.hpp"
#include "../header/Dog.hpp"
#include "../header/Cat.hpp"
#include "../header/WrongAnimal.hpp"
#include "../header/WrongCat.hpp"

int main()
{
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout<<std::endl;

    std::cout << dog->getType() << " : ";
    dog->makeSound();
    std::cout << cat->getType() << " : ";
    cat->makeSound();
    animal->makeSound();


    std::cout<<"\n------WRONG ANIMAL TESTS-------\n"<<std::endl;
    const WrongAnimal* wrongCreature = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout<<std::endl;

    std::cout << wrongCat->getType() << " : ";
    wrongCat->makeSound();
    wrongCreature->makeSound();

    std::cout<<"\n------destructors-------\n"<<std::endl;
    delete animal;
    delete cat;
    delete dog;
    delete wrongCreature;
    delete wrongCat;
    return 0;
}