/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:17:35 by elikavak          #+#    #+#             */
/*   Updated: 2025/07/07 22:17:35 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
	std::cout<<"Default constructor called!!"<<std::endl;
}
Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
	std::cout<<"Copy constructor called!!"<<std::endl;
}
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->value = other.getRawBits();
	std::cout<<"Copy assignment operator called!!"<<std::endl;
	return *this;
}
Fixed::~Fixed()
{
	std::cout<<"Destructor called!!"<<std::endl;
}
int Fixed::getRawBits(void) const 
{
	std::cout<<"getRawBits member function called!!"<<std::endl;
	return this->value;
}
void Fixed::setRawBits(int const raw)
{
	this->value = raw;
	std::cout<<"setRawBits member functions called!!"<<std::endl;
}
Fixed::Fixed(const int val_int)
{
	this->value = val_int << this->bits;
	std::cout<<"Int constructor called!!"<<std::endl;
}
Fixed::Fixed(const float val_flo)
{
	this->value = roundf(val_flo *(1 << this->bits));
	std::cout<<"Float constructor called!!"<<std::endl;
}
float Fixed::toFloat(void) const 
{
    return this->value / FIXED_SCALE;
}
int Fixed::toInt(void) const 
{
    return this->value >> this->bits;
}
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) 
{
    os << fixed.toFloat();
    return os;
}