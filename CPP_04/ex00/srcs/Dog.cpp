/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:09:37 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/26 16:34:46 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "iostream"


// = CONSTRUCTORS ==============================================

Dog:: Dog()
{	
	Animal::type = "Dog";
	std::cout << "A " << type << " is born" << std::endl;
}

Dog:: Dog( const Dog& other ) : Animal( other )
{
	(*this) = other;
	std::cout << "A twin " << type << " is created" << std::endl;
}

Dog& Dog::operator=( const Dog& other )
{
	if (this != &other)
	{	Animal::type = other.type;	}
	std::cout << "A new same " << type << " is created" << std::endl;
	return (*this);
}

Dog:: ~Dog()
{	std::cout << "A " << type << " is leaving" << std::endl;	}


// = METHODS ===================================================

void	Dog::makeSound( void ) const
{	std::cout << "makeSound() - Ouaf" << std::endl;	}

std::string	Dog::getType( void ) const
{	return (type);	}
