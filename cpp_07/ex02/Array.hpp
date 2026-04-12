#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
    private:
        T* _data;
        unsigned int _size;

    public:
        Array() : _data(NULL), _size(0)
        {

        }

        Array(unsigned int n) : _size(n)
        {
            if (n == 0)
                _data = NULL;
            else
                _data = new T[n]();
        }

        Array(const Array &other) : _data(NULL), _size(0)
        {
            *this = other;
        }

        ~Array()
        {
            delete[] _data;
        }

        Array &operator=(const Array &other)
        {
            if (this != &other)
            {
                delete[] _data;
                _size = other._size;

                if (_size == 0)
                    _data = NULL;
                else
                {
                    _data = new T[_size];
                    for (unsigned int i = 0; i < _size; i++)
                        _data[i] = other._data[i];
                }
            }
            return *this;
        }

        T &operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::exception();
            return _data[index];
        }

        unsigned int size() const
        {
            return _size;
        }
};

#endif