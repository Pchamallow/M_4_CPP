/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:09:37 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 17:18:40 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "iostream"


// = CONSTRUCTORS ==============================================

Cat:: Cat()
{
	Animal::type = "Cat";
	_brain = new Brain();
	std::cout << "A " << type << " is born" << std::endl;
}

Cat:: Cat( const Cat& other )
{
	*this = other;
	std::cout << "A twin " << type << " is created" << std::endl;
}

Cat& Cat::operator=( const Cat& other )
{
	if (this != &other)
	{
		Animal::type = other.type;
		delete _brain;
		_brain = new Brain(*other._brain);
		std::cout << "A new same " << type << " is created" << std::endl;
	}
	return (*this);
}

Cat:: ~Cat()
{
	delete _brain;
	std::cout << "A " << type << " is leaving" << std::endl;
}


// = METHODS ===================================================

void	Cat::makeSound( void ) const
{	std::cout << "makeSound() - Miaou" << std::endl;	}

void	Cat::setIdea( int index, std::string content )
{	_brain->setIdea(index, content);	}

std::string	Cat::getIdea( int index ) const
{	return (_brain->getIdea(index));	}

std::string	Cat::getType( void ) const
{	return (type);	}
