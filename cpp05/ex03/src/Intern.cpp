#include "../header/Intern.hpp"

Intern::Intern(void){}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern::~Intern(void){}

Intern &Intern::operator=(const Intern &src)
{
    (void)src;
    return *this;
}


AForm* Intern::createShrubberyForm(const std::string &target)const{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string &target)const{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardonForm(const std::string &target)const{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target)const
{
    //compilator magic that knows how to associate each parameter
    FormManagment forms[]={
        {"shrubbery request", &Intern::createShrubberyForm},
        {"robotomy request", &Intern::createRobotomyForm},
        {"presidential pardon", &Intern::createPardonForm}
    };
    for (int i = 0; i < 3; i++)
    {
        if (name == forms[i].name)
        {
            std::cout<<"Intern creates "<<name<<std::endl;
            return (this->*(forms[i].creator))(target);//"->*" syntax to call the function through the pointer
        }
    }
    std::cerr<<"Form's name not found"<<std::endl;
    return NULL;
}