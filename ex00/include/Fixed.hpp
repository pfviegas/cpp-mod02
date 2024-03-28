/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:28:18 by pviegas           #+#    #+#             */
/*   Updated: 2024/03/28 16:59:04 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

/*
fixed point number <32, 8>
32 bits no total
8 bits mais à direita são usados para a fração

23 bits para a parte inteira
8 bits para a fração
1 bit para sinal do número

_value: todos os bits representados como se fosse um número inteiro
_fractionalBits: número de bits mais à direita usados para a parte fracionária:
*/

class	Fixed
{
	public:
		Fixed( void );
		Fixed( const Fixed &other );
		Fixed &operator=( const Fixed &other );
		~Fixed( void );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int _value;
		static const int _fractionalBits = 8;
};

#endif
