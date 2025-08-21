#pragma once
#include <iostream>
//#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    private:
        const std::string _name;
        const int _signGrade;
        const int _execGrade;
        bool _isSigned;

    public:
        Form(const std::string &name, int signGrade, int execGrade);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        std::string getName()const;
        int getSignGrade()const;
        int getExecGrade()const;
        bool getIsSigned()const;

        class GradeTooHighException: public std::exception{
          const char* what()const throw();  
        };
        class GradeTooLowException: public std::exception{
            const char* what()const throw();
        };

        void beSigned(const Bureaucrat &x);
};

//surcharge <<