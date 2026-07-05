/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 08:40:45 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/05 19:28:26 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>     // std::cout, std::hex, std::endl
#include <iomanip>      // std::setiosflags
#include <cstdlib>
#include "PhoneBook.hpp"


void	print(std::string message, int fd)
{
	if (fd == 2)
		std::cerr << "\033[31m" << message  << "\033[0m" << std::endl;
	else
		std::cout << message << std::endl;
}

void	search(PhoneBook phonebook)
{
	// const char	*input;
	(void)phonebook;
	std::string	input;
	while (1)
	{
		if (phonebook.current == -1){
			print("Error: not a least one contact, add one before search", 2);
			return ;
		}

		std::cout << "Search index n* ";
		getline(std::cin, input);
		char *endptr;
		int	index = std::strtol(input.c_str(), &endptr, 10);

		if (input.empty())
			continue ;
		else if (endptr == input.c_str() || index > phonebook.current)
		{
			std::cerr << "Error: index must be between 0 and ";
			std::cerr << phonebook.current << " (inclusive)";
			std::cerr << std::endl;
			continue ;
		}
		else {
			// print l index
			break ;
		}
	}
}

void	add(PhoneBook phonebook)
{
	std::string		input[5];
	Contact			contact;
	int				i = 0;

	if (phonebook.current == -1)
		++phonebook.current;
	while (i < 5)
	{
		std::cout << phonebook.fields_names[i] << " : ";
		getline(std::cin, input[i]);
		if (input[i].empty())
			continue ;
		else
			i++;
	}
	phonebook.add_contact(phonebook.current, contact);
	++phonebook.current;
}


int main () {

	PhoneBook		phonebook;
	std::string		input;

	// PhoneBook.fields_names = {"coucou", "salut", "yo", "hello", "hs"}; // test
	while (1)
	{
		std::cout << "Enter a command : ADD / SEARCH / EXIT" << std::endl;
		getline(std::cin, input);
	
		if (!input.compare("ADD")){
			add(phonebook);
			std::cout << "oui" << std::endl;
		}
		else if (!input.compare("SEARCH")){
			search(phonebook);
		}
		else if (!input.compare("EXIT")){
			break ;
		}

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


