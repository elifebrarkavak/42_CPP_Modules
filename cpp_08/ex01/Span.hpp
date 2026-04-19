#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>

class Span
{
    private:
        unsigned int        maxSize;
        std::vector<int>    numbers;
        Span();

    public:
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);

        template <typename Iterator>
        void addNumber_Iterator(Iterator begin, Iterator end)
        {
            if (numbers.size() + static_cast<unsigned int>(std::distance(begin, end)) > maxSize)
                throw std::runtime_error("Storage is full");

            numbers.insert(numbers.end(), begin, end);
        }

        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};

#endif