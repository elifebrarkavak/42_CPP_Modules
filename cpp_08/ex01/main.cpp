#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        Span bigSpan(15000);
        std::vector<int> v(15000);
        for (int i = 0; i < 15000; ++i) v[i] = i * 2;
        bigSpan.addNumbers(v.begin(), v.end());
        std::cout << "Big shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Big longest: " << bigSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}