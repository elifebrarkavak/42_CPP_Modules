/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:35:19 by elikavak          #+#    #+#             */
/*   Updated: 2025/07/03 23:35:19 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Default";
	std::cout<<"Dog default constructor called!!"<<std::endl;
}
Dog::Dog(const Dog& copy)
{
	*this = copy;
	std::cout<<"Dog copy constructor called!!"<<std::endl;
}
Dog::~Dog()
{
	std::cout<<"Dog destructor is called!!"<<std::endl;
}
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called." << std::endl;
	this->type = other.type;
	return *this;
}

void Dog::makeSound()
{
	std::cout<< "Wooff!!"<<std::endl;
}