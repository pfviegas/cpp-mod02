/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:34:43 by pviegas           #+#    #+#             */
/*   Updated: 2024/03/28 17:00:36 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "../include/Fixed.hpp"

// Default Constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

// Parameterized Constructor
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fractionalBits;
}

// Parameterized Constructor
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	
	_value = (roundf(value * (1 << _fractionalBits)));
}

// Copy Constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = other._value;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other._value;
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Member Functions
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

// Setter
void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

// Member Functions
float Fixed::toFloat() const
{
	return ((float)_value / (1 << _fractionalBits));
}

// Member Functions
int Fixed::toInt() const
{
	return ((int)_value >> _fractionalBits);
}

// Operator Overload
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

