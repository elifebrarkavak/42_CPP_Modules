/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:08:53 by elikavak          #+#    #+#             */
/*   Updated: 2025/07/02 14:08:53 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "Default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->damage = 0;
	std::cout<<"ClapTrap Constructor Called!!"<<std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->damage = 0;
	std::cout<<this->name<<"ClapTrap Constructor Called!!"<<std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& copy)
{
	*this = copy;
	std::cout << "ClapTrap Copy Constructor Called" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	this->damage = other.damage;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	std::cout << "ClapTrap Copy Assignment Called" << std::endl;
	return *this;
}
ClapTrap::~ClapTrap()
{
	std::cout<<"ClapTrap Destructor Called!!"<<std::endl;
}
void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints < 0)
		std::cout<<"ClapTrap is named "<<this->name<< " dead."<<std::endl;
	else if (this->energyPoints == 0)
		std::cout<<"Energy is 0 so cannot atack."<<std::endl;
	else
	{
		std::cout <<"ClapTrap "<<this->name<<" attacks "<<target<<" , causing "<<this->damage<<" points of damage!"<<std::endl;
		this->energyPoints--;
	}
	return ;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints <= 0)
	{
		std::cout<<"ClapTrap is named "<<this->name<<" dead so cannot take damage."<<std::endl;
	}
	else
	{
		std::cout<<"ClapTrap "<<this->name<<" takes "<<amount<<" points of damage!"<<std::endl;
		this->hitPoints -= amount;
	}
	return ;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
	{
		std::cout<<"ClapTrap is dead so cannot get repaired"<<std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " repairing itself!!"<<std::endl;
		this->energyPoints--;
		this->hitPoints += amount;
		std::cout << "New HitPoints = " << this->hitPoints << std::endl;
	}
	return ;
}
int ClapTrap::getHitPoints(){
	return this->hitPoints;
}

int ClapTrap::getEnergyPoints(){
	return this->energyPoints;
}

int ClapTrap::getDamage()
{
	return this->damage;
}