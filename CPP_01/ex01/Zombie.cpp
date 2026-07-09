/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:23:29 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/08 23:18:14 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() : name("") {}

Zombie::Zombie( std::string zombieName){
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
