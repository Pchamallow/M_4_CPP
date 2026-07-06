/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 08:40:45 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/06 18:46:16 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "PhoneBook.hpp"

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

int	getIndex(PhoneBook& book)
{
	std::string	input;
	int			index = -1;

	while (1)
	{
		std::cout << "Index to find: ";
		getline(std::cin, input);
		index = std::atoi(input.c_str());
	
		if (input.empty())
			continue ;
		else if (!isNumeric(input)
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

void	search(PhoneBook& book)
{
	while (1)
	{
		if (book.getIndex() == -1){
			print(2, "Error: not a least one contact, add one before search");
			return ;
		}

		book.printContacts();

		int index = -1;
		while (index == -1)
			index = getIndex(book);

		book.printContact(index);
		break ;
	}
}

void	add(PhoneBook& book)
{
	std::string		input[5];
	int				i = 0;

	if (book.getIndex() == -1)
		book.incrementIndex();
	while (i < 5)
	{
		std::cout << book.fieldsNames[i] << ": ";
		getline(std::cin, input[i]);
		if (input[i].empty())
			continue ;
		else
			i++;
	}
	Contact	contact(input[0], input[1], input[2], input[3], input[4]);
	book.addContact(contact);
}

int main () {

	PhoneBook		book;
	std::string		input;

	while (1)
	{
		std::cout << "Enter a command (ADD / SEARCH / EXIT): ";
		getline(std::cin, input);

		if (input == "ADD")
			add(book);
		else if (input == "SEARCH")
			search(book);
		else if (input == "EXIT")
			break ;
	}
	return (0);
}
