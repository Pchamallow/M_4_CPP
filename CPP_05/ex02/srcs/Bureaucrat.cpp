/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:21:51 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/02 14:44:44 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include <iostream>
#define RED		"\033[31m"
#define RESET	"\033[0m"


// = CONSTRUCTORS =====================================================

Bureaucrat:: Bureaucrat( void ) : _name(""), _grade(150) {}

Bureaucrat:: Bureaucrat( const std::string name )
	: _name(name), _grade(150) {}

Bureaucrat:: Bureaucrat( const std::string name, const int grade )
	: _name(name)
{
	try {	setGrade(grade);	}
	catch (std::exception & e)
	{	std::cout << RED << e.what() << RESET << std::endl;	}
}
Bureaucrat:: Bureaucrat( const Bureaucrat& other )
{	(*this) = other;	}

Bureaucrat&		Bureaucrat::operator=( const Bureaucrat& other )
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

Bureaucrat:: ~Bureaucrat( void ) {}



// = MEMBER FUNCTIONS =================================================

std::string		Bureaucrat::getName( void ) const
{	return (_name);	}

int		Bureaucrat::getGrade( void ) const
{	return (_grade);	}

void	Bureaucrat::incrementGrade( void )
{
	try {	setGrade(_grade - 1);	}
	catch (std::exception & e)
	{	std::cout << RED << e.what() << RESET << std::endl;	}
}

void	Bureaucrat::decrementGrade( void )
{
	try {	setGrade(_grade + 1);	}
	catch (std::exception & e)
	{	std::cout << RED << e.what() << RESET << std::endl;	}
}

void	Bureaucrat::setGrade( int grade )
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
		return;
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
		return;
	}
	else
		_grade = grade;
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	form.execute(*this);
	std::cout << _name << " executed " << form.getName() << std::endl;
}


void	Bureaucrat::signForm( AForm & form )
{
	try
	{
		if (form.beSigned(*this))
		{	std::cout << _name << " signed " << form.getName() << "." << std::endl;	}
	}
	catch (std::exception & e)
	{
		std::cout << _name<< " couldn’t sign ";
		std::cout << form.getName() << " because ";
		std::cout << "bureaucrat grade is too low." << std::endl;
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

std::ostream&	operator<<( std::ostream& os, const Bureaucrat& other )
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl;
	return (os);
}

const char* Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Bureaucrat grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Bureaucrat grade is too low.");
}