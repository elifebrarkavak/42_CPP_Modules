/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:24:45 by elikavak          #+#    #+#             */
/*   Updated: 2025/08/17 16:24:45 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int stored;
        static const int numberBit = 8;

    public:

        Fixed();
        Fixed(const int intNumber);
        Fixed(const float floatNumber);
        Fixed(const Fixed &num);

        Fixed& operator =(const Fixed &num);

        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        ~Fixed();

};

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed);

#endif