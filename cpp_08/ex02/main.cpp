#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "===== SUBJECT TEST =====" << std::endl;
    try
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;

        mstack.pop();

        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::stack<int> s(mstack);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n===== LIST COMPARISON =====" << std::endl;
    try
    {
        std::list<int> lst;

        lst.push_back(5);
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);

        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "List error: " << e.what() << std::endl;
    }

    std::cout << "\n===== REVERSE ITERATOR TEST =====" << std::endl;
    try
    {
        MutantStack<int> rev;

        rev.push(10);
        rev.push(20);
        rev.push(30);

        MutantStack<int>::reverse_iterator rit = rev.rbegin();
        MutantStack<int>::reverse_iterator rite = rev.rend();

        while (rit != rite)
        {
            std::cout << *rit << std::endl;
            ++rit;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Reverse error: " << e.what() << std::endl;
    }

    return 0;
}
