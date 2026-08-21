/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:30:25 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/21 12:07:55 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <iostream>


#define RED		"\033[31m"
#define BLUE	"\033[34m"
#define CYAN	"\033[36m"
#define LYLA	"\033[35m"
#define BROWN	"\033[33m"
#define RESET	"\033[0m"
#define GROUP	3


/*
Arr = array
Grp = groupe
*/
class PmergeMe
{
	public:
		// PmergeMe( void );
		void	insertNumber();
		int		argsToNumbers( int ac, char **av );
		void	invalidArguement( void );
		void	clearArrayA( void );
		void	printArray( char arr, bool sortByLoseWin );
		void	algo( void );
		
	private:
		int		_sendToArray ( std::string str );
		bool	_isSorted( std::vector<int>& arr );
		size_t	_nbGrp( size_t sizeArr, size_t sizeGrp );
		void	_orderGrp( size_t sizeGrp );
		void	_moveRange(size_t start, size_t length, size_t newIndex, std::vector<int>& src, std::vector<int>& dst);
		void	_allLosersToArrayB( size_t sizeGrp, size_t nbGrp );
		void	_pushToArr(size_t start, size_t length, std::vector<int>& src, std::vector<int>& dst);
		std::vector<int>			_arrayA;
		std::vector<int>			_arrayB;
		std::vector<int>::iterator	it;
};