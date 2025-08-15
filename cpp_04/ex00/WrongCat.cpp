/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 00:15:33 by elikavak          #+#    #+#             */
/*   Updated: 2025/07/04 00:15:33 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "Default";
	std::cout<<"WrongCat default constructor called!!"<<std::endl;
}
WrongCat::WrongCat(const WrongCat& copy)
{
	*this = copy;
	std::cout<<"WrongCat copy constructor called!!"<<std::endl;
}
WrongCat::~WrongCat()
{
	std::cout<<"WrongCat destructor is called!!"<<std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat assignment operator called." << std::endl;
	this->type = other.type;
	return *this;
}

void WrongCat::makeSound()
{
	std::cout<< "Meow but somethings wrond!!"<<std::endl;
}