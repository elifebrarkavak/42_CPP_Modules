/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:18:52 by elikavak          #+#    #+#             */
/*   Updated: 2025/08/17 16:18:52 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->stored = 0;
    std::cout << "Default constructor called" << std::endl;
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
        this->stored = num.getRawBits();
    return *this;
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
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