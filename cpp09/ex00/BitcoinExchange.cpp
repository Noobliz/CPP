#include "BitcoinExchange.hpp"
#include <fstream>
#include <exception>
#include <stdlib.h>
#include <string.h>
#include <sstream>

void    BitcoinExchange::loadRates(const std::string& fileName)
{
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
        throw std::runtime_error("open failed");
    std::string line;
    std::getline(file, line);
    while(std::getline(file, line))
    {
        if (line.empty())
            continue;
        size_t sep = line.find(',');
        if (sep == std::string::npos)
        {
            std::cerr<<"missing ',' : line ignored"<<std::endl;
            continue;
        }
        std::string date = line.substr(0, sep);
        std::string rateString = line.substr(sep + 1, line.length());

        char *endptr = NULL;
        float rate = strtof(rateString.c_str(), &endptr);
        if (endptr == rateString || *endptr != '\0')
        {
            std::cerr<<"invalid float for "<<date<<std::endl;
            continue;
        }
        _btcRates[date] = rate;
    }
    //test
    // for (std::map<std::string, float>::iterator it = _btcRates.begin(); it != _btcRates.end(); ++it)
    //     std::cout << it->first << " => " << it->second << "\n";
}


// int countWhiteSpaceL(std::string str)
// {
//     size_t start = 0;
//     while (start < str.length() && std::isspace(static_cast<unsigned char>(str[start])))
//         ++start;
//     return start;
// }
// int countWhiteSpaceR(std::string str)
// {
//     int end = str.length() - 1;
//     int count = 0;
//     while (std::isspace(static_cast<unsigned char>(str[end])))
//     {
//         --end;
//         ++count;
//     }
//     return count;
// }




std::string trim(const std::string &s) {
    size_t start = 0;
    while (start < s.length() && std::isspace(static_cast<unsigned char>(s[start])))
        ++start;

    if (start == s.length())
        return "";

    size_t end = s.length() - 1;
    while (end > start && std::isspace(static_cast<unsigned char>(s[end])))
        --end;

    return s.substr(start, end - start + 1);
}


void BitcoinExchange::calculateValue(const std::string &inputName)
{
    std::ifstream input(inputName.c_str());
    if (!input.is_open())
        throw std::runtime_error("open failed");
    std::string line;

    //first line
    if (!std::getline(input, line))
        throw std::runtime_error("file is empty");
    if (line != "date | value" || line.empty())
        std::cerr<<"input file should start with 'date | value' : ignoring line"<<std::endl;
    
    while (std::getline(input, line))
    {
        if (line.empty())
            continue;

        size_t sep = line.find('|');
        if (sep == std::string::npos) {
            std::cerr <<"Error: bad format line"<<std::endl;
            continue;
        }

        //trim whitespaces
        std::string date = trim(line.substr(0, sep));
        std::string valueStr = trim(line.substr(sep + 1, line.length()));

        //parsing value
        char *endptr = NULL;
        float value = std::strtof(valueStr.c_str(), &endptr);
        if (endptr == valueStr.c_str() || *endptr != '\0' || value < 0 || value > 1000) {
            std::cerr << "Error: invalid value\n";
            continue;
        }
        
        std::cout << "[" << date << "] => [" << valueStr << "]\n"; // test for trim

        //parsing date
        //line lenght = 10
        // 2 '-'
        //4 digits, 2 digits, 2digits
        //year = >2008 | month = >00 && <= 12 || days = >0 && < 30 or 31 or (feb:28 or 29)
        //
    }

}