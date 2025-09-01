#pragma once
#include <iostream>

class   Test
{
    private:
        int _number;
        Test(const Test &copy);
        Test &operator=(const Test &other);
    public:
        Test(int number);
        int getNumber()const;
        ~Test();

};

    
bool operator>(const Test &x, const Test &y);
std::ostream &operator<<(std::ostream &cout, const Test &x);