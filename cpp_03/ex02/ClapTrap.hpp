/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:08:45 by elikavak          #+#    #+#             */
/*   Updated: 2025/08/24 11:10:38 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string name;
		unsigned int hitPoints; 
		int energyPoints;
		int damage;
	public:
		ClapTrap();                                 
		ClapTrap(const ClapTrap& copy);               
		ClapTrap& operator=(const ClapTrap& other);     
		~ClapTrap();                                    

		ClapTrap(std::string name);

		void attack(const std::string& target);
   		void takeDamage(unsigned int amount);
    	void beRepaired(unsigned int amount);

		int getHitPoints();
		int getEnergyPoints();
		int getDamage();
		std::string getName();
};

#endif