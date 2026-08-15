/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 10:57:14 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/15 12:10:23 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/AForm.hpp"
#include <streambuf>
#include <iostream>
#include <fstream>
#include <cstdlib>
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define RESET	"\033[0m"


// = CONSTRUCTORS =====================================================

PresidentialPardonForm:: PresidentialPardonForm( void )
	: AForm("", 25, 5), _target("") {}

PresidentialPardonForm:: PresidentialPardonForm( std::string target )
	: AForm(target, 25, 5), _target(target) {}

PresidentialPardonForm:: PresidentialPardonForm( const PresidentialPardonForm& other )
{	(*this) = other;	}

PresidentialPardonForm&		PresidentialPardonForm::operator=( const PresidentialPardonForm& other )
{
	if (this != &other)
	{
		this->AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm:: ~PresidentialPardonForm( void ) {}


// = MEMBER FUNCTIONS =================================================

void	PresidentialPardonForm::_execute( void ) const
{
	std::cout << GREEN << _target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}
