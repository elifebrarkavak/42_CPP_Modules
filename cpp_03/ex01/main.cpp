/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:08:51 by elikavak          #+#    #+#             */
/*   Updated: 2025/07/02 14:08:51 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap s1;
    ScavTrap s2(s1);

    ScavTrap s3("ebrar");
    ScavTrap s4 = s3;

    s1.attack(s3.getName());
    s3.takeDamage(s1.getEnergyPoints());
    s1.beRepaired(22);
    s1.guardGate();
}