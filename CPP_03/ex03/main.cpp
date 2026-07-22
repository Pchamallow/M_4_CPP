/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:59:49 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/22 18:09:40 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "Diamond.hpp"
#include <iostream>

int main ()
{
	{
		std::cout << "TESTS - INITIALISATION - DIAMOND" << std::endl;
		Diamond	a;
		Diamond	b("Mish");
		Diamond	c(b);
		Diamond	d = c;
		std::cout << std::endl;
	}
	{
		std::cout << "TESTS - FIGHT" << std::endl;
		ScavTrap	a("Seb");
		Diamond		b("Vulkan");
		
		a.attack("Vulkan");
		b.takeDamage(20);



		
		std::cout << std::endl;
	}
	
	

}
