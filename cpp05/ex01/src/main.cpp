#include "../header/Bureaucrat.hpp"
#include "../header/Form.hpp"

int main()
{
    std::cout<<"\n|-----------[SIGNING FORM]-----------|"<<std::endl;
    Bureaucrat alex("Alex", 3);
    Form ab("AB11", 5, 2);
    std::cout<<"form status before being signed : "<<ab.getIsSigned()<<std::endl;
    alex.signForm(ab);
    std::cout<<"form status is_signed : "<<ab.getIsSigned()<<std::endl;

    std::cout<<"\n|-----------[FORM level too high]-----------|"<<std::endl;

    Form ac("AC", 1, 1);
    std::cout<<alex<<" will try to sign "<<ac<<std::endl;
    alex.signForm(ac);

    std::cout<<"\n|-----------[FORM copy]-----------|"<<std::endl;
    
    std::cout<<"Form to be copied\n";
    std::cout<<ab<<std::endl;
    Form ad(ab);
    std::cout<<"Form ad:\n";
    std::cout<<ad<<std::endl;

    std::cout<<"\n|-----------[Destructors]-----------|"<<std::endl;

    return 0;
}