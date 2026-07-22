/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 17:03:52 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/22 17:52:37 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
