/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:21:08 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 18:10:29 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "iostream"


// = CONSTRUCTORS ==============================================

Animal:: Animal()
{
	type = "";
	std::cout << "An Animal with no types is born" << std::endl;
}

Animal:: Animal( const Animal& other )
{
	(*this) = other;
	std::cout << "A twin of an Animal of type " << type << " is created" << std::endl;
}

Animal& Animal::operator=( const Animal& other )
{
	if (this != &other)
	{	type = other.type;	}
	std::cout << "A new same " << type << " is created" << std::endl;
	return (*this);
}

Animal:: ~Animal()
{	std::cout << "An Animal, type : " << type << " is leaving" << std::endl;	}


// = METHODS ===================================================

void	Animal::makeSound( void ) const
{	std::cout << "makeSound() - Animal make a sound" << std::endl;	}

std::string	Animal::getType( void ) const
{	return (type);	}
