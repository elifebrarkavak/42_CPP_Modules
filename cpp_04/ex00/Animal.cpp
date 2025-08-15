/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:35:22 by elikavak          #+#    #+#             */
/*   Updated: 2025/07/03 23:35:22 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Default";
	std::cout<<"Animal default constructor called!!"<<std::endl;
}
Animal::Animal(const Animal& copy)
{
	*this = copy;
	std::cout<<"Animal copy constructor called!!"<<std::endl;
}
Animal::~Animal()
{
	std::cout<<"Animal destructor is called!!"<<std::endl;
}
Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignment operator called." << std::endl;
	this->type = other.type;
	return *this;
}

std::string Animal::getType()
{
	return this->type;
}

void Animal::makeSound()
{
	std::cout<< "Animal makes a sound!!"<<std::endl;
}