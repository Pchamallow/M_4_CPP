/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 13:16:35 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/15 13:29:09 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA:: HumanA ( std::string humanName, Weapon weaponTarget )
{
	name = humanName;
	weapon = weaponTarget;
}

void	HumanA::attack( void )
{
	std::cout << name << " attacks with their " << weapon.getType();
	std::cout << std::endl;
	
}