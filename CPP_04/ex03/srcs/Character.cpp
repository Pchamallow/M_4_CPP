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

AMateria*	Character::_floor[50] = {NULL};

// = CONSTRUCTORS ==============================================

Character::	Character( void )
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

Character::	Character( const Character& other ): _name( "" ), _inventory()
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

Character::	~Character( void )
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}


// = METHODS ===================================================

std::string const	&Character::getName() const
{	return (_name);	}

AMateria*	Character::getFloor( int idx ) const
{
	if (idx >= 0 && idx < 50 && _floor[idx])
		return (_floor[idx]);
	return (0);
}

AMateria*	Character::getInventory( int idx ) const
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		return (_inventory[idx]);
	return (0);
}

void	Character::equip( AMateria* m )
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
	delete m;
}

void	Character::unequip( int idx )
{
	if (idx >= 0 && idx < 4)
	{
		for (int i = 0; i < 50; i++)
		{
			if (!_floor[i])
			{
				_floor[i] = _inventory[idx];
				break ;
			}
		}
		_inventory[idx] = NULL;
	}
}

void	Character::use( int idx, ICharacter& target )
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		(*_inventory[idx]).use(target);
}

void	Character::clearFloor( void )
{
	for (int i = 0; i < 50; i++)
	{
		if (_floor[i])
		{
			delete _floor[i];
			_floor[i] = NULL;
		}
	}
}
