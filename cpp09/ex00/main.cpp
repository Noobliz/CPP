#include "BitcoinExchange.hpp"

int main()
{
    BitcoinExchange btc;
    std::string fileName = "cpp_09/data.csv";

    try{
        
        btc.loadRates(fileName);
        btc.calculateValue("input.txt");
    }
    catch(std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }
}