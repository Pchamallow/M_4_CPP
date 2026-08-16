/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:21:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/16 08:37:52 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Intern
{
	public :
		Intern();
		Intern( const Intern& other );
		Intern&	operator=( const Intern& other );
		~Intern();

		AForm*	makeForm( const std::string& formName, const std::string& formeTarget ) const;

		private :
		AForm*	newRobotomyRequest( const std::string& target ) const;
		AForm*	newPresidentialPardon( const std::string& target ) const;
		AForm*	newShrubberyCreation( const std::string& target ) const;

	class FormNotFound : public std::invalid_argument
	{
		public :
			FormNotFound();
	};
};
