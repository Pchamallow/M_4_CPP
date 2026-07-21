/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:59:52 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/21 16:51:14 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap( const std::string& name );
		ClapTrap& operator=( const ClapTrap& other );
		~ClapTrap();

		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

	protected: // permet aux enfants d avoir les atrributes privess de la class parents
		int				_hitPoints;
		int				_energyPoints;
		int				_attackDamage;
		std::string		_name;
};