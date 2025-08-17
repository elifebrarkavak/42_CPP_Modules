/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:24:47 by elikavak          #+#    #+#             */
/*   Updated: 2025/08/17 16:24:47 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed()
{
    this->stored = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intNumber)
{
    std::cout << "Int constructor called" << std::endl;
    stored = intNumber << numberBit;
}

Fixed::Fixed(const float floatNumber)
{
    std::cout << "Float constructor called" << std::endl;
    stored = roundf(floatNumber * (1 << numberBit));
}

Fixed::Fixed(const Fixed& num) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = num;
}

Fixed& Fixed::operator=(const Fixed& num) 
{
    std::cout << "Copy assignment operator called" << std::endl;
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
    std::cout << "getRawBits member function called" << std::endl;
    return this->stored;
}

void Fixed::setRawBits(int const raw) 
{
    std::cout << "setRawBits member function called" << std::endl;
    this->stored = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed)
{
    ostream << fixed.toFloat();
    return ostream;
}