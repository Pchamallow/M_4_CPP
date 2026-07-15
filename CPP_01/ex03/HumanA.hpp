/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 13:08:27 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/15 13:54:02 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Weapon.hpp"

class HumanA{

	public :
		HumanA ( std::string humanName, Weapon& weaponTarget );

		void	attack( void );

	private :
		std::string	name;
		Weapon&		weapon;

};