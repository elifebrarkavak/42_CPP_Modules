#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span& other) { *this = other; }

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->_n = other._n;
        this->_storage = other._storage;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_storage.size() >= _n)
        throw FullStorageException();
    _storage.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (_storage.size() + std::distance(begin, end) > _n)
        throw FullStorageException();
    _storage.insert(_storage.end(), begin, end);
}

unsigned int Span::shortestSpan() const {
    if (_storage.size() < 2)
        throw NoSpanException();
    
    std::vector<int> sorted = _storage;
    std::sort(sorted.begin(), sorted.end());
    
    unsigned int min = -1;
    for (size_t i = 0; i < sorted.size() - 1; ++i) {
        unsigned int diff = sorted[i + 1] - sorted[i];
        if (diff < min)
            min = diff;
    }
    return min;
}

unsigned int Span::longestSpan() const {
    if (_storage.size() < 2)
        throw NoSpanException();
    
    int min = *std::min_element(_storage.begin(), _storage.end());
    int max = *std::max_element(_storage.begin(), _storage.end());
    return max - min;
}