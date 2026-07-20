/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 16:19:51 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/20 15:39:04 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	public :
		Fixed ();
		Fixed ( const Fixed& other );
		Fixed ( const int nbInt );
		Fixed ( const float nbFloat );
		Fixed& operator=( const Fixed& other );
		~Fixed ();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private :
		int					_fixedPointValue;
		static const int	_nbBits = 8;
};

// overload of ostream, not Fixed
std::ostream&	operator<<( std::ostream& os, const Fixed& other );
