/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:21:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/14 10:56:39 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <string>
#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		RobotomyRequestForm&	operator=( const RobotomyRequestForm& other );
		~RobotomyRequestForm();

	private :
		std::string	_target;
		void		_execute( void ) const;

};
