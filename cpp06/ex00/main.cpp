#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    //char c = 'c';
    if (argc != 2)
        return 0;
    //non printable char
    // std::string g = "~";
    // for (int i = 0; i < 2; i++)
    //     g[0] +=1;
    // (void)argv;
     ScalarConverter::convert(argv[1]);
    //float a = 42.6f;
    //std::cout<<"a : "<<static_cast<int>(a)<<std::endl;
    return 0;
}