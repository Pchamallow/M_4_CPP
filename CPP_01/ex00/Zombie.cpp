/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:23:29 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/09 10:46:15 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>
#include <string>

Zombie::Zombie( std::string zombieName ){
	name = zombieName;
}

Zombie::~Zombie(){
	std::cout << name << " is lying on the ground, inanimate";
	std::cout << std::endl;
}

void	Zombie::announce( void ){
	std::cout << name << ": BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}

Zombie&	Zombie::operator= (const Zombie& other){
	if (this != &other)
		this->name = other.name;
	return (*this);
}
