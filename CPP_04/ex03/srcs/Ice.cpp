/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:09:37 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/26 10:45:40 by pswirgie         ###   ########.fr       */
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
{	std::cout << "copying the type doesn’t make sense" << std::endl;	}

Ice& Ice::operator=( const Ice& other )
{	std::cout << "copying the type doesn’t make sense" << std::endl;	}

Ice:: ~Ice()
{	std::cout << "A materia " << _type << " is destroyed" << std::endl;	}


// = METHODS ===================================================

std::string		Ice::getType( void ) const
{	return (_type);	}

AMateria*	Ice::clone() const
{	return (new Ice(*this));	}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}
