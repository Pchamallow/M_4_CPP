/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:21:51 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/01 14:40:31 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <iostream>


// = CONSTRUCTORS =====================================================

Bureaucrat:: Bureaucrat( void ) : _name(""), _grade(150) {}

Bureaucrat:: Bureaucrat( const std::string name ) : _name(name), _grade(150) {}

Bureaucrat:: Bureaucrat( const std::string name, const int grade ) : _name(name)
{
	if (!_checkGrade(grade))
		_grade = grade;
	else
		_grade = 150;
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
	if (!_checkGrade(_grade - 1))
		--_grade;
}

void	Bureaucrat::decrementGrade( void )
{
	if (!_checkGrade(_grade + 1))
		++_grade;
}

int	Bureaucrat::_checkGrade( int grade )
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
		return (1);
	}
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
		return (1);
	}
	return (0);
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