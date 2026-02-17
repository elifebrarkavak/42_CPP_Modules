#include "iter.hpp"

template <typename T>

void printElement(T &content) 
{
    std::cout << content << " ";
}

template <typename T>
void printElementConst(const T &content) 
{
    std::cout << content << " ";
}

int main(void) 
{
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Int Array: ";
    ::iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    std::string strArray[] = {"Bilisim", "Vadisi", "42", "Turkiye"};
    std::cout << "String Array: ";
    ::iter(strArray, 4, printElement<std::string>);
    std::cout << std::endl;

    const int constArray[] = {10, 20, 30};
    std::cout << "Const Int Array: ";
    ::iter(constArray, 3, printElementConst<int>);
    std::cout << std::endl;

    return 0;
}