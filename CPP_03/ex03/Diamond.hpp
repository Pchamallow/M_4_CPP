/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Diamond.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:06:14 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/22 18:15:35 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"
#include <string>

class Diamond : public FragTrap, public ScavTrap
{
	public :
		Diamond();
		Diamond( const Diamond& other );
		Diamond( const std::string& name );
		Diamond& operator=( const Diamond& other );
		~Diamond();

		void	attack( const std::string& target );
		void	whoAmI();
	
	private :
		ClapTrap	_name;
};
