/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:21:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/02 14:53:51 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <string>
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
		ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& other );
		~ShrubberyCreationForm();

		void	writeForm( Bureaucrat const& executor );
		void	execute( Bureaucrat const & executor ) const;
	
	private :
		const std::string	_target;

};
