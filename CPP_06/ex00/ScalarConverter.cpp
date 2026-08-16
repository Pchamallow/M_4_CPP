/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 10:11:09 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/16 13:29:35 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#define RED		"\033[31m"
#define RESET	"\033[0m"

// = MEMBER FUNCTIONS =================================================

void		ScalarConverter::convert( const std::string& src )
{
	if (src.empty())
	{
		std::cerr << RED << "Invalid arguement" << RESET << std::endl;
		return ;
	}

	std::string input = src;
	double value = 0;
	char *end;
	if (input == "nan")
		value = std::numeric_limits<double>::quiet_NaN();
	else
		value = std::strtod(input.c_str(), &end);

	if (std::isnan(value))
	{
		printChar(src, 1);
		std::cout << "int: impossible" << std::endl;
		// printFloat(src, 1);
		// tous les autres print en error
		return ;
	}

	bool	(*findType[4])( const std::string& ) ={
		&ScalarConverter::isChar,
		&ScalarConverter::isInt
	};

	void	(*printType[4])( const std::string&, bool ) ={
		&ScalarConverter::fromChar,
		&ScalarConverter::fromInt
	};

	for(int i = 0; i < 2; ++i)
	{
			std::cout << "[DEBUG] its" << std::endl;
		if (findType[i](src))
		{
			printType[i](src, 0);
			return ;
		}
	}
}

bool	ScalarConverter::isChar( const std::string& src)
{
	if (src.length() == 1
		&& !std::isdigit(src[0]))
	{
		std::cout << "[DEBUG] its a char" << std::endl;
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isInt( const std::string& src )
{
	char	*end;
	int		nb = std::strtol(src.c_str(), &end, 10);
	if (!errno && end == '\0' && (nb >= INT_MIN && nb <= INT_MAX))
	{
		std::cout << "[DEBUG] its a int" << std::endl;
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isFloat( const std::string& src )
{
	char	*end;
	float	nb = std::strtof(src.c_str(), &end);
	(void)nb;
	if (!errno && end == '\0')
		return (true);
	return (false);
}
// bool	ScalarConverter::isDouble( const std::string& src );

void	ScalarConverter::fromChar( const std::string& src , bool is_error)
{
	int	value = atoi(src.c_str());
	printChar(src, is_error);
	std::cout << "int: " << value << std::endl;
}

void	ScalarConverter::fromInt( const std::string& src , bool is_error)
{
	int	value = atoi(src.c_str());
	printChar(src, is_error);
	std::cout << "int: " << value << std::endl;
}

void	ScalarConverter::printChar( const std::string& src , bool is_error)
{
	if (is_error)
	{
		std::cerr << "char: " << "impossible" << std::endl;
		return ;
	}
	int	value = atoi(src.c_str());
	
	if ( value >= 32 && value < 128 )
		std::cout << "char: '" << static_cast<char>(src[0]) << "'" << std::endl;
	else if (src.length() > 1)
		std::cerr << "char: " << "impossible" << std::endl;
	else
		std::cerr << "char: " << "Non displayable" << std::endl;
}


