/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:09:37 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 18:22:44 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "iostream"


// = CONSTRUCTORS ==============================================

AMateria::	AMateria( std::string const & type )
{	_type = type;	}

AMateria::	AMateria()
{	_type = "DEFAULT";	}

AMateria::	AMateria( const AMateria& other )
{	*this = other;	}

AMateria&	AMateria::operator=( const AMateria& other )
{
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

AMateria::	~AMateria(){}


// = METHODS ===================================================


std::string	const	&AMateria::getType( void ) const
{	return (_type);	}

void	AMateria::use( ICharacter& ) {}
