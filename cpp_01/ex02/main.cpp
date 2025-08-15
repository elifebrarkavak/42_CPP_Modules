/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 20:26:15 by elikavak          #+#    #+#             */
/*   Updated: 2025/06/27 11:10:12 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR;
	stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory address of the string variable     : " << &str << std::endl;
    std::cout << "The memory address held by stringPTR         : " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF         : " << &stringREF << std::endl;

    std::cout << "The value of the string variable              : " << str << std::endl;
    std::cout << "The value pointed to by stringPTR            : " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF            : " << stringREF << std::endl;
	
	return 0;
}