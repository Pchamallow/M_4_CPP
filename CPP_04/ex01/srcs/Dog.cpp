/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:09:37 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 17:53:56 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Animal.hpp"
#include "iostream"


// = CONSTRUCTORS ==============================================

Dog:: Dog()
{	
	Animal::type = "Dog";
	_brain = new Brain();
	std::cout << "A " << type << " is born" << std::endl;
}

Dog:: Dog( const Dog& other ) : Animal (other), _brain(NULL)
{
	*this = other;
	std::cout << "A twin " << type << " is created" << std::endl;
}

Dog& Dog::operator=( const Dog& other )
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

Dog:: ~Dog()
{
	delete _brain;
	std::cout << "A " << type << " is leaving" << std::endl;
}


// = METHODS ===================================================

void	Dog::makeSound( void ) const
{	std::cout << "makeSound() - Ouaf" << std::endl;	}

void	Dog::setIdea( int index, std::string content )
{
	if (index >= 0 && index < 100)
		_brain->setIdea(index, content);
	else
		std::cout << "Invalid neuron range, only allowed between: [0, 99]" << std::endl;
}

std::string	Dog::getIdea( int index ) const
{
	if (index >= 0 && index < 100)
		return (_brain->getIdea(index));
	else
		std::cout << "Invalid neuron range, only allowed between: [0, 99]" << std::endl;
	return ("");
}

std::string	Dog::getType( void ) const
{	return (type);	}
