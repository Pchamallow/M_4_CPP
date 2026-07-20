/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:23:53 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/20 19:56:29 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class	Point
{
	public :
		Point();
		Point( const float initX, const float initY );
		Point( const Point& other );
		Point&	operator=( const Point& other );
		~Point();

		float	getX( void ) const;
		float	getY( void ) const;

	private :
		Fixed const	x;
		Fixed const	y;
};

std::ostream&	operator<<( std::ostream& os, const Fixed& other );
bool	bsp( Point const a, Point const b, Point const c, Point const point);
