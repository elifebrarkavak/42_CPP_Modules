/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:35:17 by elikavak          #+#    #+#             */
/*   Updated: 2025/07/03 23:35:17 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Default";
	std::cout<<"Cat default constructor called!!"<<std::endl;
}
Cat::Cat(const Cat& copy)
{
	*this = copy;
	std::cout<<"Cat copy constructor called!!"<<std::endl;
}
Cat::~Cat()
{
	std::cout<<"Cat destructor is called!!"<<std::endl;
}
Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called." << std::endl;
	this->type = other.type;
	return *this;
}

void Cat::makeSound()
{
	std::cout<< "Meow!!"<<std::endl;
}