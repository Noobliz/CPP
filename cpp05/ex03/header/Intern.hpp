
#pragma once
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;
class Intern{

    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        struct FormManagment{
            const std::string name;
            AForm* (Intern::*creator)(const std::string &target)const;
        };
        AForm* createShrubberyForm(const std::string &target)const;
        AForm* createRobotomyForm(const std::string &target)const;
        AForm* createPardonForm(const std::string &target)const;
        AForm* makeForm(std::string name, std::string target)const;

};