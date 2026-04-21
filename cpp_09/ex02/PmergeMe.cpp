#include "PmergeMe.hpp"
#include <sys/time.h>
#include <cstdlib>

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}

bool PmergeMe::isPositiveInteger(const std::string &str)
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;
    }
    return true;
}

void PmergeMe::sortVector(int argc, char **argv)
{
    std::vector<int> v;
    struct timeval start, end;

    for (int i = 1; i < argc; i++)
    {
        if (!isPositiveInteger(argv[i]))
            throw std::runtime_error("Error");

        char *endptr;
        long value = std::strtol(argv[i], &endptr, 10);

        if (*endptr != '\0')
            throw std::runtime_error("Error");

        v.push_back(static_cast<int>(value));
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    gettimeofday(&start, NULL);
    fordJohnsonSort(v);
    gettimeofday(&end, NULL);

    std::cout << "After:  ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    double elapsed = (end.tv_sec - start.tv_sec) * 1e6
                   + (end.tv_usec - start.tv_usec);

    std::cout << "Time to process " << v.size()
              << " elements with std::vector : "
              << elapsed << " us" << std::endl;
}

void PmergeMe::sortDeque(int argc, char **argv)
{
    std::deque<int> d;
    struct timeval start, end;

    for (int i = 1; i < argc; i++)
    {
        if (!isPositiveInteger(argv[i]))
            throw std::runtime_error("Error");

        char *endptr;
        long value = std::strtol(argv[i], &endptr, 10);

        if (*endptr != '\0')
            throw std::runtime_error("Error");

        d.push_back(static_cast<int>(value));
    }

    gettimeofday(&start, NULL);
    fordJohnsonSort(d);
    gettimeofday(&end, NULL);

    double elapsed = (end.tv_sec - start.tv_sec) * 1e6
                   + (end.tv_usec - start.tv_usec);

    std::cout << "Time to process " << d.size()
              << " elements with std::deque  : "
              << elapsed << " us" << std::endl;
}
