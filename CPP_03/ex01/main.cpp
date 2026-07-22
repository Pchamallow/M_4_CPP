/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:59:49 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/22 18:01:13 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main ()
{
	ScavTrap a;
	ScavTrap b("Seb");
	ClapTrap c("Vulkan");
	ScavTrap e(b);
	ClapTrap f(c);
	std::cout << std::endl;
	
	b.attack("Vulkan");
	c.takeDamage(20);
	c.beRepaired(10);
	b.attack("Vulkan");
	b.guardGate();
	std::cout << "ScavTrap copy - Seb's sibling appeares." << std::endl;
	e.beRepaired(5);
	std::cout << "ClapTrap copy - Vulkan's copy appeares." << std::endl;
	f.beRepaired(5);
	std::cout << std::endl;
}
