/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:08:22 by elikavak          #+#    #+#             */
/*   Updated: 2025/07/03 22:08:22 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() { //değiştir
    std::cout << "\n--- Creating DiamondTrap ---\n";
    DiamondTrap d("Eda");

    d.attack("Monster");
    d.takeDamage(40);
    d.beRepaired(20);
    d.highFivesGuys();
    d.guardGate();
    d.whoAmI();

    std::cout << "\n--- End of Program ---\n";
    return 0;
}
