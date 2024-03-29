/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:12:15 by pviegas           #+#    #+#             */
/*   Updated: 2024/03/29 17:07:16 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

// Default Constructor
Point::Point() : _x(0), _y(0) {}
// Parameterized Constructor
Point::Point(Fixed x, Fixed y) : _x(x), _y(y) {}

// getters
Fixed Point::getX() const 
{
	return (_x);
}
Fixed Point::getY() const 
{
	return (_y);
}
