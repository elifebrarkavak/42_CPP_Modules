/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:29:26 by elikavak          #+#    #+#             */
/*   Updated: 2025/08/18 17:16:34 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main()
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    Point inside(5.0f, 5.0f);
    Point outside(11.0f, 5.0f);
    Point edge(5.0f, 0.0f);

    std::cout << "Inside test:  " 
              << (bsp(a, b, c, inside) ? "YES" : "NO") << std::endl;

    std::cout << "Outside test: " 
              << (bsp(a, b, c, outside) ? "YES" : "NO") << std::endl;

    std::cout << "Edge test:    " 
              << (bsp(a, b, c, edge) ? "YES" : "NO") << std::endl;

    return 0;
}
