/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:44:29 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/20 11:06:43 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <climits>
#include <stdlib.h>
#include <errno.h>
#include <cmath>

void	printError( char *message )
{
	std::cerr << RED << "Error" << std::endl;
	std::cerr << message << RESET << std::endl;
}

void	PmergeMe::invalidArguement( void )
{
	std::cerr << RED << "Error" << std::endl;
	std::cerr << "Invalid arguements, pattern required a unsorted"
	" positive integer sequence (at least 2 elements)";
	std::cerr << " separated by spaces: ./PmergeMe [numbers] [//] [//] ...";
	std::cerr << RESET << std::endl;
}

int PmergeMe::_sendToArray( std::string str )
{
	char *end;
	long nb = std::strtol(str.c_str(), &end, 10); // INT MIN, INT MAX
	// std::cout << BLUE << "[DEBUG] " << nb << RESET << std::endl;
	if (errno || nb < 0 || nb > INT_MAX)
	{
		invalidArguement();
		return (1);
	}
	_arrayA.push_back((int)nb);
	return (0);
}

bool	PmergeMe::_isSorted( std::vector<int>& array )
{
	size_t i = 0;
	while(i <= array.size())
	{
		if (i < array.size() - 1)
		{
			// std::cout << BLUE << "[DEBUG] e1 = " << array.at(i);
			// std::cout << " e2 = " << array.at(i + 1) << RESET << std::endl;
			if (array.at(i) > array.at(i + 1))
				return (false);
		}
		++i;
	}
	return (true);
}

int	PmergeMe::argsToNumbers( int ac, char **av ) // parser les arguemnts de av et les trsnaformer en int
{
	bool isNumber = false;

	for(int i = 0; i < ac - 1; ++i)
	{
		std::string arg = av[i];
		// std::cout << BLUE << "[DEBUG] arg = " << arg << RESET << std::endl;
		if (arg.empty()) // case arg = ""
		{
			invalidArguement();
			return (1);
		}
		size_t start = 0;
		for(size_t j = 0; arg[j]; ++j) // case arg != digit && space
		{
			// std::cout << BLUE << "[DEBUG] arg j = " << arg[j] << RESET << std::endl;
			if (std::isspace(arg[j]))
			{
				if (isNumber)
				{
					std::string nb = arg.substr(start, j - 1);
					// std::cout << "[DEBUG] string nb = " << nb << std::endl;
					if (_sendToArray(nb))
						return (1);
				}
				isNumber = false;
			}
			else if (std::isdigit(arg[j]))
			{
				isNumber = true;
				while (arg[j] && std::isdigit(arg[j]))
					j++;
				if (!arg[j])
				{
					std::string nb = arg.substr(start, j);
					// std::cout << "[DEBUG] string nb = " << nb << std::endl;
					j--;
					if (_sendToArray(nb))
						return (1);
				}
			}
			else
			{
				invalidArguement();
				return (1);
			}
		}
	}
	if (_arrayA.size() <= 1) // case one argument
	{
		printError((char *)"Only one arguement, required at least two");
		return (1);
	}
	else if (_isSorted(_arrayA)) // case already sorted
	{
		printError((char *)"Arguements already sorted");
		return (1);
	}
	return (0);
}

void	PmergeMe::clearArrayA( void )
{	_arrayA.clear();	}

size_t	PmergeMe::_getNbGroup( size_t size, size_t sizeGroup )
{
	size_t res = std::ceil(size/sizeGroup); // round up
	return (res);
}

void	PmergeMe::printArrayA( void )
{
	std::cout << BLUE;
	for (size_t i = 0; i < _arrayA.size(); ++i) {
		std::cout << _arrayA[i] << " ";
	}
	std::cout << RESET << std::endl;
}

void	PmergeMe::algo( void )
{
	printArrayA();
	_orderPairs(2);
	printArrayA();
}


// 1er tour a 2
void	PmergeMe::_orderPairs( size_t padding )
{
	size_t i = 0;
	--padding;
	if (padding < 1)
	{
		printError((char *)"Order pairs, padding invalid");
		return ;
	}
	while(i <= _arrayA.size())
	{
		size_t loser = i;
		size_t winner = i + padding;
		std::cout << BLUE << "[DEBUG] loser = " << loser << " | winner = " << winner;
		std::cout << BLUE << " | size = " << _arrayA.size();
		std::cout << RESET << std::endl;

		if ( loser >= _arrayA.size() )
			return ; // paire fictive, ne pas modifier
		if ( i < _arrayA.size() - 1 )
		{

			std::cout << BLUE << "[DEBUG] value loser = " << _arrayA.at(loser);
			std::cout << " | value winner = " << _arrayA.at(winner) << std::endl;
			printArrayA();

			if (_arrayA.at(loser) > _arrayA.at(winner))
			{
				int valueLoser = _arrayA.at(loser);
				_arrayA.erase(_arrayA.begin() + loser);
				_arrayA.insert(_arrayA.begin() + loser + 1, valueLoser);
			}
		}
		i += padding + 1;
	}
}
