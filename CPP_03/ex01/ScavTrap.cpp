/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:25:46 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/22 17:57:05 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>


// = CONSTRUCTORS ==============================================

ScavTrap:: ScavTrap()
{	
	std::cout << "ScavTrap - default constructor called" << std::endl;
	_name = "";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap:: ScavTrap ( const ScavTrap& other )
{	
	std::cout << "ScavTrap - copy constructor called" << std::endl;
	(*this) = other;
}

ScavTrap:: ScavTrap( const std::string& name )
		: ClapTrap ( name )
{
	std::cout << "ScavTrap - default constructor called" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& other )
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

ScavTrap:: ~ScavTrap()
{
	std::cout << "ScavTrap - destructor called" << std::endl;
}



// = METHODS ===================================================

void	ScavTrap::guardGate()
{	std::cout << "ScavTrap - " << _name << " is now in Gate keeper mode." << std::endl;	}

void	ScavTrap::attack( const std::string& target )
{
	if (_hitPoints && _energyPoints)
	{
		std::cout << "ScavTrap - ";
		std::cout << _name << " attacks " << target;
		std::cout << ", causing " << _attackDamage << " points of damage !";
		std::cout << std::endl;
		_energyPoints -= 1;
	}
	else
	{
		std::cout << "ScavTrap - " << _name << " can't attack.";
		std::cout << std::endl;
	}
}
