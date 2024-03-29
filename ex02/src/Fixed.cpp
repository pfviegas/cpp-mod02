/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:34:43 by pviegas           #+#    #+#             */
/*   Updated: 2024/03/29 13:55:35 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "../include/Fixed.hpp"


// Default Constructor
Fixed::Fixed() : _value(0) {}

// Parameterized Constructor
Fixed::Fixed(const int value) : _value(value << _fractionalBits) {}

// Parameterized Constructor
Fixed::Fixed(const float value) : _value(static_cast<int>(roundf(value * (1 << _fractionalBits)))) {}

// Copy Constructor
Fixed::Fixed(const Fixed &other) : _value(other._value) {}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_value = other._value;
	return (*this);
}

// Destructor
Fixed::~Fixed() {}

// Getter
int Fixed::getRawBits() const
{
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
	return (static_cast<float>(_value) / (1 << _fractionalBits));
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

// Comparison operators
bool Fixed::operator>(const Fixed &other) const
{
	return (_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (_value != other._value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(toFloat() / other.toFloat()));
}

// pre-increment operator
Fixed &Fixed::operator++()
{
	_value++;
	return (*this);
}

// post-increment operator
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

// pre-decrement operator
Fixed &Fixed::operator--()
{
	_value--;
	return (*this);
}

// post-decrement operator
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}
