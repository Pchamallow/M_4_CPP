/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 09:54:30 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/17 12:25:08 by pswirgie         ###   ########.fr       */
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

template <typename valueType>
void	printChar( valueType value )
{
	if ( value >= 32 && value < 128 )
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else if (value < 0 || value >= 129)
		std::cerr << "char: " << "impossible" << std::endl;
	else
		std::cerr << "char: " << "Non displayable" << std::endl;
}

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
		static bool	isDouble( const std::string& src );
		
		static void	fromChar( const std::string& src );
		static void	fromInt( const std::string& src );
		static void	fromFloat( const std::string& src );
		static void	fromDouble( const std::string& src );


// char -> que de des lettres + len de 1

// int -> que des lettres, -, entre int min et int max

// float -> int + . + int + f, avec ou sans -
// -> se reseigner pour -inff, +inff

// double -> int + . + int, avec ou sans -

// faire les conversions et voir s il y a une erreur

};