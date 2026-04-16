#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{

    std::cout << "---- VECTOR TEST1 ----" << std::endl;

    std::vector<int> v;
    for (int i = 0; i < 5; i++)
        v.push_back(i * 10);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Found in vector: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Vector error: " << e.what() << std::endl;
    }
    std::cout << "\n---- VECTOR TEST2 ----" << std::endl;
    try
    {
        easyfind(v, 99);
    }
    catch (std::exception &e)
    {
        std::cout << "Vector error: " << e.what() << std::endl;
    }

    std::cout << "\n---- LIST TEST1 ----" << std::endl;

    std::list<int> l;
    l.push_back(5);
    l.push_back(15);
    l.push_back(25);

    try
    {
        std::list<int>::iterator it = easyfind(l, 15);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "List error: " << e.what() << std::endl;
    }
    std::cout << "\n---- LIST TEST2 ----" << std::endl;
    try
    {
        easyfind(l, -1);
    }
    catch (std::exception &e)
    {
        std::cout << "List error: " << e.what() << std::endl;
    }


    std::cout << "\n---- DEQUE TEST ----" << std::endl;

    std::deque<int> d;
    d.push_back(100);
    d.push_back(200);
    d.push_back(300);

    try
    {
        std::deque<int>::iterator it = easyfind(d, 300);
        std::cout << "Found in deque: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Deque error: " << e.what() << std::endl;
    }

    std::cout << "\n---- EMPTY CONTAINER TEST ----" << std::endl;

    std::vector<int> empty;

    try
    {
        easyfind(empty, 1);
    }
    catch (std::exception &e)
    {
        std::cout << "Empty container error: " << e.what() << std::endl;
    }


    return 0;
}