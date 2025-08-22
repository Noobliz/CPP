
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("Shrubbery", 145, 137),
_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other),
_target(other._target)
{}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target= other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

std::string ShrubberyCreationForm::getTarget()const{
    return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor)const{
    
    if (!getIsSigned())
        throw ErrorMsgException("Form not signed");

    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
    std::ofstream file((getTarget()+"_shrubbery").c_str());
    if (!file)
        throw ErrorMsgException("Error with file");
    
    file <<"             &&& &&  & &&\n"
        <<"         && &__&_& ()|/ @, &&\n"
        <<"          &__(/&/&||/& /_/)_&/_&\n"
        <<"     &() &__&|()|/&_& '% _&_ ()"<<"\n"
        <<"        &_&_&&_& |& |&&/&__%_/_& &\n"
        <<"       &&   && & &| &| /& & % ()& /&\n"
        <<"        ()&_---()&_&_|&&-&&--%---()~\n"
        <<"               &&     _|||\n"
        <<"                 |||\n"
        <<"                 |||\n"
        <<"                 |||\n"
        <<"            , -=-~  .-^- _\n";
    file.close();

}