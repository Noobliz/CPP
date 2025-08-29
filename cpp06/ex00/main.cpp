#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout<<"input 1 value\n";
        return 0;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}