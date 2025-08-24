/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:33:24 by elikavak          #+#    #+#             */
/*   Updated: 2025/08/21 17:35:46 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
   
}
Point::Point(const float x, const float y) : x(x), y(y)
{
}
Point::Point(const Point &num) : x(num.x), y(num.y)
{
}
Point& Point::operator =(const Point &num)
{
    (void)num;
    return *this;
}
Point::~Point()
{
    
}
float Point::getX() const
{
    return (x.toFloat());
}
float Point::getY() const
{
    return (y.toFloat());
}
