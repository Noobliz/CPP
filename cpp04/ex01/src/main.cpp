#include "../header/Animal.hpp"
#include "../header/Dog.hpp"
#include "../header/Cat.hpp"
#include "../header/Brain.hpp"

int main(void)
{
    int nbAnimals = 6;
    Animal *animals[nbAnimals];


	std::cout << "\n--- [ Constructors Dogs] ---\n" << std::endl;

	for (int i = 0; i < nbAnimals / 2; ++i)
		animals[i] = new Dog();

    for (int i = 0; i < nbAnimals / 2; i++)
        animals[i]->makeSound();

    std::cout << "\n--- [ Constructors Cats] ---\n" << std::endl;

	for (int i = nbAnimals / 2; i < nbAnimals; ++i)
		animals[i] = new Cat();

    std::cout << "\n--- [ tests Dogs by copy ] ---\n" << std::endl;
    {
        Dog basicDog;
        basicDog.setIdea("I want to eat my poop", 0);

        Dog copyDog (basicDog);

        std::cout << "Original idea of basicDog: " << basicDog.getIdea(0) << std::endl;
        std::cout << "Copied idea in copyDog: " << copyDog.getIdea(0) << std::endl;

        copyDog.setIdea("I want to dig a hole", 0);
        std::cout << "After modification, basicDog idea: " << basicDog.getIdea(0) << std::endl;
        std::cout << "After modification, copyDog idea: " << copyDog.getIdea(0) << std::endl;
    }
    std::cout << "\n--- [ tests Cat by assignment ] ---\n" << std::endl;
    {
        Cat trueCat;
        Cat otherCat;

        trueCat.setIdea("I want to get through the door", 0);
        otherCat.setIdea("rrrrrrrrrr ball of furr", 0);
        std::cout<<"trueCat idea : "<<trueCat.getIdea(0)<<std::endl;
        std::cout<<"otherCat idea : "<<otherCat.getIdea(0)<<std::endl;

        otherCat = trueCat;
        trueCat.setIdea("NIARKNIARK", 0);
        //std::cout<<"trueCat idea: "<<trueCat.getIdea(0)<<std::endl;
        std::cout<<"after assignation, otherCat idea : "<<otherCat.getIdea(0)<<std::endl;
    }
    std::cout<<"\n---- [destructors] ---\n"<<std::endl;
    for (int i = 0; i < nbAnimals; i++)
        delete animals[i];

    return (0);
}