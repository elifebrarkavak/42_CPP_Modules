/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:19:20 by elikavak          #+#    #+#             */
/*   Updated: 2025/08/21 17:36:54 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) 
{
    Fixed e;
    Fixed b(e);
    Fixed r;
    
    r = b;
    std::cout << e.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << r.getRawBits() << std::endl;

    return 0;
}
