/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:21:51 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/16 08:54:23 by pswirgie         ###   ########.fr       */
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

Intern&		Intern::operator=( const Intern& )
{	return (*this);	}

Intern:: ~Intern( void ) {}


// = MEMBER FUNCTIONS =================================================

AForm* Intern::newRobotomyRequest( const std::string& target ) const
{	return (new RobotomyRequestForm(target));	}

AForm* Intern::newPresidentialPardon( const std::string& target ) const
{	return (new PresidentialPardonForm(target));	}

AForm* Intern::newShrubberyCreation( const std::string& target ) const
{	return (new ShrubberyCreationForm(target));	}

AForm*	Intern::makeForm( const std::string& formName, const std::string& formeTarget ) const
{
	static const std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	
	AForm *(Intern::*formPtr[3])(const std::string&) const = {
		&Intern::newRobotomyRequest,
		&Intern::newPresidentialPardon,
		&Intern::newShrubberyCreation,
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formeTarget << "." << std::endl;
			return (this->*formPtr[i])(formeTarget);
		}
	}
	try{
		throw FormNotFound();
	}
	catch(std::invalid_argument &e)
	{
		std::cerr << RED << "Intern can't create because " << e.what() << RESET << std::endl;
		return (NULL);
	}
}

Intern::FormNotFound::FormNotFound()
	:invalid_argument(RED "Form not found." RESET)
{}
