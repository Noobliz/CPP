#pragma once
# include <map>
# include <iostream>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _btcRates;

    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &fileName);
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void calculateValue(const std::string& inputName);

};