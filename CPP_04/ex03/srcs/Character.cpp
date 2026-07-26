/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:09:37 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/26 10:45:40 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/AMateria.hpp"
#include "iostream"


// = CONSTRUCTORS ==============================================

Character::	Character()
{
	_name = "unknown";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::	Character( const std::string name ) : _name( name )
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::	Character( const Character& other )
{	*this = other;	}

Character&	Character::operator=( const Character& other )
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = NULL;
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
		}
	}
	return (*this);
}

Character::	~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}


// = METHODS ===================================================

std::string const	&Character::getName() const
{	return (_name);	}

void	Character::equip( AMateria* m )
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m->clone();
			return ;
		}
	}
}

void	Character::unequip( int idx )
{
	if (idx >= 0 && idx < 4)
		_inventory[idx] = NULL;
}

void	Character::use( int idx, ICharacter& target )
{
	if (idx >= 0 && idx < 4)
		(*_inventory[idx]).use(target);
}

