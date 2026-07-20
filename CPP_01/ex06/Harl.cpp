/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 13:14:45 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/20 11:10:03 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Harl.hpp"
#include <iostream>

Harl:: Harl ()
{}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for"
	" my 7XL-double-cheese-triple-pickle-special-"
	"ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
	std::cout << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding"
	" extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in"
	"my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t"
	" be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra"
	" bacon for free." << std::endl;
	std::cout << "I’ve been coming for years, whereas"
	" you started working here just last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want"
	" to speak to the manager now !!!!!" << std::endl;
	std::cout << std::endl;
}

void	Harl::complain( std::string level )
{
	std::string array[4] = {"DEBUG", "INFO","WARNING", "ERROR"};

	void	(Harl::*arrayLevels[4])(void) = {
		&Harl::debug, &Harl::info,
		&Harl::warning, &Harl::error
	};

	int i = 0;
	while (i < 4)
	{
		if (level == array[i])
			break;
		++i;
	}

	switch (i)
	{
		case 0:
			(this->*arrayLevels[0])();
		case 1:
			(this->*arrayLevels[1])();
		case 2:
			(this->*arrayLevels[2])();
		case 3:
			(this->*arrayLevels[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant"
				" problems ]" << std::endl;
	}
}
