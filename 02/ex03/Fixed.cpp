/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:29:29 by elikavak          #+#    #+#             */
/*   Updated: 2025/08/18 17:20:27 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->stored = 0;
}

Fixed::Fixed(const int intNumber)
{
    stored = intNumber << numberBit;
}

Fixed::Fixed(const float floatNumber)
{
    stored = roundf(floatNumber * (1 << numberBit));
}

Fixed::Fixed(const Fixed& num) 
{
    *this = num;
}

Fixed& Fixed::operator=(const Fixed& num) 
{
    if (this != &num)
        this->stored = num.stored;
    return *this;
}

float Fixed::toFloat( void ) const
{
    return ((float)stored / (1 << numberBit));
}

int Fixed::toInt( void ) const
{
    return (stored >> 8);
}

int Fixed::getRawBits(void) const 
{
    return this->stored;
}

void Fixed::setRawBits(int const raw) 
{
    this->stored = raw;
}

bool Fixed::operator>(const Fixed& num) const
{
    return (this->stored > num.stored);
}

bool Fixed::operator<(const Fixed& num) const
{
    return (this->stored < num.stored);
}

bool Fixed::operator>=(const Fixed& num) const
{
    return (this->stored >= num.stored);
}

bool Fixed::operator<=(const Fixed& num) const
{
    return (this->stored <= num.stored);
}

bool Fixed::operator==(const Fixed& num) const
{
    return (this->stored == num.stored);
}

bool Fixed::operator!=(const Fixed& num) const
{
    return (this->stored != num.stored);
}

Fixed Fixed::operator+(const Fixed& num) const
{
    return (Fixed(this->toFloat() + num.toFloat()));
}

Fixed Fixed::operator-(const Fixed& num) const
{
    return (Fixed(this->toFloat() - num.toFloat()));
}

Fixed Fixed::operator*(const Fixed& num) const
{
    return (Fixed(this->toFloat() * num.toFloat()));
}

Fixed Fixed::operator/(const Fixed& num) const
{
    return (Fixed(this->toFloat() / num.toFloat()));
}

Fixed& Fixed::operator++()
{
    stored++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    stored++;
    return temp;
}

Fixed& Fixed::operator--()
{
    stored--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    stored--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

Fixed::~Fixed()
{
    
}

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed)
{
    ostream << fixed.toFloat();
    return ostream;
}