#include <iostream>
#include <string.h>
#include "RPN.hpp"

int main(int argc, char **argv)
{
    std::string values;
    if (argc > 1)
    {
        for(int i = 1; i < argc; ++i)
        {
            values += argv[i];
            if (i < argc -1)
                values += " ";
        }
        //std::cout<<"values = "<<values<<std::endl;
        RPN(values);
    }
    else
    {
        std::cerr<<"Error: input an operation"<<std::endl;
    }
}