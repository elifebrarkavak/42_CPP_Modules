/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:08:53 by elikavak          #+#    #+#             */
/*   Updated: 2025/07/15 22:08:53 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "Default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->damage = 0;
	std::cout << "Default constructor called for ClapTrap " << this->name << std::endl;
}
ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->damage = 0;
	std::cout << "Constructor called for ClapTrap " << this->name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	*this = copy;
	std::cout << "Copy constructor called for ClapTrap " << this->name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->damage = other.damage;
	}
	std::cout << "Copy assignment operator called for ClapTrap " << this->name << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for ClapTrap " << this->name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead and can't attack." << std::endl;
	}
	else if (this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy to attack." << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount == 0)
    {
        std::cout << "Claptrap " << this->name << " no damage" << std::endl;
        return ;
    }
    else if (this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is 0 hitpoint now" << std::endl;
        return ;
    }
    else if (amount >= (unsigned int)this->hitPoints)
        this->hitPoints = 0;
    else
        this->hitPoints -= amount;
    std::cout << "ClapTrap " << this->name <<  " takes " << amount<< " damage"
    << " also " << this->name << " has " << this->hitPoints << " hitPoint now" <<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0 || energyPoints <= 0 || amount == 0)
    {
        std::cout << "ClapTrap " << this->name <<  " can not repair" << std::endl;
    }
	else
	{
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " repairs itself for " << amount  << " hit points! New HP: " << this->hitPoints << std::endl;
	}
}

int ClapTrap::getHitPoints()
{
	return this->hitPoints;
}

int ClapTrap::getEnergyPoints() 
{
	return this->energyPoints;
}

int ClapTrap::getDamage() 
{
	return this->damage;
}

std::string ClapTrap::getName() 
{
    return (this->name);
}
