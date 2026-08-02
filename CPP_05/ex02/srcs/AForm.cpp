/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:23:02 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/02 14:59:13 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include <iostream>
#define RED		"\033[31m"
#define RESET	"\033[0m"


// = CONSTRUCTORS =====================================================

AForm:: AForm( void )
	: _name(""), _gradeSign(1), _gradeExec(1), _signed(false) {}

AForm:: AForm( const std::string name )
	: _name(name),  _gradeSign(1), _gradeExec(1), _signed(false) {}

AForm:: AForm( const std::string name, const int gradeSign)
	: _name(name), _gradeSign(gradeSign),_gradeExec(1), _signed(false)
{
	try {	checkGrade(_gradeSign);	}
	catch (std::exception & e)
	{	std::cout << RED << e.what() << RESET << std::endl;	}
}

AForm:: AForm( const std::string name, const int gradeSign, const int gradeExec )
	: _name(name), _gradeSign(gradeSign),_gradeExec(gradeExec), _signed(false)
{
	try {
		checkGrade(_gradeSign);
		checkGrade(_gradeExec);
	}
	catch (std::exception & e)
	{	std::cout << RED << e.what() << RESET << std::endl;	}
}

AForm:: AForm( const AForm& other ) 
	: _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec),
	_signed(other._signed)
{	(*this) = other;	}

AForm&		AForm::operator=( const AForm& )
{	return (*this);	}

AForm:: ~AForm( void ) {}



// = MEMBER FUNCTIONS =================================================

std::string		AForm::getName( void ) const
{	return (_name);	}

int		AForm::getGradeSign( void ) const
{	return (_gradeSign);	}

int		AForm::getGradeExec( void ) const
{	return (_gradeExec);	}

bool		AForm::getSigned( void ) const
{	return (_signed);	}

int	AForm::checkGrade( int grade ) const
{
	if (grade < 1)
	{
		throw AForm::GradeTooHighException();
		return (1);
	}
	else if (grade > 150)
	{
		throw AForm::GradeTooLowException();
		return (1);
	}
	return (0);
}

bool	AForm::beSigned( Bureaucrat& executor )
{
	if (executor.getGrade() > _gradeSign)
	{
		throw AForm::GradeTooLowException();
		return (false);
	}
	_signed = true;
	return (true);
}

void	AForm::execute( Bureaucrat const & ) const {}

std::ostream&	operator<<( std::ostream& os, const AForm& other )
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

const char* AForm::GradeTooHighException::what( void ) const throw()
{	return ("AForm grade is too high.");	}

const char* AForm::GradeTooLowException::what( void ) const throw()
{	return ("AForm grade is too low.");	}

const char* AForm::ExecutorGradeTooLowException::what( void ) const throw()
{	return ("Executor grade is too low.");	}

const char* AForm::FormAlreadySigned::what( void ) const throw()
{	return ("AForm is already signed.");	}