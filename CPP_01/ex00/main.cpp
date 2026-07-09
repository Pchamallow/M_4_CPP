/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:17:55 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/09 10:45:40 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"

int	main( void )
{
	Zombie *zombie;
	zombie = newZombie("Eustache");
	delete zombie;

	Zombie zombie2("Michell");
	zombie2.announce();
}
