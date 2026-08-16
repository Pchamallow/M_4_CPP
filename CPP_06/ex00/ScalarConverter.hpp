/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 09:54:30 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/16 13:26:56 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <exception>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <climits>
#include <limits>
#include <cerrno>


class ScalarConverter
{
	public :
		static void		convert( const std::string& src );

	private :
		ScalarConverter( void ){};
		ScalarConverter( const ScalarConverter& ){};
		ScalarConverter&	operator=( const ScalarConverter& ){ return (*this); };
		~ScalarConverter(){};

		static bool	isChar( const std::string& src );
		static bool	isInt( const std::string& src );
		static bool	isFloat( const std::string& src );
		// static bool	isDouble( const std::string& src );
		
		static void	fromChar( const std::string& src, bool is_error );
		static void	fromInt( const std::string& src, bool is_error );

		static void	printChar( const std::string& src, bool is_error );

// char -> que de des lettres + len de 1

// int -> que des lettres, -, entre int min et int max

// float -> int + . + int + f, avec ou sans -
// -> se reseigner pour -inff, +inff

// double -> int + . + int, avec ou sans -

// faire les conversions et voir s il y a une erreur

};