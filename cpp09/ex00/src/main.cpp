#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        if (argc < 2)
            std::cerr<<"could not open file"<<std::endl;
        else
            std::cerr<<"input exactly 1 file"<<std::endl;
        return (1);
    }
    std::string fileName = "data.csv";
    
    try{
        BitcoinExchange btc(fileName);
        btc.calculateValue(argv[1]);
    }
    catch(std::exception &e)
    {
        std::cerr<<e.what()<<std::endl;
    }
}