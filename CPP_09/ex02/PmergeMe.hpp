/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:30:25 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/21 09:50:02 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <iostream>


#define RED		"\033[31m"
#define BLUE	"\033[34m"
#define BROWN	"\033[33m"
#define RESET	"\033[0m"

class PmergeMe
{
	public:
		void	insertNumber();
		int		argsToNumbers( int ac, char **av );
		void	invalidArguement( void );
		void	clearArrayA( void );
		void	printArrayA( void );
		void	algo( void );
		
	private:
		int		_sendToArray ( std::string str );
		bool	_isSorted( std::vector<int>& array );
		size_t	_getNbGroup( size_t size, size_t sizeGroup );
		void	_orderGrp( size_t grpSize );
		void	_moveRange(size_t start, size_t length, size_t dst);

		std::vector<int>			_arrayA;
		std::vector<int>::iterator	it;
};