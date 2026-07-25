/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:09:37 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 14:29:15 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"
#include "iostream"


// = CONSTRUCTORS ==============================================

WrongCat:: WrongCat()
{
	WrongAnimal::type = "WrongCat";
	std::cout << "A WrongCat " << type << " is born" << std::endl;
}

WrongCat:: WrongCat( const WrongCat& other )
{
	(*this) = other;
	std::cout << "A twin WrongCat" << type << " is created" << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat& other )
{
	if (this != &other)
	{	WrongAnimal::type = other.type;	}
	std::cout << "A new same WrongCat" << type << " is created" << std::endl;
	return (*this);
}

WrongCat:: ~WrongCat()
{	std::cout << "A WrongCat, type" << type << " is leaving" << std::endl;	}


// = METHODS ===================================================

void	WrongCat::makeSound( void )
{	std::cout << "WrongCat - makeSound - Miaou" << std::endl;	}

std::string	WrongCat::getType( void )
{	return (type);	}