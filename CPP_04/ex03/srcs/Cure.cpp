/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:39:42 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/26 15:52:23 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"
#include "iostream"


// = CONSTRUCTORS ==============================================

Cure:: Cure( void )
{	AMateria::_type = "cure";	}

Cure:: Cure( const Cure& other ) : AMateria(other)
{	*this = other;	}

Cure& Cure::operator=( const Cure& )
{	return (*this);	}

Cure:: ~Cure() {}


// = METHODS ===================================================

std::string		Cure::getType( void ) const
{	return (_type);	}

AMateria*	Cure::clone( void ) const
{	return (new Cure(*this));	}

void	Cure::use(ICharacter& target)
{	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;	}
