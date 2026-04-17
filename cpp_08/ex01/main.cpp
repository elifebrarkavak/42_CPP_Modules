#include "Span.hpp"

int main()
{
    std::cout << "===== BASIC TEST =====" << std::endl;
    try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest : " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Basic error: " << e.what() << std::endl;
    }

    std::cout << "\n===== BIG TEST =====" << std::endl;
    try
    {
        Span big(15000);
        std::vector<int> v(15000);

        for (int i = 0; i < 15000; i++)
            v[i] = i * i;

        big.addNumber_Itarator(v.begin(), v.end());

        std::cout << "Big shortest: " << big.shortestSpan() << std::endl;
        std::cout << "Big longest : " << big.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Big error: " << e.what() << std::endl;
    }

    std::cout << "\n===== OVERFLOW TEST =====" << std::endl;
    try
    {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
    }
    catch (const std::exception& e)
    {
        std::cout << "Overflow error: " << e.what() << std::endl;
    }

    return 0;
}
