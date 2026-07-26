/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:09:37 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/26 12:10:05 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"
#include "iostream"


// = CONSTRUCTORS ==============================================

Ice:: Ice()
{	AMateria::_type = "ice";	}

Ice:: Ice( const Ice& other ) : AMateria(other)
{	*this = other;	}

Ice& Ice::operator=( const Ice& )
{	return (*this);	}

Ice:: ~Ice() {}


// = METHODS ===================================================

std::string		Ice::getType( void ) const
{	return (_type);	}

AMateria*	Ice::clone() const
{	return (new Ice(*this));	}

void	Ice::use(ICharacter& target)
{	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;	}
