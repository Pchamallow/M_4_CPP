/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 09:52:14 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/17 12:20:19 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <sstream>

#define RED		"\033[31m"
#define BROWN	"\033[33m"
#define RESET	"\033[0m"

/*
pour une valuer str donne

ScalarConverter converter();
converter.convert("42");
-> print output en char, int, float et double

- As this class doesn’t need to store anything at all, it must not be instantiable by users.
Except for char parameters, only the decimal notation will be used

- parsing des entrées


*/

int main( int ac, char **av )
{
	std::cout << std::endl << std::string(60, '-') << std::endl;
	std::cout << BROWN << "TESTS - Argument test"<< RESET << std::endl;
	
	if (ac == 2 && av[1])
		ScalarConverter::convert(av[1]);
	else
		std::cerr << RED << "Required one argument" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BROWN << "TESTS - Char: b"<< RESET << std::endl;
	ScalarConverter::convert("b");
	std::cout << std::endl;

	std::cout << BROWN << "TESTS - Int: 28"<< RESET << std::endl;
	ScalarConverter::convert("28");
	std::cout << std::endl;

	std::cout << BROWN << "TESTS - Float: 0.42f"<< RESET << std::endl;
	ScalarConverter::convert("0.42f");
	std::cout << std::endl;

	std::cout << BROWN << "TESTS - Double: 0.42"<< RESET << std::endl;
	ScalarConverter::convert("0.42");
	std::cout << std::endl;


	std::cout << BROWN << "TESTS - Nan test" << RESET << std::endl;
	ScalarConverter::convert("nan");

	std::cout << std::endl;
}