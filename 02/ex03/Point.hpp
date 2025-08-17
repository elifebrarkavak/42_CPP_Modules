/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:33:39 by elikavak          #+#    #+#             */
/*   Updated: 2025/08/17 16:33:39 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &num);
        Point& operator =(const Point &num);
        ~Point();
        float getX() const;
        float getY() const;
        

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif