/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:23:02 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/15 12:27:54 by pswirgie         ###   ########.fr       */
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
	: AForm("shrubbery creation", 145, 137), _target("") {}

ShrubberyCreationForm:: ShrubberyCreationForm( std::string target )
	: AForm("shrubbery creation", 145, 137), _target(target) {}

ShrubberyCreationForm:: ShrubberyCreationForm( const ShrubberyCreationForm& other )
{	(*this) = other;	}

ShrubberyCreationForm&		ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
	if (this != &other)
	{
		this->AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm:: ~ShrubberyCreationForm( void ) {}


// = MEMBER FUNCTIONS =================================================

void	ShrubberyCreationForm::_execute( void ) const
{
	std::ofstream fileStream;
	fileStream.open((_target + "_shrubbery").c_str());
	if (!fileStream.is_open())
	{
		std::cerr << "Unable to create " << (_target + "_shrubbery") << "." << std::endl;
		fileStream.close();
		return ;
	}
	fileStream << "    _\\/_" << std::endl;
	fileStream << "     /\\" << std::endl;
	fileStream << "     /\\" << std::endl;
	fileStream << "    /  \\" << std::endl;
	fileStream << "    /~~\\o" << std::endl;
	fileStream << "   /o   \\" << std::endl;
	fileStream << "  /~~*~~~\\" << std::endl;
	fileStream << " o/    o \\" << std::endl;
	fileStream << " /~~~~~~~~\\" << std::endl;
	fileStream << "/__*_______\\" << std::endl;
	fileStream << "     ||" << std::endl;
	fileStream << "   \\====/" << std::endl;
	fileStream << "    \\__/" << std::endl;
	fileStream.close();
}
