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

FragTrap::FragTrap() : ClapTrap()
{
	this->name = "Default";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->damage = 30;
	std::cout<<"FragTrap default constructor called"<<std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->damage = 30;
	std::cout<<"FragTrap "<<this->name<< " constructor called"<<std::endl;
}
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap Copy Constructor Called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) 
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->damage = other.damage;
    }
    std::cout << "FragTrap Copy assignment called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
	std::cout<<" FragTrap Destructor Called!!"<<std::endl;
}
void FragTrap::highFivesGuys(void)
{
	std::cout<<"FragTrap "<<this->name<<" requests a positive high five!"<<std::endl;
}

//atackt?