/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:21:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/31 16:12:42 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
	public :
		Form();
		Form( const std::string name );
		Form( const std::string name, const int grade );
		Form( const Form& other );
		Form&	operator=( const Form& other );
		~Form();

		std::string		getName( void ) const;
		int				getGradeSign( void ) const;
		int				getGradeExec( void ) const;
		void			incrementGrade( void );
		void			decrementGrade( void );
		void			beSigned( Bureaucrat& bureaucrat );

	private :
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_signed;

	class GradeTooHighException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
};

std::ostream&	operator<<( std::ostream& os, const Bureaucrat& other );


