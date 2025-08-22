
#include "../header/RobotomyRequestForm.hpp"
#include "../header/Bureaucrat.hpp"
// #include <ctime>
#include <cstdlib> 

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("Robotomy", 72, 45),
_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other),
_target(other._target)
{}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target= other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

std::string RobotomyRequestForm::getTarget()const{
    return _target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor)const{
    if (!getIsSigned())
        throw ErrorMsgException("Form wasn't signed");
    if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    std::cout<<"*****Annoying drilling noise*****\n";
    if (std::rand() % 2 == 0)
        std::cout<<getTarget()<<" has been robotomized successfully"<<std::endl;
    else
        std::cout<<"robotomy failed"<<std::endl;
    
}