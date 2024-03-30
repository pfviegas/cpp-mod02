/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:04:02 by pviegas           #+#    #+#             */
/*   Updated: 2024/03/29 17:05:57 by pviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

class Point
{
	public:
		Point();
		Point(float x, float y);
		Fixed getX() const;
		Fixed getY() const;
		
	private:
		Fixed const _x;
		Fixed const _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
