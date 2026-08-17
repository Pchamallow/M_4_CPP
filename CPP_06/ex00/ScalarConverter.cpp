/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 10:11:09 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/17 12:14:56 by pswirgie         ###   ########.fr       */
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
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	bool	(*findType[4])( const std::string& ) ={
		&ScalarConverter::isChar,
		&ScalarConverter::isInt,
		&ScalarConverter::isFloat
	};

	void	(*printType[4])( const std::string& ) ={
		&ScalarConverter::fromChar,
		&ScalarConverter::fromInt,
		&ScalarConverter::fromFloat
	};

	for(int i = 0; i < 3; ++i)
	{
		if (findType[i](src))
		{
			printType[i](src);
			return ;
		}
	}
}

bool	ScalarConverter::isChar( const std::string& src)
{
	if (src.length() == 1
		&& !std::isdigit(src[0]))
	{
		#if DEBUG
		std::cout << "[DEBUG] its a char" << std::endl;
		#endif
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isInt( const std::string& src )
{
	char	*end;
	int		nb = std::strtol(src.c_str(), &end, 10);
	if (!errno && *end == '\0' && (nb >= INT_MIN && nb <= INT_MAX))
	{
		#if DEBUG
		std::cout << "[DEBUG] its a int" << std::endl;
		#endif
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isFloat( const std::string& src )
{
	char	*end;
	float	nb = std::strtof(src.c_str(), &end);
	(void)nb;
	if (!errno && *end == 'f')
	{
		#if DEBUG
		std::cout << "[DEBUG] its a float" << std::endl;
		#endif
		return (true);
	}
	return (false);
}
// bool	ScalarConverter::isDouble( const std::string& src );

void	ScalarConverter::fromChar( const std::string& src )
{
	int	value = atoi(src.c_str());
	std::cout << "char: " << src[0] << std::endl;
	std::cout << "int: " << value << std::endl;
}

void	ScalarConverter::fromInt( const std::string& src )
{
	char	*end;
	float	value = std::strtof(src.c_str(), &end);
	printChar<int>(value);
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << value << std::endl;
}

void	ScalarConverter::fromFloat( const std::string& src )
{
	char	*end;
	float	value = std::strtof(src.c_str(), &end);
	printChar<float>(value);
	if (value >= static_cast<float>(INT_MIN) &&value <= static_cast<float>(INT_MAX))
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << value << std::endl;
}




