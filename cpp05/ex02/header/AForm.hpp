#pragma once
#include <iostream>
//#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
    private:
        const std::string _name;
        const int _signGrade;
        const int _execGrade;
        bool _isSigned;

    public:
        AForm(const std::string &name, int signGrade, int execGrade);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

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
        class ErrorMsgException:public std::exception{
                std::string _msg;
            public:
                ErrorMsgException(const std::string &msg);
                ~ErrorMsgException()throw();
                const char* what()const throw();
        };
    
        void beSigned(const Bureaucrat &x);
        virtual void execute(Bureaucrat const &executor)const = 0;
};

std::ostream &operator<<(std::ostream &cout, AForm &x);