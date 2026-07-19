/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 13:14:45 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/19 15:36:55 by pswirgie         ###   ########.fr       */
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
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra"
	" bacon for free." << std::endl;
	std::cout << "I’ve been coming for years, whereas"
	" you started working here just last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want"
	" to speak to the manager now !!!!!" << std::endl;
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

	if (i >= 4)
	{
		std::cout << "[ Probably complaining about insignificant"
		" problems ]" << std::endl;
		return ;
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
	}
}
