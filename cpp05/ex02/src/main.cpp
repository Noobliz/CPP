#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"

int main()
{
    std::cout<<"\n|-----------[SIGNING FORM]-----------|"<<std::endl;
    Bureaucrat alex("Alex", 1);
    ShrubberyCreationForm test("test");
    alex.executeForm(test);
    
    alex.signForm(test);
    alex.executeForm(test);

    std::cout<<"\n|-----------[Destructors]-----------|"<<std::endl;

    return 0;
}