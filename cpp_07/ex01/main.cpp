#include <iostream>
#include "iter.hpp"

void multi_by_5_printConst(const int &x)
{
    std::cout << x * 5 << " ";
}

void toUpper_and_Print(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
        std::cout << (char)std::toupper(str[i]);
    std::cout << " ";
}

int main()
{
    std::cout <<"---------------------------INTEGER TESTS---------------------------" <<std::endl;
    int arr[] = {2, 5, 10, 3};
    std::cout << "Multiplied by 5 int array: ";
    ::iter(arr, 4, multi_by_5_printConst);
    std::cout << std::endl;

    const int carr[] = {5, 6, 7};
    std::cout << "Multiplied by 5 const int array: ";
    ::iter(carr, 3, multi_by_5_printConst);
    std::cout << std::endl;
    std::cout <<"---------------------------STRING TESTS---------------------------" <<std::endl;
    std::string strs[] = {"EbRar", "ElIf", "kaVak"};
    std::cout << "String Uppercase: ";
    ::iter(strs, 3, toUpper_and_Print);
    std::cout << std::endl;

    const std::string str[] = {"Beyza", "KaradAg", "IsTanbul"};
    std::cout << "Const String Uppercase: ";
    ::iter(str, 3, toUpper_and_Print);

    std::cout << std::endl;

    return 0;
}
