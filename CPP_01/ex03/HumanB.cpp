/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 13:16:35 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/15 14:23:53 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB ( std::string humanName )
	: name(humanName), weapon(NULL)
{}

void	HumanB::attack( void )
{
	std::cout << name;
	if (weapon)
		std::cout << " attacks with their " << weapon->getType();
	else
		std::cout << " attacks with a punch";
	std::cout << std::endl;
}

/* take adress of reference -> take original */
void	HumanB::setWeapon ( Weapon& weaponTarget )
{
	weapon = &weaponTarget;
}