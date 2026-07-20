/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 23:39:37 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/20 10:20:48 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>

Zombie* zombieHorde( int N, std::string name )
{
	int i = 0;
	Zombie *zombie;
	
	try { zombie = new Zombie[N]; }
	catch  ( const std::bad_alloc &e )
	{
		std::cout << "Error: zombieHorde - allocation of memory failed";
		std::cout << std::endl;
		exit (1);
	}
		
	while (i < N)
	{
		zombie[i] = Zombie(name);
		i++;
	}
	return (zombie);
}
