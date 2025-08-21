#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name)
{
    //throw exception
    if (grade > 150)
    {
        throw GradeTooLowException();
    }
    else if (grade < 1)
    {
        throw GradeTooHighException();
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other.getName() + ".copy")
{
    _grade = other.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->_grade = other.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat(){
    std::cout<<"Bureaucrat : "<<this->getName()<<" destructor called"<<std::endl;
}

int Bureaucrat::getGrade()const{
    return _grade;
}

const std::string& Bureaucrat::getName()const{
    return _name;
}

void    Bureaucrat::promotion()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade -= 1;
}

void    Bureaucrat::demotion()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what()const throw()
{
    return "Grade is too high";
}

const   char* Bureaucrat::GradeTooLowException::what()const throw()
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream &cout, const Bureaucrat &x)
{
    cout<<x.getName()<<" bureaucrat grade "<<x.getGrade();
    return cout;
}