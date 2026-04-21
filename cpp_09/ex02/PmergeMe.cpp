#include "PmergeMe.hpp"
#include <sys/time.h> // gettimeofday için gerekli

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

void PmergeMe::sortVector(int argc, char **argv) {
    std::vector<int> v;
    struct timeval start, end;

    // Zaman ölçümü verilerin işlenmesiyle başlar 
    gettimeofday(&start, NULL);
    for (int i = 1; i < argc; i++) {
        if (!isPositiveInteger(argv[i])) throw std::runtime_error("Error");
        v.push_back(std::atoi(argv[i]));
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    fordJohnsonSort(v);
    gettimeofday(&end, NULL);

    std::cout << "After:  ";
    for (size_t i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    // Mikro saniye hesaplama
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds * 1e6 + microseconds;

    std::cout << "Time to process " << v.size() << " elements with std::vector : " << elapsed << " us" << std::endl;
}

void PmergeMe::sortDeque(int argc, char **argv) {
    std::deque<int> d;
    struct timeval start, end;

    gettimeofday(&start, NULL);
    for (int i = 1; i < argc; i++) {
        d.push_back(std::atoi(argv[i]));
    }

    fordJohnsonSort(d);
    gettimeofday(&end, NULL);

    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds * 1e6 + microseconds;

    std::cout << "Time to process " << d.size() << " elements with std::deque  : " << elapsed << " us" << std::endl;
}