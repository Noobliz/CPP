#include "../header/AAnimal.hpp"
#include "../header/Dog.hpp"
#include "../header/Cat.hpp"
#include "../header/Brain.hpp"

int main(void)
{
    int nbAAnimals = 6;
    AAnimal *AAnimals[nbAAnimals];
    //AAnimal a; ->proves that the class is abstract (do not compile)


	std::cout << "\n--- [ Constructors Dogs] ---\n" << std::endl;

	for (int i = 0; i < nbAAnimals / 2; ++i)
		AAnimals[i] = new Dog();

    for (int i = 0; i < nbAAnimals / 2; i++)
        AAnimals[i]->makeSound();

    std::cout<<"\n--- [ Constructors Cats] ---\n"<< std::endl;

	for (int i = nbAAnimals / 2; i < nbAAnimals; ++i)
		AAnimals[i] = new Cat();

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
    for (int i = 0; i < nbAAnimals; i++)
        delete AAnimals[i];

    return (0);
}