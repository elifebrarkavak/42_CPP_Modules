#include "Span.hpp"

Span::Span(unsigned int n) : maxSize(n)
{

}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->maxSize = other.maxSize;
        this->numbers = other.numbers;
    }
    return *this;
}

Span::~Span()
{

}

void Span::addNumber(int number)
{
    if (numbers.size() >= maxSize)
        throw std::runtime_error("Storage is full");

    numbers.push_back(number);
}

unsigned int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());

    return static_cast<unsigned int>(max - min);
}

unsigned int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    std::vector<int> tmp(numbers);

    std::sort(tmp.begin(), tmp.end());

    unsigned int min = static_cast<unsigned int>(tmp[1] - tmp[0]);

    for (size_t i = 1; i < tmp.size() - 1; i++)
    {
        unsigned int difference = static_cast<unsigned int>(tmp[i + 1] - tmp[i]);
        if (difference < min)
            min = difference;
    }

    return min;
}
