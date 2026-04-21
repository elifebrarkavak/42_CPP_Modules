#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error!! Invalid argc count" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe p;
        p.sortVector(argc, argv);
        p.sortDeque(argc, argv);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}