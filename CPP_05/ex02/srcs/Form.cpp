/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:23:02 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/01 16:12:16 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include <iostream>
#define RED		"\033[31m"
#define RESET	"\033[0m"


// = CONSTRUCTORS =====================================================

Form:: Form( void )
	: _name(""), _gradeSign(1), _gradeExec(1), _signed(false) {}

Form:: Form( const std::string name )
	: _name(name),  _gradeSign(1), _gradeExec(1), _signed(false) {}

Form:: Form( const std::string name, const int gradeSign)
	: _name(name), _gradeSign(gradeSign),_gradeExec(1), _signed(false)
{
	try {	checkGrade(_gradeSign);	}
	catch (std::exception & e)
	{	std::cout << RED << e.what() << RESET << std::endl;	}
}

Form:: Form( const std::string name, const int gradeSign, const int gradeExec )
	: _name(name), _gradeSign(gradeSign),_gradeExec(gradeExec), _signed(false)
{
	try {
		checkGrade(_gradeSign);
		checkGrade(_gradeExec);
	}
	catch (std::exception & e)
	{	std::cout << RED << e.what() << RESET << std::endl;	}
}

Form:: Form( const Form& other ) 
	: _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec),
	_signed(other._signed)
{	(*this) = other;	}

Form&		Form::operator=( const Form& )
{	return (*this);	}

Form:: ~Form( void ) {}



// = MEMBER FUNCTIONS =================================================

std::string		Form::getName( void ) const
{	return (_name);	}

int		Form::getGradeSign( void ) const
{	return (_gradeSign);	}

int		Form::getGradeExec( void ) const
{	return (_gradeExec);	}

bool		Form::getSigned( void ) const
{	return (_signed);	}

int	Form::checkGrade( int grade ) const
{
	if (grade < 1)
	{
		throw Form::GradeTooHighException();
		return (1);
	}
	else if (grade > 150)
	{
		throw Form::GradeTooLowException();
		return (1);
	}
	return (0);
}

bool	Form::beSigned( Bureaucrat& bureaucrat )
{
	if (bureaucrat.getGrade() > _gradeSign)
	{
		throw Form::GradeTooLowException();
		return (false);
	}
	_signed = true;
	return (true);
}

std::ostream&	operator<<( std::ostream& os, const Form& other )
{
	os << "The ";
	if (other.getSigned())
		os << "signed ";
	else
		os << "unsigned ";
	os << other.getName() << " document, grade required to sign is ";
	os << other.getGradeSign() << " and to execute is ";
	os << other.getGradeExec() << "." << std::endl;
	return (os);
}

const char* Form::GradeTooHighException::what( void ) const throw()
{	return ("Form grade is too high.");	}

const char* Form::GradeTooLowException::what( void ) const throw()
{	return ("Form grade is too low.");	}