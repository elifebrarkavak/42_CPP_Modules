#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base* generate(void) 
{
    int i = std::rand() % 3;

    if (i == 0) 
    {
        return new A;
    } 
    else if (i == 1) 
    {
        return new B;
    } 
    else 
    {
        return new C;
    }
}

void identify(Base* p) 
{
    if (dynamic_cast<A*>(p)) 
    {
        std::cout << "A" << std::endl;
    } 
    else if (dynamic_cast<B*>(p)) 
    {
        std::cout << "B" << std::endl;
    } 
    else if (dynamic_cast<C*>(p)) 
    {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) 
{
    try 
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } 
    catch (const std::exception& e) 
    {
        (void)e;
    }

    try 
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } 
    catch (const std::exception& e) 
    {
        (void)e;
    }

    try 
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } 
    catch (const std::exception& e) 
    {
        (void)e;
    }
}

int main()
{
    std::srand(std::time(0));

    Base* ptr = generate();
    if (ptr == NULL) 
    {
        std::cout << "Error: Failed to generate an object!!!" << std::endl;
        return 1;
    }   
    
    identify(ptr);
    identify(*ptr);

    delete ptr;
    return 0;
}