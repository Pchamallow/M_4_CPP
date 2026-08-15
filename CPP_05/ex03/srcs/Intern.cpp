/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:21:51 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/15 13:43:56 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include <iostream>
#define RED		"\033[31m"
#define RESET	"\033[0m"


// = CONSTRUCTORS =====================================================

Intern:: Intern( void ) {}

Intern:: Intern( const Intern& other )
{	(*this) = other;	}

Intern&		Intern::operator=( const Intern& other )
{	return (*this);	}

Intern:: ~Intern( void ) {}


// = MEMBER FUNCTIONS =================================================

AForm* Intern::newRobotomyRequest( const std::string& target )
{	return (new RobotomyRequestForm(target));	}

AForm* Intern::newPresidentialPardon( const std::string& target )
{	return (new PresidentialPardonForm(target));	}

AForm* Intern::newShrubberyCreaction( const std::string& target )
{	return (new ShrubberyCreationForm(target));	}

AForm*	Intern::makeForm( const std::string& formName, const std::string& formeTarget ) const
{
	static const std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	
	AForm *(Intern::*formPtr)(std::string&) = {
		&Intern::newRobotomyRequest,
		&Intern::newPresidentialPardon,
		&Intern::newShrubberyCreaction,
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formNames[i] = formName)
		{
			//message
			std::cout << "Intern creates " << formeTarget
			return (this->formPtr[i](formeTarget));
		}
	}

	// thrown error message
}

Intern::FormNotFound::FormNotFound()
	:invalid_argument(RED "Form not found." RESET)
{}
