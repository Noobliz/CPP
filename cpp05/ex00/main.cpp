#include "Bureaucrat.hpp"

int main()
{
    std::cout<<"\n|-----------[Grade too low]-----------|"<<std::endl;
    try
    {
        Bureaucrat bob("Bob", 15000);
    }
    catch (Bureaucrat::GradeTooHighException &e) //not the correct exception
    {
        std::cerr << e.what() << '\n';
        //problems
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout<<"\n|-----------[Grade too high for promotion]-----------|"<<std::endl;
    Bureaucrat ernest("Ernest", 1);
    std::cout << ernest<<std::endl;
    try
    {
        ernest.promotion();
    }
    catch (const std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }
    std::cout <<"after promotion attempted: "<< ernest<<std::endl;

    std::cout<<"\n|-----------[Assignment operator]-----------|"<<std::endl;
    Bureaucrat alex("Alex", 5);
    std::cout<<alex<<std::endl;
    std::cout<<"before assignment "<<ernest<<std::endl;
    ernest = alex;
    std::cout<<"after assignment "<<ernest<<std::endl;
    
    
    
    std::cout<<"\n|-----------[Copy constructor]-----------|"<<std::endl;
    Bureaucrat copy(ernest);
    std::cout<<copy<<std::endl;

    std::cout<<"\n|-----------[Destructors]-----------|"<<std::endl;

    return 0;
}