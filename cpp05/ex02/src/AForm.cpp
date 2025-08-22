#include "../header/AForm.hpp"
#include "../header/Bureaucrat.hpp"

AForm::AForm(const std::string &name, int signGrade, int execGrade): _name(name),
_signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
    else if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other): _name(other._name + ".copy"), _signGrade(other._signGrade),
 _execGrade(other._execGrade), _isSigned(other._isSigned)
{
}

AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout<<getName()<<" AForm destructor called\n";
}

std::string AForm::getName()const{
    return _name;
}

int AForm::getSignGrade()const{
    return _signGrade;
}

int AForm::getExecGrade()const{
    return _execGrade;
}

bool AForm::getIsSigned()const
{
    return _isSigned;
}


const char* AForm::GradeTooHighException::what()const throw()
{
    return "Grade is too high";
}

const   char* AForm::GradeTooLowException::what()const throw()
{
    return "Grade is too low";
}


//----------------Personalized error msg----------------------
AForm::ErrorMsgException::ErrorMsgException(const std::string &msg):_msg(msg){}
AForm::ErrorMsgException::~ErrorMsgException()throw(){}
const char* AForm::ErrorMsgException::what()const throw()
{
    return _msg.c_str();
}
//-----------------------------------------------------------



void AForm::beSigned(const Bureaucrat &x){
    if (x.getGrade() > this->getSignGrade())
        throw GradeTooLowException();
    this->_isSigned = true;
}

std::ostream& operator<<(std::ostream &cout, AForm &x)
{
    cout<<x.getName()<<" sign_grade["<<x.getSignGrade()<<"] execution_grade["
        <<x.getExecGrade()<<"]"<<" AForm signed status = "<<x.getIsSigned();
    return cout;
}