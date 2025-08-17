/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:28:16 by elikavak          #+#    #+#             */
/*   Updated: 2025/08/17 16:28:16 by elikavak         ###   ########.fr       */
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
        bool operator>(const Fixed& num) const;
        bool operator<(const Fixed& num) const;
        bool operator>=(const Fixed& num) const;
        bool operator<=(const Fixed& num) const;
        bool operator==(const Fixed& num) const;
        bool operator!=(const Fixed& num) const;
        Fixed operator+(const Fixed& num) const;
        Fixed operator-(const Fixed& num) const;
        Fixed operator*(const Fixed& num) const;
        Fixed operator/(const Fixed& num) const;
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        ~Fixed();
};

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed);

#endif