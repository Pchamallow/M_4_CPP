/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:06:14 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/22 18:05:32 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public :
		ScavTrap();
		ScavTrap( const ScavTrap& other );
		ScavTrap( const std::string& name );
		ScavTrap& operator=( const ScavTrap& other );
		~ScavTrap();

		void	attack( const std::string& target );
		void	guardGate();
};
