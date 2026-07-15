/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 13:08:27 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/15 14:12:40 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Weapon.hpp"

class HumanB{

	public :
		HumanB ( std::string humanName );

		void	attack( void );
		void	setWeapon(Weapon& weaponTarget);

	private :
		std::string	name;
		Weapon*		weapon;

};