/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:09:37 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/26 10:45:40 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include "../includes/IMateriaSource.hpp"
#include "../includes/AMateria.hpp"
#include "iostream"


// = CONSTRUCTORS ==============================================

MateriaSource::	MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_source[i] = NULL;
}

MateriaSource::	MateriaSource( const MateriaSource& other )
{	*this = other;	}

MateriaSource&	MateriaSource::operator=( const MateriaSource& other )
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_source[i])
				delete this->_source[i];
			this->_source[i] = NULL;
			if (other._source[i])
				this->_source[i] = other._source[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::	~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_source[i])
			delete _source[i];
	}
}


// = METHODS ===================================================

void	MateriaSource::learnMateria( AMateria *other )
{
	for (int i = 0; i < 4; i++)
	{
		if (!_source[i])
		{
			_source[i] = other;
			return ;
		}
	}
	delete other;
}

AMateria*	MateriaSource::createMateria( std::string const & type )
{
	for (int i = 3; i >= 0; i--)
	{
		if (_source[i] && _source[i]->getType() == type)
			return (_source[i]->clone());
	}
	return (0);
}
