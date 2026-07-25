/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:59:49 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 10:34:42 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main ()
{
	{
		DiamondTrap	a;
		DiamondTrap	b("Mish");
		DiamondTrap	c(b);
		DiamondTrap	d = c;
		
		std::cout << std::endl;
		std::cout << "TESTS - INITIALISATION - DIAMOND" << std::endl;
		std::cout << "hit points : " << b.getHitPoints() << std::endl;
		std::cout << "energy points : " << b.getEnergyPoints() << std::endl;
		std::cout << "attack damage : " << b.getAttackDamage() << std::endl;
		b.attack("Vulkan");
		std::cout << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << "TESTS - FIGHT" << std::endl;
		ScavTrap	a("Seb");
		DiamondTrap	b("Vulkan");

		a.attack("Vulkan");
		b.takeDamage(20);
		b.attack("Seb");

		std::cout << std::endl;
		ClapTrap c = DiamondTrap ("Gael");
		std::cout << std::endl;
		std::cout << "TESTS - CONVERT CLAP TO DIAMOND - WHO I AM" << std::endl;
		c.takeDamage(1);
		std::cout << "Who I am = ";
		b.whoAmI();
		std::cout << std::endl;
	}
}
