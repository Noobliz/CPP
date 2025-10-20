#pragma once
# include <map>
# include <iostream>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _btcRates;

    public:
        void loadRates(const std::string& fileName);
        void calculateValue(const std::string& inputName);

};