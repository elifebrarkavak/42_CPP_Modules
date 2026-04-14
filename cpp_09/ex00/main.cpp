#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error! File is wrong." << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    btc.loadDatabase("data.csv");
    btc.execute(argv[1]);

    return 0;
}