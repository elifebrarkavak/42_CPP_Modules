#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>

int main()
{
    std::cout << "---- VECTOR TEST 1 ----" << std::endl;

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
        std::cout << "Vector ERROR: " << e.what() << std::endl;
    }

    std::cout << "\n---- VECTOR TEST 2 ----" << std::endl;

    try
    {
        easyfind(v, 99);
    }
    catch (std::exception &e)
    {
        std::cout << "Vector ERROR: " << e.what() << std::endl;
    }

    std::cout << "\n---- LIST TEST 1 ----" << std::endl;

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
        std::cout << "List ERROR: " << e.what() << std::endl;
    }

    std::cout << "\n---- LIST TEST 2 ----" << std::endl;
    
    try
    {
        easyfind(l, -1);
    }
    catch (std::exception &e)
    {
        std::cout << "List ERROR: " << e.what() << std::endl;
    }

    std::cout << "\n---- DEQUE TEST ----" << std::endl;

    std::deque<int> d;
    d.push_back(100);
    d.push_back(200);
    d.push_back(300);

    try
    {
        std::deque<int>::iterator it = easyfind(d, 300);
        std::cout << "Found in Deque: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Deque ERROR: " << e.what() << std::endl;
    }

    std::cout << "\n---- FORWARD_LIST TEST 1 ----" << std::endl;

    std::forward_list<int> fl;
    fl.push_front(21);
    fl.push_front(14);
    fl.push_front(7);

    try
    {
        std::forward_list<int>::iterator it = easyfind(fl, 14);
        std::cout << "Found in forward_list: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Forward_list ERROR: " << e.what() << std::endl;
    }

    std::cout << "\n---- FORWARD_LIST TEST 2 ----" << std::endl;

    try
    {
        easyfind(fl, 99);
    }
    catch (std::exception &e)
    {
        std::cout << "Forward_list ERROR: " << e.what() << std::endl;
    }

    std::cout << "\n---- EMPTY CONTAINER TEST ----" << std::endl;

    std::vector<int> empty;

    try
    {
        easyfind(empty, 1);
    }
    catch (std::exception &e)
    {
        std::cout << "Empty Container ERROR: " << e.what() << std::endl;
    }

    return 0;
}
