#pragma once
# include <map>
# include <iostream>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _btcRates;

        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &other);
    public:
        BitcoinExchange(const std::string &fileName);
        ~BitcoinExchange();

        void calculateValue(const std::string& inputName);

};