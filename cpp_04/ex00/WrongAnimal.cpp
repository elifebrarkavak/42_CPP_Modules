/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 00:12:20 by elikavak          #+#    #+#             */
/*   Updated: 2025/07/04 00:12:20 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "Default";
	std::cout<<"WrongAnimal default constructor called!!"<<std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	*this = copy;
	std::cout<<"WrongAnimal copy constructor called!!"<<std::endl;
}
WrongAnimal::~WrongAnimal()
{
	std::cout<<"WrongAnimal destructor is called!!"<<std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal assignment operator called." << std::endl;
	this->type = other.type;
	return *this;
}

std::string WrongAnimal::getType()
{
	return this->type;
}

void WrongAnimal::makeSound()
{
	std::cout<< "WrongAnimal makes a sound but somethings weird!!"<<std::endl;
}