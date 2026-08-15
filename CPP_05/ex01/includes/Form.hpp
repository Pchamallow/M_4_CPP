/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:21:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/14 09:23:44 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public :
		Form();
		Form( const std::string name );
		Form( const std::string name, const int gradeSign );
		Form( const std::string name, const int gradeSign, const int gradeExec );
		Form( const Form& other );
		Form&	operator=( const Form& other );
		~Form();

		int				checkGrade( int grade ) const;
		std::string		getName( void ) const;
		int				getGradeSign( void ) const;
		int				getGradeExec( void ) const;
		bool			getSigned( void ) const;
		bool			beSigned( Bureaucrat& bureaucrat );

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

std::ostream&	operator<<( std::ostream& os, const Form& other );
