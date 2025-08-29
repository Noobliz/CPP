#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib> 

Base* generate(void)
{
    int i = std::rand() % 3;
    if (i == 0)
        return new A;
    if (i == 1)
        return new B;
    if (i == 2)
        return new C;
    return NULL;
}


void    identify(Base *p)
{
    if (!p)
    {
        std::cerr<<"Error: pointer is null\n";
        return ;
    }
    if (dynamic_cast<A*>(p))
        std::cout<<"Type is A\n";
    else if (dynamic_cast<B*>(p))
        std::cout<<"Type is B\n";
    else if (dynamic_cast<C*>(p))
        std::cout<<"Type is C\n";

}

void    identify(Base& p)
{
    try{
        dynamic_cast<A&>(p);
        std::cout<<"Type of ref is A\n";
    }
    catch(std::exception &e){}
    try{
        dynamic_cast<B&>(p);
        std::cout<<"Type of ref is B\n";
    }
    catch(std::exception &e){
    }
    try{
        dynamic_cast<C&>(p);
        std::cout<<"Type of ref is C\n";
    }
    catch(std::exception &e){
    }
}
int main(void)
{
    std::srand(std::time(NULL)); // for random num
    Base *p = generate();
    A a;
    Base &ref = a;
    identify(ref);
    identify(*p);//random ref
    identify(p); // random pointer

    if (p)
        delete p;
    return 0;
}