/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 17:02:43 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/22 17:45:34 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>


// = CONSTRUCTORS ==============================================

FragTrap:: FragTrap()
{	
	std::cout << "FragTrap - default constructor called" << std::endl;
	_name = "";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap:: FragTrap ( const FragTrap& other )
{	
	std::cout << "FragTrap - copy constructor called" << std::endl;
	(*this) = other;
}

FragTrap:: FragTrap( const std::string& name )
		: ClapTrap ( name )
{
	std::cout << "FragTrap - init constructor called" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap& FragTrap::operator=( const FragTrap& other )
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

FragTrap:: ~FragTrap()
{
	std::cout << "FragTrap - destructor called" << std::endl;
}



// = METHODS ===================================================

void	FragTrap::highFivesGuys( void )
{	std::cout << "FragTrap - " << _name << " gimme a high five !" << std::endl;	}

void	FragTrap::attack( const std::string& target )
{
	if (_hitPoints && _energyPoints)
	{
		std::cout << "FragTrap - ";
		std::cout << _name << " attacks " << target;
		std::cout << ", causing " << _attackDamage << " points of damage !";
		std::cout << std::endl;
		_energyPoints -= 1;
	}
	else
	{
		std::cout << "FragTrap - " << _name << " can't attack.";
		std::cout << std::endl;
	}
}
