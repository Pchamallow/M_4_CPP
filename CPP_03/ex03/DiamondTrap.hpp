/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:06:14 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/24 13:07:25 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
	public :
		DiamondTrap();
		DiamondTrap( const DiamondTrap& other );
		DiamondTrap( const std::string& name );
		DiamondTrap& operator=( const DiamondTrap& other );
		~DiamondTrap();

		int	getHitPoints ( void ) const;
		int	getEnergyPoints( void ) const;
		int	getAttackDamage( void ) const;

		void	attack( const std::string& target );
		void	whoAmI();
	
	private :
		std::string			_name;
		int					_hitPoints;
		int					_energyPoints;
		int					_attackDamage;
};
