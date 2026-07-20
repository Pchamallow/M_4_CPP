/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 16:19:51 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/19 16:48:46 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
	public :
		Fixed ();
		Fixed ( const Fixed& other);
		Fixed& operator=( const Fixed& other );
		~Fixed ();
		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private :
		int					_fixedPointValue;
		static const int	_nbBits = 8;
};