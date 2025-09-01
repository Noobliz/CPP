#include "Test.hpp"


Test::Test(int number):_number(number){}

Test::~Test(){}

int Test::getNumber()const
{
    return (_number);
}


bool operator>(const Test &x, const Test &y){
    if (x.getNumber() > y.getNumber())
        return true;
    return false;
}

std::ostream &operator<<(std::ostream &cout, const Test &x)
{
    cout << x.getNumber();
    return cout;
}

