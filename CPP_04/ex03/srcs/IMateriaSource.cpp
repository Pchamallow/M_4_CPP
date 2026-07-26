/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:09:37 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 18:22:44 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/IMateriaSource.hpp"
#include "iostream"


// = CONSTRUCTORS ==============================================

IMateriaSource:: IMateriaSource()
{
}

IMateriaSource:: IMateriaSource( const IMateriaSource& other )
{
	*this = other;
}

IMateriaSource& IMateriaSource::operator=( const IMateriaSource& other )
{
	if (this != &other)
	{
		_type = other._type;
		std::cout << "A new same materia " << _type << " is created" << std::endl;
	}
	return (*this);
}

IMateriaSource:: ~IMateriaSource()
{
	std::cout << "A materia " << _type << " is destroyed" << std::endl;
}


// = METHODS ===================================================


std::string	const & IMateriaSource::getType( void ) const
{	return (_type);	}

void IMateriaSource::use(ICharacter& target)
{	return ;	}
