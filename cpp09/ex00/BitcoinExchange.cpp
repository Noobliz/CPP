#include "BitcoinExchange.hpp"
#include <fstream>
#include <exception>
#include <stdlib.h>
#include <string.h>
#include <sstream>

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy){
    *this = copy;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _btcRates = other._btcRates;

    return *this;
}
BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const std::string &fileName)
{
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
        throw std::runtime_error("open failed");
    std::string line;
    if (!std::getline(file, line))
        throw std::runtime_error("file is empty");
    int check = 0;
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
        if (endptr == rateString || *endptr != '\0' || rate < 0)
        {
            std::cerr<<"invalid float for "<<date<<std::endl;
            continue;
        }
        _btcRates[date] = rate;
        ++check;
    }
    if (check == 0)
        throw std::runtime_error("database is not exploitable");
}


static std::string trim(const std::string &s) {
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


static bool isValidFormat(const std::string &date, int &year, int &month, int &day)
{
    std::istringstream iss(date);
    char dash1, dash2;
    int countDash = 0;
    if (date.length() > 10)
        return false;
    for (size_t i = 0; i < date.length(); ++i)
    {
        if (date[i] == '-')
        {
            countDash++;
            size_t j = i + 1;
            while (date[j] && date[j] != '-')
                j++;
            if (j != i + 3)//checking if month/day is "XX" and not "X"
                return false;
        }
    }
    if (countDash != 2)
        return false;
    if (!(iss >> year >> dash1 >> month >> dash2 >> day))
    {
        return false;
    }
    if (dash1 != '-' || dash2 != '-')
    {
        return false;
    }
    return true;
}

static bool isValdiDate(int year, int month, int day)
{
    int daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool exception = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)); //leap year
    if (exception)
        daysPerMonth[2] = 29;
    return (month >= 1 && month <= 12 && day >= 1 && day <= daysPerMonth[month]);
}

void BitcoinExchange::calculateValue(const std::string &inputName)
{
    if (_btcRates.empty())
        return ;
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
            std::cerr << "Error: invalid value : "<<valueStr<<std::endl;
            continue;
        }
        
        //====parsing date=====
        int y, m, d = 0;
        if (!isValidFormat(date, y, m, d) || !isValdiDate(y, m, d))
        {
            std::cerr<<"Error: invalid (date), ignoring"<<std::endl;
            continue;
        }
        std::map<std::string, float>::iterator it = _btcRates.lower_bound(date);
        if (it == _btcRates.end() || it->first != date)
        {
            if (it == _btcRates.begin())
             {
                std::cerr << "Error: date too early"<<std::endl;
                continue;
            }
            --it;
        }
        float result = value * it->second;
        std::cout<<date <<" => "<<value<<" = " <<result<< std::endl;
    }
}
