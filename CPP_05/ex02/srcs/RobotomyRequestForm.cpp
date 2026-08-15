/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 10:57:14 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/15 12:28:13 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/AForm.hpp"
#include <streambuf>
#include <iostream>
#include <fstream>
#include <cstdlib>
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define RESET	"\033[0m"


// = CONSTRUCTORS =====================================================

RobotomyRequestForm:: RobotomyRequestForm( void )
	: AForm("robotomy request", 72, 45), _target("") {}

RobotomyRequestForm:: RobotomyRequestForm( std::string target )
	: AForm("robotomy request", 72, 45), _target(target) {}

RobotomyRequestForm:: RobotomyRequestForm( const RobotomyRequestForm& other )
{	(*this) = other;	}

RobotomyRequestForm&		RobotomyRequestForm::operator=( const RobotomyRequestForm& other )
{
	if (this != &other)
	{
		this->AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm:: ~RobotomyRequestForm( void ) {}


// = MEMBER FUNCTIONS =================================================

void	RobotomyRequestForm::_execute( void ) const
{
	std::cout << GREEN << " ~ bip bip bop bop ~ " << RESET << std::endl;
	srand (time(NULL));
	int ret = rand() % 2;
	if (ret)
		std::cout << GREEN << _target << " has been robotomized successfully." << RESET << std::endl;
	else
		std::cout << RED << "Robotomy failed." << RESET << std::endl;
}
