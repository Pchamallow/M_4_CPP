/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 08:40:45 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/06 14:29:13 by pswirgie         ###   ########.fr       */
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

void	search(PhoneBook& book)
{
	std::string	input;

	while (1)
	{
		if (book.getCurrent() == -1){
			print(2, "Error: not a least one contact, add one before search");
			return ;
		}

		book.printContacts();

		std::cout << "Search index n* ";
		getline(std::cin, input);
		char *endptr;
		int	index = std::strtol(input.c_str(), &endptr, 10);

		if (input.empty())
			continue ;
		else if (endptr == input.c_str() || index > book.getCurrent())
		{
			std::cerr << "Error: index must be between 0 and ";
			std::cerr << book.getCurrent() << " (inclusive)";
			std::cerr << std::endl;
			continue ;
		}
		else {
			// print un contact -> index
			break ;
		}
	}
}

void	add(PhoneBook& book)
{
	std::string		input[5];
	int				i = 0;

	if (book.getCurrent() == -1)
		book.incrementCurrent();
	// std:;cout 
	while (i < 5)
	{
		std::cout << book.fields_names[i] << " : ";
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


// TESTS
// SEARCH
// mettre des lettres



// // SECTION READ FROM INPUT TERMINAL + DISPLAY PROMPT IF INPUT EMPTY
// // an entire line of text, including spaces.
// std::string name;

// getline(std::cin, name);
// std::cout << name;


// // SECTION SAVE CONTACT
// get input for each element
// if empty display
// put in instance

// // SECTION SEARCH INDEX
// get input
// if empty display prompt
// if invalid = error
// read the index of array contact

// // SECTION EXIT
// get input
// if input == EXIT, return main

// // SECTION RIGHT ALIGNED + REPLACE LAST CHAR BY A DOT + 10 WIDE
// // PIPE
// // std::string s = "Coucou les loulous. Comment ça fart ?";
// std::string s = "Coucou";
// std::string getrest = s.substr(0,9);
// std::cout << std::right << std::setw(10);
// std::cout << (s.size() > 10 ? getrest.replace(9, 1, ".") : s) << std::endl;

// print a pipe

// reprint avec la fonction au dessus 
// faire toute la ligne ainsi 
// endl
// faire chaque ligne


