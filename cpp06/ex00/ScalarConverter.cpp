#include "ScalarConverter.hpp"
#include <vector>


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
    std::string pseudoLiteralsF[]
    {
        {"-inff"},
        {"+inff"},
        {"nanf"}
    };
    std::string pseudoLiteralsD[]
    {
        {"-inf"},
        {"+inf"},
        {"nan"}
    };
    for (int i = 0; i < 3; i++)
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
        if (type == "double")
        {
            std::cout<<"float : "<<value + "f"<<"\n"
                    <<"double : "<<value<<std::endl;
        }
        else
        {
            std::cout<<"float : "<<value<<"\n"
                    <<"double : "<<value.substr(0, value.size() -1)<<std::endl; //remove 2nd f
        }
        return 1;
    }
    return 0;
}
void ScalarConverter::convert(const std::string &value)
{
    if (pseudoLiterals(value))
        return ;
}