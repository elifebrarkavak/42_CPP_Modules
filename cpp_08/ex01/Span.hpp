#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>

class Span {
private:
    unsigned int _n;
    std::vector<int> _storage;
    Span();

public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    class FullStorageException : public std::exception {
        virtual const char* what() const throw() { return "Storage is full"; }
    };

    class NoSpanException : public std::exception {
        virtual const char* what() const throw() { return "Not enough numbers to find a span"; }
    };
};

#endif