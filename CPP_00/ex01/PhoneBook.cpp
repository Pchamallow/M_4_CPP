/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 09:35:32 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/06 10:35:42 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

// Default constructor -> values by default
PhoneBook::PhoneBook() {
	_nextIndex = -1;
	_maxIndex = -1;
}

void	PhoneBook:: addContact(const Contact& c)
{
	_contacts[_nextIndex] = c;
	if (_maxIndex < 7)
		_maxIndex = _nextIndex;
	_nextIndex = (_nextIndex + 1) % 8;
}

void	PhoneBook:: incrementIndex(){
	_nextIndex += 1;
}

int	PhoneBook:: getIndex(){
	return (_nextIndex);
}

int	PhoneBook:: getMaxIndex(){
	return (_maxIndex);
}

// right-aligned, 10 characters wide, trunc with last char = .
void	PhoneBook:: printFormat(std::string str)
{
	std::string getrest = str.substr(0,9);
	std::cout << std::right << std::setw(10);
	std::cout << (str.size() > 10 ? getrest.replace(9, 1, ".") : str);
}

std::string	PhoneBook::	toString(int nb){
	std::ostringstream oss;
	oss << nb;
	return (oss.str());
}

void	PhoneBook::	printContact(int index){
	int	i = 0;

	while (i < 5){
		std::cout << fieldsNames[i] << ": ";
		std::cout << _contacts[index].getField(i) << std::endl;
		++i;
	}
}

void	PhoneBook::	printContacts()
{
	int	i = 0;

	printFormat("index");
	while (i < 3)
	{
		std::cout << "|";
		printFormat(fieldsNames[i]);
		++i;
	}
	std::cout << "|";
	std::cout << std::endl;

	i = 0;
	while (i == 0 || i <= _maxIndex)
	{
		printFormat(toString(i));
		std::cout << "|";
		int j = 0;
		while (j < 3)
		{
			printFormat(_contacts[i].getField(j));
			std::cout << "|";
			++j;
		}
		std::cout << std::endl;
		++i;
	}
}

// define a array static const
// -> same in all program and define 1 time,
// even if we have several instances of book
const std::string PhoneBook::fieldsNames[5] = {
	"First name", "Last name", "Nick name", "Phone number", "Darkest secret"
};


