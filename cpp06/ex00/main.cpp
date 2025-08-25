#include "ScalarConverter.hpp"

int main(void)
{
    char c = 'c';

    //non printable char
    // std::string g = "~";
    // for (int i = 0; i < 2; i++)
    //     g[0] +=1;

     ScalarConverter::convert("+1255");
    float a = 42.6f;
    //std::cout<<"a : "<<static_cast<int>(a)<<std::endl;
    return 0;
}