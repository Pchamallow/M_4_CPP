/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:09:37 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 17:25:03 by pswirgie         ###   ########.fr       */
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

Dog:: Dog( const Dog& other ) : Animal (other)
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

std::string	Dog::getType( void ) const
{	return (type);	}
