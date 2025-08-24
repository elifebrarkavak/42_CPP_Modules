/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:34:00 by elikavak          #+#    #+#             */
/*   Updated: 2025/08/18 17:15:30 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float getArea(Point const &p1, Point const &p2, Point const &p3)
{
    return std::fabs(
        (p1.getX() * (p2.getY() - p3.getY())) +
        (p2.getX() * (p3.getY() - p1.getY())) +
        (p3.getX() * (p1.getY() - p2.getY()))
    ) * 0.5f;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float mainArea = getArea(a, b, c);
    float area1 = getArea(point, b, c);
    float area2 = getArea(a, point, c);
    float area3 = getArea(a, b, point);


    if (area1 < 1e-6f || area2 < 1e-6f || area3 < 1e-6f)
        return false;
    float sumAreas = area1 + area2 + area3;
    return std::fabs(sumAreas - mainArea) <= 1e-6f;
}