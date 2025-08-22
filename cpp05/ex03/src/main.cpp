#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/Intern.hpp"
#include <ctime>
#include <cstdlib> 

int main()
{
    std::srand(std::time(NULL));//for RobotomtForm


    std::cout<<"\n|-----------[Intern makeFORM]-----------|"<<std::endl;
    Bureaucrat alex("Alex", 1);
    Intern intern1;
    AForm *test;
    test = intern1.makeForm("robotomy request", "bob");
    alex.signForm(*test);
    alex.executeForm(*test);
    delete test;

    std::cout<<"\n|-----------[makeFORM wrong name]-----------|"<<std::endl;
    test = intern1.makeForm("wrong name", "bob");
    if (test)
        alex.signForm(*test);

    std::cout<<"\n|-----------[Destructors]-----------|"<<std::endl;
    if (test)
        delete test;
    return 0;
}