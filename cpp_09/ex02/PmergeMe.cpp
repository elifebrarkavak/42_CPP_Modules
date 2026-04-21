#include "PmergeMe.hpp"

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
    struct timeval s, e;

    for (int i = 1; i < argc; i++)
    {
        if (!isPositiveInteger(argv[i]))
            throw std::runtime_error("Error!! Not Positive Integer");

        char *eptr;
        long value = std::strtol(argv[i], &eptr, 10);

        if (*eptr != '\0')
            throw std::runtime_error("Error!! Not a Valid Integer");

        v.push_back(static_cast<int>(value));
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    gettimeofday(&s, NULL);
    fordJohnsonSort(v);
    gettimeofday(&e, NULL);

    std::cout << "After:  ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    double exectime = (e.tv_sec - s.tv_sec) * 1e6
                   + (e.tv_usec - s.tv_usec);

    std::cout << "Time to process " << v.size()
              << " elements with std::vector : "
              << exectime << " us" << std::endl;
}

void PmergeMe::sortDeque(int argc, char **argv)
{
    std::deque<int> d;
    struct timeval s, e;

    for (int i = 1; i < argc; i++)
    {
        if (!isPositiveInteger(argv[i]))
            throw std::runtime_error("Error!! Not Positive Integer");

        char *eptr;
        long value = std::strtol(argv[i], &eptr, 10);

        if (*eptr != '\0')
            throw std::runtime_error("Error!! Not a Valid Integer");

        d.push_back(static_cast<int>(value));
    }

    gettimeofday(&s, NULL);
    fordJohnsonSort(d);
    gettimeofday(&e, NULL);

    double exectime = (e.tv_sec - s.tv_sec) * 1e6
                   + (e.tv_usec - s.tv_usec);

    std::cout << "Time to process " << d.size()
              << " elements with std::deque  : "
              << exectime << " us" << std::endl;
}
