/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:09:37 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/26 09:45:55 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "iostream"


// = CONSTRUCTORS ==============================================

Ice:: Ice()
{
	AMateria::_type = "ice";
	std::cout << "A materia " << _type << " is created" << std::endl;
}

Ice:: Ice( const Ice& other ) : AMateria(other)
{
	*this = other;
	std::cout << "A copy of materia " << _type << " is created" << std::endl;
}

Ice& Ice::operator=( const Ice& other )
{
	if (this != &other)
	{
		AMateria::_type = other._type;
		std::cout << "A new same materia " << _type << " is created" << std::endl;
	}
	return (*this);
}

Ice:: ~Ice()
{
	std::cout << "A materia " << _type << " is used" << std::endl;
}


// = METHODS ===================================================

void	Ice::makeSound( void ) const
{	std::cout << "makeSound() - Miaou" << std::endl;	}

void	Ice::setIdea( int index, std::string content )
{
	if (index >= 0 && index < 100)
		_brain->setIdea(index, content);
	else
		std::cout << "Invalid neuron range, only allowed between: [0, 99]" << std::endl;
}

std::string	Ice::getIdea( int index ) const
{
	if (index >= 0 && index < 100)
		return (_brain->getIdea(index));
	else
		std::cout << "Invalid neuron range, only allowed between: [0, 99]" << std::endl;
	return ("");
}

std::string	Ice::getType( void ) const
{	return (_type);	}
