/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:23:02 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/02 15:01:04 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/AForm.hpp"
#include <streambuf>
#include <iostream>
#include <fstream>
#define RED		"\033[31m"
#define RESET	"\033[0m"


// = CONSTRUCTORS =====================================================

ShrubberyCreationForm:: ShrubberyCreationForm( void )
	: AForm("", 145, 137) {}

ShrubberyCreationForm:: ShrubberyCreationForm( std::string target )
	: AForm("", 145, 137), _target(target) {}

ShrubberyCreationForm:: ShrubberyCreationForm( const ShrubberyCreationForm& other ) 
	: AForm(other)
{	(*this) = other;	}

ShrubberyCreationForm&		ShrubberyCreationForm::operator=( const ShrubberyCreationForm& )
{	return (*this);	}

ShrubberyCreationForm:: ~ShrubberyCreationForm( void ) {}


// = MEMBER FUNCTIONS =================================================

void	ShrubberyCreationForm::execute( Bureaucrat const& executor ) const
{
	try 
	{
		if (!AForm::_signed)
		{
			if (executor.getGrade() > _gradeExec || executor.getGrade() > _gradeSign)
				throw AForm::ExecutorGradeTooLowException();
			else 
				writeForm(executor);
		}
		else
			throw AForm::FormAlreadySigned();
	}
	catch (std::exception &e)
	{	std::cout << RED << e.what() << RESET << std::endl;	}
}

void	ShrubberyCreationForm::writeForm( Bureaucrat const& executor )
{
	std::string nameFile = _target.c_str();
	nameFile.append("_shrubbery");

	std::ofstream fileStream;
	fileStream.open(nameFile);
	if (!fileStream.is_open())
	{
		std::cerr << "Unable to create " << nameFile << "." << std::endl;
		fileStream.close();
		return ;
	}
	fileStream << "    _\/_" << std::endl;
	fileStream << "     /\ " << std::endl;
	fileStream << "     /\ " << std::endl;
	fileStream << "    /  \ " << std::endl;
	fileStream << "    /~~\o " << std::endl;
	fileStream << "   /o   \ " << std::endl;
	fileStream << "  /~~*~~~\ " << std::endl;
	fileStream << " o/    o \ " << std::endl;
	fileStream << " /~~~~~~~~\~`" << std::endl;
	fileStream << "/__*_______\ " << std::endl;
	fileStream << "     ||" << std::endl;
	fileStream << "   \====/" << std::endl;
	fileStream << "    \__/" << std::endl;
	fileStream.close();
}
