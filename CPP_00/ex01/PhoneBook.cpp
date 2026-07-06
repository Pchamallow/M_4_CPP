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
	_current = -1;
}

// Create a method = type Class name (args)
// void	PhoneBook:: addContact(Contact c)
void	PhoneBook:: addContact(const Contact& c)
{
	_contacts[_current] = c;
	// std::cout << "debug" << _contacts[0].getField(0) << std::endl; 
	_current = (_current + 1) % 8;
}

void	PhoneBook:: incrementCurrent(){
	_current += 1;
}

int	PhoneBook:: getCurrent(){
	return (_current);
}

// right-aligned, 10 characters wide
void	PhoneBook:: printFormat(std::string str)
{
	std::cout << std::right << std::setw(10);
	std::cout << str;
}

std::string	PhoneBook:: toString(int nb){
	std::ostringstream oss;
	oss << nb;
	return (oss.str());
}

void	PhoneBook::	printContacts()
{
	int	i = 0;

	printFormat("index");
	while (i < 3)
	{
		std::cout << "|";
		printFormat(fields_names[i]);
		++i;
	}
	i = 0;
	int j = 0;
	while (i == 0 || i < _current)
	{
		printFormat(toString(i));
		std::cout << "|";
		while (j < 3)
		{
			printFormat(_contacts[i].getField(j));
			std::cout << "|";
			++j;
		}
		++i;
	}
	std::cout << std::endl;
}

// define a array static const
// -> same in all program and define 1 time,
// even if we have several instances of book
const std::string PhoneBook::fields_names[5] = {
	"First name", "Last name", "Nick name", "Phone number", "Darkest secret"
};


