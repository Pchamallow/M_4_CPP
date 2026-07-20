/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:26:15 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/20 19:16:56 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// = CONSTRUCTORS ==============================================

Point:: Point() : x(0), y(0)
{
	#ifdef DEBUG
	std::cout << "Point Default constructor called" << std::endl;
	#endif
}

Point:: Point( const float initX, const float initY ): x(initX), y(initY)
{
	#ifdef DEBUG
	std::cout << "Point Init constructor called" << std::endl;
	#endif
}

Point:: Point( const Point& other )
{
	#ifdef DEBUG
	std::cout << "Point cpy constructor called" << std::endl;
	#endif
	(*this) = other;
}

Point&	Point::operator=( const Point& )
{
	#ifdef DEBUG
	std::cout << "Point copy assignment operator overload called" << std::endl;
	#endif
	return (*this);
}

Point:: ~Point ()
{
	#ifdef DEBUG
	std::cout << "Point destructor called" << std::endl;
	#endif
}


// = METHODS ===================================================

float	Point::getX( void ) const
{
	return (this->x.toFloat());
}

float	Point::getY( void ) const
{
	return (this->y.toFloat());
}
