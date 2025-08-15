/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:44:26 by elikavak          #+#    #+#             */
/*   Updated: 2025/07/03 21:44:26 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->name = "Default";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->damage = 30;
	std::cout<<"FragTrap default constructor called"<<std::endl;
}
FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->damage = 30;
	std::cout<<"FragTrap"<<this->name<< "constructor called"<<std::endl;
}
FragTrap::FragTrap(const FragTrap& copy)
{
	*this = copy;
	std::cout << "FragTrap Copy Constructor Called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	this->damage = other.damage;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	std::cout << "FragTrap Copy Assignment Called" << std::endl;
	return *this;
}
FragTrap::~FragTrap()
{
	std::cout<<" FragTrap Destructor Called!!"<<std::endl;
}
void FragTrap::highFivesGuys(void)
{
	std::cout<<"FragTrap"<<this->name<<"requests a positive high five!"<<std::endl;
}