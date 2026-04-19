#include "Span.hpp"
#include <list>

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

        big.addNumber_Iterator (v.begin(), v.end());

        std::cout << "Big shortest: " << big.shortestSpan() << std::endl;
        std::cout << "Big longest : " << big.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Big error: " << e.what() << std::endl;
    }


    std::cout << "\n===== LIST TEST =====" << std::endl;

    try
    {
        Span other(5);
        std::list<int> l;

        l.push_back(42);
        l.push_back(7);
        l.push_back(19);
        l.push_back(3);
        l.push_back(11);

        other.addNumber_Iterator(l.begin(), l.end());

        std::cout << "List shortest: " << other.shortestSpan() << std::endl;
        std::cout << "List longest : " << other.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "List range error: " << e.what() << std::endl;
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
