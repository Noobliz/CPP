#include "../header/PresidentialPardonForm.hpp"
#include "../header/Bureaucrat.hpp"



PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("Pardon", 25, 5),
_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other),
_target(other._target)
{}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target= other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

std::string PresidentialPardonForm::getTarget()const{
    return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)const{
    if (!getIsSigned())
        throw ErrorMsgException("Form wasn't signed");
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
    std::cout<<getTarget()<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;

}