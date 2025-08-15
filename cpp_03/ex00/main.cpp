/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:11:46 by elikavak          #+#    #+#             */
/*   Updated: 2025/07/15 22:11:46 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap c1;
	ClapTrap c2(c1);

	ClapTrap c4("ebrar");
	ClapTrap c3 = c4;

	c3.attack(c1.getName());
	c1.takeDamage(c3.getEnergyPoints());
	c1.beRepaired(1);
	c1.attack(c3.getName());
}
