#include "PmergeMe.hpp"
#include <sys/time.h> // gettimeofday için gerekli

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other) { (void)other; return *this; }

bool PmergeMe::isPositiveInteger(const std::string &s) {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.length(); i++)
        if (!isdigit(s[i])) return false;
    return true;
}

template <typename T>
void PmergeMe::fordJohnsonSort(T &c) {
    if (c.size() <= 1) return;

    T mainChain;
    T pend;
    
    for (size_t i = 0; i < c.size(); i += 2) {
        if (i + 1 < c.size()) {
            if (c[i] > c[i + 1]) {
                mainChain.push_back(c[i]);
                pend.push_back(c[i + 1]);
            } else {
                mainChain.push_back(c[i + 1]);
                pend.push_back(c[i]);
            }
        } else {
            pend.push_back(c[i]);
        }
    }

    std::sort(mainChain.begin(), mainChain.end());

    for (size_t i = 0; i < pend.size(); i++) {
        typename T::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
        mainChain.insert(it, pend[i]);
    }
    c = mainChain;
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