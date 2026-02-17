#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
    Array<int> empty;
    std::cout << "Empty size: " << empty.size() << std::endl;

    Array<int> numbers(5);
    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = i * 10;
    }

    std::cout << "Numbers: ";
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    try {
        Array<int> copy = numbers;
        copy[0] = 999;
        std::cout << "Original[0]: " << numbers[0] << " (should be 0)" << std::endl;
        std::cout << "Copy[0]: " << copy[0] << " (should be 999)" << std::endl;
        
        std::cout << "Testing out of bounds: " << std::endl;
        std::cout << numbers[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}