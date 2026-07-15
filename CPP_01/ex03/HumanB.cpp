/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 13:16:35 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/15 14:08:59 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB ( std::string humanName )
	: name(humanName)
{
	weapon = NULL;
}

void	HumanB::attack( void )
{
	std::cout << name << " attacks with their " << (*weapon).getType();
	std::cout << std::endl;
}

void	HumanB::setWeapon (Weapon weaponTarget )
{
	weapon = &weaponTarget;
}