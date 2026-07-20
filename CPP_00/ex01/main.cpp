/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 08:40:45 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/20 10:15:34 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <CXXtype>
#include "PhoneBook.hpp"

bool	strWhitespaces(std::string *str)
{
	int	i = 0;

	while ((*str)[i])
	{
		if (!std::isspace((*str)[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	getInput(std::string *input)
{
	getline(std::cin, *input);
	if (std::cin.eof())
		return (false);
	return (true);
}

void	print(int fd, std::string message)
{
	if (fd == 2)
		std::cerr << "\033[31m" << message  << "\033[0m" << std::endl;
	else
		std::cout << message << std::endl;
}

int	isNumeric(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if(!std::isdigit(str[i]))
			return (0);
		++i;
	}
	return (1);
}

int	getIndexInput(PhoneBook& book)
{
	std::string	input;
	int			index = -1;

	while (1)
	{
		std::cout << "Index to find: ";
		if(!getInput(&input))
			return (-2);
		index = std::atoi(input.c_str());
	
		if (input.empty()
			|| strWhitespaces(&input)
			|| !isNumeric(input)
			|| index > book.getMaxIndex()
			|| index < 0)
		{
			int max = book.getMaxIndex();
			std::cerr << "\033[31m" << "Error: index must be between 0 and ";
			std::cerr << max << " (inclusive)";
			std::cerr << "\033[0m" << std::endl;
			continue ;
		}
		else
			break;
	}
	return (index);
}

int	search(PhoneBook& book)
{
	while (1)
	{
		if (book.getIndex() == -1){
			print(2, "Error: not a least one contact, add one before search");
			return (0);
		}

		book.printContacts();

		int index = -1;
		while (index == -1)
			index = getIndexInput(book);
		if (index == -2)
			return (1);

		book.printContact(index);
		break ;
	}
	return (0);
}

int	add(PhoneBook& book)
{
	std::string		input[5];
	int				i = 0;

	if (book.getIndex() == -1)
		book.incrementIndex();
	while (i < 5)
	{
		std::cout << book.fieldsNames[i] << ": ";
		if (!getInput(&input[i]))
			return (1);
		if (input[i].empty() || strWhitespaces(&input[i]))
			continue ;
		else
			i++;
	}
	Contact	contact(input[0], input[1], input[2], input[3], input[4]);
	book.addContact(contact);
	return (0);
}

int main () {

	PhoneBook		book;
	std::string		input;

	while (1)
	{
		std::cout << "Enter a command (ADD / SEARCH / EXIT): ";
		if (!getInput(&input))
			return (1);

		if (input == "ADD" && add(book))
			return (1);
		else if (input == "SEARCH" && search(book))
			return (1);
		else if (input == "EXIT")
			break ;
	}
	return (0);
}
