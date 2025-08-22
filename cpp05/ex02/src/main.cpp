#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib> 

int main()
{
    std::srand(std::time(NULL));//for RobotomtForm


    std::cout<<"\n|-----------[exec ShrubberyFORM]-----------|"<<std::endl;
    Bureaucrat alex("Alex", 1);
    AForm *test = new ShrubberyCreationForm("prout");
    //ShrubberyCreationForm test("test");
    alex.executeForm(*test);
    
    alex.signForm(*test);
    alex.executeForm(*test);

    std::cout<<"\n|-----------[exec RobotomyFORM]-----------|"<<std::endl;
    AForm *robot = new RobotomyRequestForm("Bob");
    alex.signForm(*robot);
    alex.executeForm(*robot);
    alex.executeForm(*robot);
    alex.executeForm(*robot);

        std::cout<<"\n|-----------[exec PardonFORM]-----------|"<<std::endl;
    AForm *pardon = new PresidentialPardonForm("Ernest");
    alex.signForm(*pardon);
    alex.executeForm(*pardon);


    std::cout<<"\n|-----------[Destructors]-----------|"<<std::endl;
    delete test;
    delete robot;
    delete pardon;

    return 0;
}