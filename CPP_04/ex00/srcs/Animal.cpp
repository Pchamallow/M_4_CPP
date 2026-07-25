/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:21:08 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 15:15:59 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "iostream"


// = CONSTRUCTORS ==============================================

Animal:: Animal()
{
	type = "";
	std::cout << "An animal with no types is born" << std::endl;
}

Animal:: Animal( const Animal& other )
{
	(*this) = other;
	std::cout << "A twin of an animal of type " << type << " is created" << std::endl;
}

Animal& Animal::operator=( const Animal& other )
{
	if (this != &other)
	{	type = other.type;	}
	std::cout << "A new same " << type << " is created" << std::endl;
	return (*this);
}

Animal:: ~Animal()
{	std::cout << "An animal, type : " << type << " is leaving" << std::endl;	}


// = METHODS ===================================================

void	Animal::makeSound( void ) const
{	std::cout << "makeSound() - Animal make a sound" << std::endl;	}

std::string	Animal::getType( void ) const
{	return (type);	}
