#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>

class PmergeMe
{
    private:
        template <typename T>
        void fordJohnsonSort(T &numbers)
        {
            if (numbers.size() <= 1)
                return;

            T bigger;
            T smaller;

            for (size_t i = 0; i < numbers.size(); i += 2)
            {
                if (i + 1 < numbers.size())
                {
                    if (numbers[i] > numbers[i + 1])
                    {
                        bigger.push_back(numbers[i]);
                        smaller.push_back(numbers[i + 1]);
                    }
                    else
                    {
                        bigger.push_back(numbers[i + 1]);
                        smaller.push_back(numbers[i]);
                    }
                }
                else
                    smaller.push_back(numbers[i]);
            }

            std::sort(bigger.begin(), bigger.end());

            for (size_t i = 0; i < smaller.size(); i++)
            {
                typename T::iterator pos;
                pos = std::lower_bound(bigger.begin(), bigger.end(), smaller[i]);
                bigger.insert(pos, smaller[i]);
            }

            numbers = bigger;
        }

        bool isPositiveInteger(const std::string &str);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void sortVector(int argc, char **argv);
        void sortDeque(int argc, char **argv);
};

#endif