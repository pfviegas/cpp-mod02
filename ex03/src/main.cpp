/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:24:28 by pviegas           #+#    #+#             */
/*   Updated: 2024/03/29 17:11:00 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

int main()
{
	// Defining the vertices of the triangle
	Point vertex1(0.1f, 0.1f);
	Point vertex2(4.2f, 0.2f);
	Point vertex3(0.3f, 4.3f);

	// Defining a test point
	Point testPoint(1.5f, 1.5f);

	// Checks if the point is inside the triangle
	bool insideTriangle = bsp(vertex1, vertex2, vertex3, testPoint);

	if (insideTriangle)
		std::cout << "The point is INSIDE the triangle." << std::endl;
	else
		std::cout << "The point is OUTSIDE the triangle." << std::endl;

	return (0);
}
