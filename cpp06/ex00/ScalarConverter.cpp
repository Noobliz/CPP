#include "ScalarConverter.hpp"
#include <vector>
#include <string>
#include <limits.h>

//---------float :

// "nanf"

// "+inff"

// "-inff"

// -------double :

// "nan"

// "+inf"

// "-inf"
bool pseudoLiterals(const std::string &value)
{
    std::string type = "";
    std::string pseudoLiteralsF[] = {"-inff", "+inff", "inff", "nanf"};
    std::string pseudoLiteralsD[] = {"-inf", "+inf", "inf", "nan"};
    for (int i = 0; i < 4; i++)
    {
        if (value == pseudoLiteralsF[i])
            type = "float";
        if (value == pseudoLiteralsD[i])
            type = "double";
    }
    if (!type.empty())
    {
        std::cout<<"char : Impossible\n"
                <<"int : Impossible\n";
        if (type == "double"){
            std::cout<<"float : "<<value + "f"<<"\n"
                    <<"double : "<<value<<std::endl;
        }
        else{
            std::cout<<"float : "<<value<<"\n"
                    <<"double : "<<value.substr(0, value.size() -1)<<std::endl; //remove 2nd f
        }
        return true;
    }
    return false;
}

void    printFromChar(char c)
{
    std::cout<<"char : "<<c<<"\n"
            <<"int : "<<static_cast<int>(c)<<"\n"
            <<"float : "<<static_cast<float>(c)<<".0f\n"
            <<"double : "<<static_cast<double>(c)<<".0"<<std::endl;
}

bool isInteger(const std::string &value)
{

    int start = 0;

    if (value[0] == '+' || value[0] == '-')
        start = 1;
    
    if (start >= value.length())
        return false;

    for (int i = start; i < value.length(); i++) {
        if (!std::isdigit(value[i]))
            return false;
    }
    
    return true;
}
void printFromInt(const std::string &value)
{
    long longValue = std::strtol(value.c_str(), NULL, 10);
        
        if (longValue > INT_MAX || longValue < INT_MIN) {
            std::cout << "char: impossible\n"
                      << "int: impossible (overflow)\n"
                      << "float: " << static_cast<float>(longValue) << "f\n"
                      << "double: " << static_cast<double>(longValue) << std::endl;
            return;
        }
        
        int intValue = std::stoi(value, NULL, 10);
        
        if (intValue > 31 && intValue < 127) {
            std::cout << "char: '" << static_cast<char>(intValue) << "'\n";
        } 
        else if (intValue >= 0 && intValue <= 127) {
            std::cout << "char: Non displayable\n";
        } 
        
        
        std::cout << "int: " << intValue << "\n"
                  << "float: " << static_cast<float>(intValue) << ".0f\n"
                  << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
    }
void ScalarConverter::convert(const std::string &value)
{
    if (value.empty())
        return ;
    if (pseudoLiterals(value))
        return ;
    if (value.length() == 1 && std::isprint(value[0]) && !std::isdigit(value[0])){
        printFromChar(value[0]);
        return ;
    }
    if (isInteger(value)){
        printFromInt(value);
        return ;
    }
    //if isfloat

    //if isdouble
    else
        std::cout<<"non printable\n";
        
    return ;
    

}