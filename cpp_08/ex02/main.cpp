#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "--- List comparison test ---" << std::endl;
    std::list<int> l;
    l.push_back(5);
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    l.push_back(0);
    std::list<int>::iterator lit = l.begin();
    while (lit != l.end()) {
        std::cout << *lit << std::endl;
        ++lit;
    }
    return 0;
}