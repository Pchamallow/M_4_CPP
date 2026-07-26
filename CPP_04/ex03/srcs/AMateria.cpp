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

AMateria:: AMateria()
{
	_type = "DEFAULT";
	std::cout << "A materia " << _type << " is created" << std::endl;
}

AMateria:: AMateria( const AMateria& other )
{
	*this = other;
	std::cout << "A copy of materia " << _type << " is created" << std::endl;
}

AMateria& AMateria::operator=( const AMateria& other )
{
	if (this != &other)
	{
		_type = other._type;
		std::cout << "A new same materia " << _type << " is created" << std::endl;
	}
	return (*this);
}

AMateria:: ~AMateria()
{
	std::cout << "A materia " << _type << " is destroyed" << std::endl;
}


// = METHODS ===================================================


std::string	const & AMateria::getType( void ) const
{	return (_type);	}
