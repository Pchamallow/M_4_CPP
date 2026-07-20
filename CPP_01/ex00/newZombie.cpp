/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:19:02 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/20 10:20:54 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>

Zombie	*newZombie( std::string name )
{
	Zombie *zombie;

	try { zombie = new Zombie(name); }
	catch ( const std::bad_alloc &e )
	{
		std::cout << "Error: newZombie - allocation of memory failed";
		std::cout << std::endl;
		exit (1);
	}
	return (zombie);
}