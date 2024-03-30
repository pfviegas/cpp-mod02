/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:31:56 by pviegas           #+#    #+#             */
/*   Updated: 2024/03/29 17:11:31 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

Fixed calculateTriangleArea( const Point& a, const Point& b, const Point& c )
{
	Fixed area = Fixed((b.getX() - a.getX()) * (c.getY() - a.getY()) -
						(c.getX() - a.getX()) * (b.getY() - a.getY()));

    // Converts to the absolute value, ensuring that the area is always positive
    area = Fixed(abs(area.getRawBits()));
	return (area);
}

// Function to check if a point is inside the triangle
bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed totalArea = calculateTriangleArea(a, b, c);
	Fixed area1 = calculateTriangleArea(point, b, c);
	Fixed area2 = calculateTriangleArea(point, a, c);
	Fixed area3 = calculateTriangleArea(point, a, b);

	// Check if sum of areas of the smaller triangles is equal to the total area
	return ((area1 + area2 + area3) == totalArea);
}
