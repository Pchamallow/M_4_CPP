/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:59:52 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/21 14:02:15 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	private:
		int				_hitPoints;
		int				_energyPoints;
		int				_attackDamage;
		std::string		_name;

};