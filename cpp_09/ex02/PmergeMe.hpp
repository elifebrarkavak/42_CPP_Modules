#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <algorithm>
#include <iterator>

class PmergeMe
{
    private:
        template <typename T>
        void fordJohnsonSort(T &container);
        
        bool isPositiveInteger(const std::string &s);    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void sortVector(int argc, char **argv);
        void sortDeque(int argc, char **argv);
};

#endif