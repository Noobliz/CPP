#include "easyFind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main(void)
{
    std::vector<int> v;

    v.push_back(42);
    v.push_back(43);
    v.push_back(44);

    int valueFound;
    std::cout<<"vector contains : ";
    for (int i = 0; i < 3; i++)
        std::cout<<v[i]<<" ";
    std::cout<<"\n----[existing value]----\n\n";
    try{

        valueFound = easyFind(v, 42);
        std::cout<<valueFound<<std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<"----[non existant value]----\n\n";
    try{

        valueFound = easyFind(v, 652);
        std::cout<<valueFound<<std::endl;

    }
    catch (std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<"----[test with list]----\n\n";

    std::list<int> list1;
    for (int i = 0; i < 10; i++)
        list1.push_back(i+1);

    std::cout<<"list contains : ";
    for (std::list<int>::iterator it = list1.begin(); it != list1.end(); ++it)
        std::cout<<*it<<" ";
    std::cout<<std::endl;

    try{

        valueFound = easyFind(list1, 5);
        std::cout<<valueFound<<std::endl;

    }
    catch (std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }
    return 0;
}