#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void loadDatabase(const std::string& path);
        void execute(const std::string& input);
        bool validateDate(const std::string& date);
        bool validateValue(const std::string& valueStr, float& value);
        bool validateInput(const std::string& date, const std::string& valueStr, float& value);
};

#endif
