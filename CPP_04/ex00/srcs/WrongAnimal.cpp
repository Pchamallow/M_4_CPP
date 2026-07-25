/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:21:08 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 14:29:34 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"
#include "iostream"


// = CONSTRUCTORS ==============================================

WrongAnimal:: WrongAnimal()
{
	type = "";
	std::cout << "A WrongAnimal with no types is born" << std::endl;
}

WrongAnimal:: WrongAnimal( const WrongAnimal& other )
{
	(*this) = other;
	std::cout << "A twin of a WrongAnimal of type " << type << " is created" << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other )
{
	if (this != &other)
	{	type = other.type;	}
	std::cout << "A new same WrongAnimal" << type << " is created" << std::endl;
	return (*this);
}

WrongAnimal:: ~WrongAnimal()
{	std::cout << "An WrongAnimal, type : " << type << " is leaving" << std::endl;	}


// = METHODS ===================================================

std::string	WrongAnimal::getType( void )
{	return (type);	}

void	WrongAnimal::makeSound( void )
{	std::cout << "makeSound() - WrongAnimal make a sound" << std::endl;	}