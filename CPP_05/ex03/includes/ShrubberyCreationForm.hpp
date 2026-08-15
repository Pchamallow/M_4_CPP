/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:21:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/14 10:11:09 by pswirgie         ###   ########.fr       */
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

	private :
		std::string	_target;
		void		_execute( void ) const;

};
