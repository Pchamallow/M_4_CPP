/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 16:19:34 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/20 17:57:50 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// = CONSTRUCTORS ==============================================

Fixed:: Fixed ()
{
	#ifdef DEBUG
	std::cout << "Default constructor called" << std::endl;
	#endif
	_fixedPointValue = 0;
}

Fixed:: Fixed ( const Fixed& other )
{
	#ifdef DEBUG
	std::cout << "Copy constructor called" << std::endl;
	#endif
	(*this) = other;
}

Fixed:: Fixed ( const int nbInt )
{
	#ifdef DEBUG
	std::cout << "Int constructor called" << std::endl;
	#endif
	_fixedPointValue = nbInt << _nbBits;
}

Fixed:: Fixed ( const float nbFloat )
{
	#ifdef DEBUG
	std::cout << "Float constructor called" << std::endl;
	#endif
	_fixedPointValue = (int)roundf(nbFloat * (1 << _nbBits));
}

Fixed& Fixed::operator= (const Fixed& other)
{
	#ifdef DEBUG
	std::cout << "Copy assignment operator called" << std::endl;
	#endif
	if (this != &other)
		this->_fixedPointValue = other._fixedPointValue;
	return (*this);
}

Fixed:: ~Fixed ()
{
	#ifdef DEBUG
	std::cout << "Destructor called" << std::endl;
	#endif
};



// = METHODS ===================================================

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointValue);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}

float	Fixed::toFloat( void ) const
{ return ((float)_fixedPointValue/(1 << _nbBits)); }

int		Fixed::toInt( void ) const
{ return (_fixedPointValue/(1 << _nbBits)); }



// = METHODS COMPARISON OVERLOAD ===============================

bool	Fixed::operator>( const Fixed& other ) const
{	return (this->_fixedPointValue > other._fixedPointValue);	}

bool	Fixed::operator<( const Fixed& other ) const
{	return (this->_fixedPointValue < other._fixedPointValue);	}

bool	Fixed::operator>=( const Fixed& other ) const
{	return(this->_fixedPointValue >= other._fixedPointValue);	}

bool	Fixed::operator<=( const Fixed& other ) const
{	return(this->_fixedPointValue <= other._fixedPointValue);	}

bool	Fixed::operator==( const Fixed& other ) const
{	return(this->_fixedPointValue == other._fixedPointValue);	}

bool	Fixed::operator!=( const Fixed& other ) const
{	return(this->_fixedPointValue != other._fixedPointValue);	}



// = METHODS ARITHMETIC OVERLOAD ===============================

Fixed	Fixed::operator+( const Fixed& other ) const
{	return (this->toFloat() + other.toFloat());	}

Fixed	Fixed::operator-( const Fixed& other ) const
{	return (this->toFloat() - other.toFloat());	}

Fixed	Fixed::operator*( const Fixed& other ) const
{	return (this->toFloat() * other.toFloat());	}

Fixed	Fixed::operator/( const Fixed& other ) const
{	return (this->toFloat() / other.toFloat());	}



// = METHODS INCREMENT / DECREMENT OVERLOAD ====================

Fixed&	Fixed::operator++( void )
{
	this->_fixedPointValue += 1;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed tmp(*this);
	this->_fixedPointValue += 1;
	return (tmp);
}

Fixed&	Fixed::operator--( void )
{
	this->_fixedPointValue -= 1;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed tmp(*this);
	this->_fixedPointValue -= 1;
	return (tmp);
}


// = METHODS INCREMENT / DECREMENT OVERLOAD ====================

Fixed&	Fixed::min( Fixed& a, Fixed& b)
{
	if (a._fixedPointValue < b._fixedPointValue)
		return (a);
	return (b);
}

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b )
{
	if (a._fixedPointValue < b._fixedPointValue)
		return (a);
	return (b);
}

Fixed&	Fixed::max( Fixed& a, Fixed& b)
{
	if (a._fixedPointValue > b._fixedPointValue)
		return (a);
	return (b);
}

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b )
{
	if (a._fixedPointValue > b._fixedPointValue)
		return (a);
	return (b);
}



// = FUNCTION STREAM OVERLOAD ==================================

std::ostream&	operator<<( std::ostream& os, const Fixed& other )
{
	os << other.toFloat();
	return (os);
}


