#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    try 
    {
        std::cout << "--- Test 1 ---" << std::endl;
        Array<int> v1(3);
        v1[0] = 10;
        v1[1] = 20;
        v1[2] = 30;

        Array<int> v2 = v1;
        v2[0] = 999;

        std::cout << "Orijinal v1[0]: " << v1[0] << std::endl;
        std::cout << "Kopya v2[0]: " << v2[0] << std::endl;
        
        if (v1[0] != v2[0])
            std::cout << "BASARILI" << std::endl;
        else
            std::cout << "HATA" << std::endl;

        std::cout << "\n--- String Testi ---" << std::endl;
        Array<std::string> words(2);
        words[0] = "Elif";
        words[1] = "Ebrar";
        
        for (unsigned int i = 0; i < words.size(); i++)
        {
            std::cout << words[i] << std::endl;
        }

        std::cout << "\n--- Exception Test ---" << std::endl;
        std::cout << words[99] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Hata: " << e.what() << std::endl;
    }

    return 0;
}