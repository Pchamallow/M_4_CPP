/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:21:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/14 10:46:10 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public :
		Bureaucrat();
		Bureaucrat( const std::string name );
		Bureaucrat( const std::string name, const int grade );
		Bureaucrat( const Bureaucrat& other );
		Bureaucrat&	operator=( const Bureaucrat& other );
		~Bureaucrat();

		std::string		getName( void ) const;
		int				getGrade( void ) const;
		void			setGrade( int grade );
		void			incrementGrade( void );
		void			decrementGrade( void );
		void			signForm( AForm & form );
		void			executeForm(AForm const & form) const;

	private :
		const std::string	_name;
		int					_grade;

		static int	_checkGrade( int grade );
	
	class GradeTooHighException : public std::range_error
	{
		public :
			GradeTooHighException();
	};
	class GradeTooLowException : public std::range_error
	{
		public :
			GradeTooLowException();
	};
};

std::ostream&	operator<<( std::ostream& os, const Bureaucrat& other );
