#include "ScalarConverter.hpp"
#include <vector>
#include <string>
#include <limits.h>
#include <cstdlib>
#include <sstream>

//---------float :

// "nanf"

// "+inff"

// "-inff"

// -------double :

// "nan"

// "+inf"

// "-inf"

int stroi(const std::string &value) {
    std::stringstream ss(value);
    int result;
    ss >> result;
    return result;
}

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
    if (std::isprint(c))
        std::cout<<"char : '"<<c<<"'\n";
    else
        std::cout<<"char : non displayable\n";

    std::cout<<"int : "<<static_cast<int>(c)<<"\n"
        <<"float : "<<static_cast<float>(c)<<".0f\n"
        <<"double : "<<static_cast<double>(c)<<".0"<<std::endl;


}

bool isInteger(const std::string &value)
{

    int start = 0;

    if (value[0] == '+' || value[0] == '-')
        start = 1;
    
    if (start >= static_cast<int>(value.length()))
        return false;

    for (int i = start; i < static_cast<int>(value.length()); i++) {
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
        
        int intValue = stroi(value);
        
        if (intValue > 31 && intValue < 127) {
            std::cout << "char: '" << static_cast<char>(intValue) << "'\n";
        } 
        else if (intValue >= 0 && intValue <= 127) {
            std::cout << "char: Non displayable\n";
        }
        else
            std::cout<<"char : Impossible\n";
        
        
        std::cout << "int: " << intValue << "\n"
                  << "float: " << static_cast<float>(intValue) << ".0f\n"
                  << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
    }

bool isFloat(const std::string &value)
{
    if (value[value.size() - 1] != 'f')
        return false;
    
    std::string withoutF = value.substr(0, value.length() - 1);
    if (withoutF.empty())
        return false;
    
    int start = 0;
    bool hasDecimalPoint = false;
    
    if (withoutF[0] == '+' || withoutF[0] == '-')
        start = 1;
    
    if (start >= static_cast<int>(withoutF.length()))
        return false;

    for (int i = start; i < static_cast<int>(withoutF.length()); i++) {
        if (withoutF[i] == '.') {
            if (hasDecimalPoint) //more than 1 "."
                return false;
            hasDecimalPoint = true;
        }
        else if (!std::isdigit(withoutF[i])) {
            return false;
        }
    }

    return hasDecimalPoint;
}

void printFromFloat(const std::string &value)
{
    // remove f
    std::string withoutF = value.substr(0, value.length() - 1);

    float floatValue = std::strtof(withoutF.c_str(), NULL);
    
    
    // if printable and "full" for char
    if (floatValue >= 32.0f && floatValue <= 126.0f && floatValue == static_cast<int>(floatValue)) {
        std::cout << "char: '" << static_cast<char>(static_cast<int>(floatValue)) << "'\n";
    }
    else if (floatValue >= 0.0f && floatValue <= 127.0f && floatValue == static_cast<int>(floatValue)) {
        std::cout << "char: Non displayable\n";
    }
    else {
        std::cout << "char: impossible\n";
    }
    
    // for int
    if (floatValue > INT_MAX || floatValue < INT_MIN){
        std::cout << "int: impossible\n";
    }
    else {
        std::cout << "int: " << static_cast<int>(floatValue) << "\n";
    }
    
    // Float depending of full value or not
    if (floatValue == static_cast<int>(floatValue)) {
        std::cout << "float: " << floatValue << ".0f\n";
    }
    else {
        std::cout << "float: " << floatValue << "f\n";
    }
    
    // Double same as above
    double doubleValue = static_cast<double>(floatValue);
    if (doubleValue == static_cast<int>(doubleValue)) {
        std::cout << "double: " << doubleValue << ".0" << std::endl;
    }
    else {
        std::cout << "double: " << doubleValue << std::endl;
    }
        
}
// bool    isChar(const std::string &value)
// {

// }
void ScalarConverter::convert(const std::string &value)
{
    if (value.empty())
        return ;
    if (pseudoLiterals(value))
        return ;
    if (value.length() == 1 && !std::isdigit(value[0])){
        printFromChar(value[0]);
        return ;
    }
    if (isInteger(value)){
        printFromInt(value);
        return ;
    }
    if (isFloat(value)){
        printFromFloat(value);
        return ;
    }

    //if isdouble
    else
        std::cout<<"Error\n";
        
    return ;
    

}