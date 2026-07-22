/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:59:49 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/22 18:01:36 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main ()
{
	{
		std::cout << "Seb attack -> Vulkan died" <<std::endl;
		ClapTrap a;
		ClapTrap b("Seb");
		ClapTrap c("Vulkan");
	
		b.attack("Vulkan");
		c.takeDamage(10);
		c.beRepaired(10);
	}
	{
		std::cout << std::endl;
		std::cout << "Seb attack -> Vulkan lives" <<std::endl;
		ClapTrap a;
		ClapTrap b("Seb");
		ClapTrap c("Vulkan");
	
		b.attack("Vulkan");
		c.takeDamage(3);
		c.beRepaired(5);
	}
	{
		std::cout << std::endl;
		std::cout << "Seb attack x 10 -> can t repair itself due to a lack of hit points" <<std::endl;
		ClapTrap b("Seb");
	
		b.attack("Vulkan");
		b.attack("Vulkan");
		b.attack("Vulkan");
		b.attack("Vulkan");
		b.attack("Vulkan");
		b.attack("Vulkan");
		b.attack("Vulkan");
		b.attack("Vulkan");
		b.attack("Vulkan");
		b.attack("Vulkan");
		b.attack("Vulkan");
		b.attack("Vulkan");
		b.attack("Vulkan");
		b.attack("Vulkan");
		b.attack("Vulkan");
		b.beRepaired(5);
	}
	{
		std::cout << std::endl;
		ClapTrap c("Vulkan");
		ClapTrap f(c);

		std::cout << "ClapTrap copy - Vulkan's copy appeares." << std::endl;
		f.beRepaired(5);
	}
}
