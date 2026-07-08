/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:23:29 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/08 18:06:22 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

Zombie::Zombie( std::string zombieName){
	name = zombieName;
}

Zombie::~Zombie(){
	std::cout << name << "is lying on the ground, inanimate";
	std::cout << std::endl;
}

void	Zombie::annouce( void ){
	std::cout << name << ": BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}

// Zombie&	Zombie::operator= (const Zombie& other){
// 	this->name = other.name;
// }
