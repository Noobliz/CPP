#include "../header/Form.hpp"
#include "../header/Bureaucrat.hpp"

Form::Form(const std::string &name, int signGrade, int execGrade): _name(name),
_signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
    else if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other): _name(other._name), _signGrade(other._signGrade),
 _execGrade(other._execGrade), _isSigned(other._isSigned)
{
}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form()
{
    std::cout<<getName()<<" Form destructor called\n";
}

std::string Form::getName()const{
    return _name;
}

int Form::getSignGrade()const{
    return _signGrade;
}

int Form::getExecGrade()const{
    return _execGrade;
}

bool Form::getIsSigned()const
{
    return _isSigned;
}


const char* Form::GradeTooHighException::what()const throw()
{
    return "Grade is too high";
}

const   char* Form::GradeTooLowException::what()const throw()
{
    return "Grade is too low";
}

void Form::beSigned(const Bureaucrat &x){
    if (x.getGrade() > this->getSignGrade())
        throw GradeTooLowException();
    this->_isSigned = true;
}

std::ostream& operator<<(std::ostream &cout, Form &x)
{
    cout<<x.getName()<<" sign_grade["<<x.getSignGrade()<<"] execution_grade["
        <<x.getExecGrade()<<"]"<<" form signed status = "<<x.getIsSigned();
    return cout;
}