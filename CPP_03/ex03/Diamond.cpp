/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Diamond.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:25:46 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/22 17:50:44 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Diamond.hpp"
#include <iostream>


// = CONSTRUCTORS ==============================================

Diamond:: Diamond()
{	
	std::cout << "Diamond - default constructor called" << std::endl;
	_name = "";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

Diamond:: Diamond ( const Diamond& other )
{	
	std::cout << "Diamond - copy constructor called" << std::endl;
	(*this) = other;
}

Diamond:: Diamond( const std::string& name )
		: ClapTrap ( name )
{
	std::cout << "Diamond - init constructor called" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

Diamond& Diamond::operator=( const Diamond& other )
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

Diamond:: ~Diamond()
{
	std::cout << "Diamond - destructor called" << std::endl;
}



// = METHODS ===================================================


void	Diamond::attack( const std::string& target )
{
	if (_hitPoints && _energyPoints)
	{
		std::cout << "Diamond - ";
		std::cout << _name << " attacks " << target;
		std::cout << ", causing " << _attackDamage << " points of damage !";
		std::cout << std::endl;
		_energyPoints -= 1;
	}
	else
	{
		std::cout << "Diamond - " << _name << " can't attack.";
		std::cout << std::endl;
	}
}

void	Diamond::whoAmI()
{
	std::cout << "I am " << //diamond name << " and ";
	std::cout << //claptrap name << std::endl;
}
