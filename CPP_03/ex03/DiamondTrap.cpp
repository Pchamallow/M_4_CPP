/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:25:46 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/22 17:50:44 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>


// = CONSTRUCTORS ==============================================

DiamondTrap:: DiamondTrap()
{	
	std::cout << "DiamondTrap - default constructor called" << std::endl;
	_name = "";
	_hitPoints = FragTrap:: _hitPoints;
	_energyPoints = ScavTrap:: _energyPoints;
	_attackDamage = 30;
}

DiamondTrap:: DiamondTrap ( const DiamondTrap& other ) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{	
	std::cout << "DiamondTrap - copy constructor called" << std::endl;
	(*this) = other;
}

DiamondTrap:: DiamondTrap( const std::string& name )
		: FragTrap ( name ), ScavTrap ( name )
{
	std::cout << "DiamondTrap - init constructor called" << std::endl;
	_name = name;
	_hitPoints = FragTrap:: _hitPoints;
	_energyPoints = ScavTrap:: _energyPoints;
	_attackDamage = 30;
	ClapTrap::_name = name + "_clap_name";
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& other )
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

DiamondTrap:: ~DiamondTrap()
{	std::cout << "DiamondTrap - destructor called" << std::endl;	}



// = METHODS ===================================================

void	DiamondTrap::attack( const std::string& target )
{	ScavTrap:: attack(target);	}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << _name << " and ";
	std::cout << ClapTrap:: _name << std::endl;
}

int	DiamondTrap::getHitPoints( void ) const
{	return (_hitPoints);	}

int	DiamondTrap::getEnergyPoints( void ) const
{	return (_energyPoints);	}

int	DiamondTrap::getAttackDamage( void ) const
{	return (_attackDamage);	}
