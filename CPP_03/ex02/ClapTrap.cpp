/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:59:54 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/21 16:53:48 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>


// = CONSTRUCTORS ==============================================

ClapTrap:: ClapTrap ()
{
	std::cout << "ClapTrap - default constructor called" << std::endl;
	_name = "";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap:: ClapTrap ( const std::string& name )
{
	std::cout << "ClapTrap - init constructor called" << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other )
{
	if (this != &other)
	{
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
		this->_name = other._name;
	}
	return (*this);
}

ClapTrap:: ~ClapTrap()
{
	std::cout << "ClapTrap - destructor called" << std::endl;
}




// = METHODS ===================================================

void	ClapTrap::attack( const std::string& target )
{
	if (_hitPoints && _energyPoints)
	{
		std::cout << "ClapTrap - ";
		std::cout << _name << " attacks " << target;
		std::cout << ", causing " << _attackDamage << " points of damage !";
		std::cout << std::endl;
		_energyPoints -= 1;
	}
	else
	{
		std::cout << "ClapTrap - " << _name << " can't attack.";
		std::cout << std::endl;
	}
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	int points = amount;
	if ((int)amount > _hitPoints)
		points = _hitPoints;
	if (_hitPoints && points)
	{
		std::cout << "ClapTrap - " << _name << " take ";
		std::cout << points << " points of damage !";
		std::cout << std::endl;
		_hitPoints -= points;
		if (!_hitPoints)
		{
			std::cout << "ClapTrap - " << _name << " died.";
			std::cout << std::endl;
		}
	}
	else if (!_hitPoints)
	{
		std::cout << "ClapTrap - " << _name << "'s corpse take ";
		std::cout << amount << " points of damage !";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "ClapTrap - " << _name << " can' t take damage.";
		std::cout << std::endl;
	}
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (_hitPoints && _energyPoints)
	{
		std::cout << "ClapTrap - " << _name << " repairs itself, it regains ";
		std::cout << amount << " hit points !";
		std::cout << std::endl;
		_energyPoints -= 1;
		_hitPoints += amount;
	}
	else
	{
		std::cout << "ClapTrap - " << _name << " can't repair itself.";
		std::cout << std::endl;
	}
}
