#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    try {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        std::cout << *easyfind(v, 2) << std::endl;

        std::list<int> l;
        l.push_back(10);
        l.push_back(20);
        std::cout << *easyfind(l, 20) << std::endl;

        easyfind(v, 42);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}