/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 15:03:10 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/05 19:19:19 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Default constructor -> values by default
PhoneBook::PhoneBook() {
	current = -1;
}

// define a array static const
// -> same in all program and define 1 time,
// even if we have several instances of PhoneBook
const std::string PhoneBook::fields_names[5] = {
	"First name", "Last name", "Nick name", "Phone number", "Darkest secret"
};

// Create a method = type Class name (args)
void PhoneBook:: add_contact(int index, const Contact& c)
{
	// contacts -> attribute array of class
	// -> directly the name
	contacts[index] = c;
	index = (index + 1) % 8;
}

// PhoneBook::~PhoneBook() {}
