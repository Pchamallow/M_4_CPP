/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:59:49 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/21 17:13:56 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main ()
{
	ScavTrap a;
	ScavTrap b("Seb");
	FragTrap c("Vulkan");
	std::cout << std::endl;
	
	b.attack("Vulkan");
	c.takeDamage(10);
	c.takeDamage(10);
	c.beRepaired(10);
	b.attack("Vulkan");
	c.takeDamage(10);
	c.takeDamage(10);
	c.highFivesGuys();
	std::cout << std::endl;
}
