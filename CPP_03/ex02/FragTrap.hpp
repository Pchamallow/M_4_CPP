/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 17:03:52 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 10:18:29 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public :
		FragTrap();
		FragTrap( const FragTrap& other);
		FragTrap( const std::string& name );
		FragTrap& operator=( const FragTrap& other );
		~FragTrap();

		void	attack( const std::string& target );
		void	highFivesGuys( void );
};
