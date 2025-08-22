#pragma once
#include <iostream>

class AForm;
class   Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    public:
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();


        const   std::string& getName()const;
        int     getGrade()const;

        void    promotion();
        void    demotion();

        class GradeTooHighException: public std::exception{
            public:
                const char* what() const throw();
        };

        class GradeTooLowException: public std::exception{
            public:
                const char* what() const throw();
        };

        void    signForm(AForm &x);
        void    executeForm(AForm const &form)const;

};

std::ostream& operator<<(std::ostream &cout, const Bureaucrat &x);