/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:58:16 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/15 13:30:41 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon() : type("") {}

Weapon::Weapon( std::string typeTarget ){
	type = typeTarget;
}

void	Weapon::setType ( std::string target )
{
	type = target;
}

const std::string&	Weapon::getType ( void )
{
	std::string& ref = type;
	return (ref);
}

