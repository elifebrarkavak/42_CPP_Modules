/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:44:11 by elikavak          #+#    #+#             */
/*   Updated: 2025/07/02 21:44:11 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->name = "Default";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->damage = 20;
	std::cout<<"ScavTrap default constructor called"<<std::endl;
}
ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->damage = 20;
	std::cout<<"ScavTrap"<<this->name<< "constructor called"<<std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& copy)
{
	*this = copy;
	std::cout << "ScavTrap Copy Constructor Called" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	this->damage = other.damage;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	std::cout << "ScavTrap Copy Assignment Called" << std::endl;
	return *this;
}
ScavTrap::~ScavTrap()
{
	std::cout<<"ScavTrap Destructor Called!!"<<std::endl;
}
void ScavTrap::attack(const std::string& target)
{
	if (this->energyPoints < 0)
		std::cout<<"ScavTrap is named "<<this->name<< " dead."<<std::endl;
	else if (this->energyPoints == 0)
		std::cout<<"Energy is 0 so cannot atack."<<std::endl;
	else
	{
		std::cout <<"ScavTrap "<<this->name<<" attacks "<<target<<" , causing "<<this->damage<<" points of damage!"<<std::endl;
		this->energyPoints--;
	}
	return ;
}
void ScavTrap::guardGate()
{
	std::cout<<"ScavTrap is now in Gate keeper mode."<<std::endl;
}