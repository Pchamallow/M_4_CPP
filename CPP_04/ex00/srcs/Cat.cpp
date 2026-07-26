/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:09:37 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/26 16:34:52 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "iostream"


// = CONSTRUCTORS ==============================================

Cat:: Cat()
{
	Animal::type = "Cat";
	std::cout << "A " << type << " is born" << std::endl;
}

Cat:: Cat( const Cat& other ) : Animal( other )
{
	(*this) = other;
	std::cout << "A twin " << type << " is created" << std::endl;
}

Cat& Cat::operator=( const Cat& other )
{
	if (this != &other)
	{	Animal::type = other.type;	}
	std::cout << "A new same " << type << " is created" << std::endl;
	return (*this);
}

Cat:: ~Cat()
{	std::cout << "A " << type << " is leaving" << std::endl;	}


// = METHODS ===================================================

void	Cat::makeSound( void ) const
{	std::cout << "makeSound() - Miaou" << std::endl;	}

std::string	Cat::getType( void ) const
{	return (type);	}
