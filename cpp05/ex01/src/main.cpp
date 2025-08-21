#include "../header/Bureaucrat.hpp"
#include "../header/Form.hpp"

int main()
{
    std::cout<<"\n|-----------[SIGNING FORM]-----------|"<<std::endl;
    Bureaucrat alex("Alex", 3);
    Form ab("AB11", 5, 2);
    alex.signForm(ab);

    std::cout<<"\n|-----------[Destructors]-----------|"<<std::endl;

    return 0;
}