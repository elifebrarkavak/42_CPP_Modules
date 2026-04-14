#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{ 
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        this->_data = other._data;
    return *this;
}

void BitcoinExchange::loadDatabase(const std::string& path)
{
    std::ifstream file(path.c_str());
    if (!file.is_open())
    {
        std::cerr << "ERROR! Not Open DB File." << std::endl;
        exit(1);
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t comma = line.find(',');
        if (comma != std::string::npos)
        {
            std::string date = line.substr(0, comma);
            float rate = std::atof(line.substr(comma + 1).c_str());
            _data[date] = rate;
        }
    }
    file.close();
}

bool BitcoinExchange::validateInput(const std::string& date, const std::string& valueStr, float& value)
{

    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            return false;
        }
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    if (month == 2 && day > 29)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    char* end;
    value = std::strtof(valueStr.c_str(), &end);

    if (*end != '\0' && !isspace(*end))
    {
        std::cout << "Error: bad input => " << valueStr << std::endl;
        return false;
    }

    if (value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl; 
        return false;
    }

    if (value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl; 
        return false;
    }

    return true;
}

void BitcoinExchange::execute(const std::string& inputPath)
{
    std::ifstream file(inputPath.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t pipe = line.find('|');
        if (pipe == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipe - 1);
        std::string valueStr = line.substr(pipe + 1);
        float value;

        if (validateInput(date, valueStr, value))
        {
            std::map<std::string, float>::iterator it = _data.upper_bound(date);
            if (it != _data.begin())
            {
                --it;
                std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
            } 
            else
            {
                std::cout << "Error: date too early." << std::endl;
            }
        }
    }
}
