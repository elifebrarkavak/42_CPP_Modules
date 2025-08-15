/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:24:44 by elikavak          #+#    #+#             */
/*   Updated: 2025/07/07 22:24:44 by elikavak         ###   ########.fr       */
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