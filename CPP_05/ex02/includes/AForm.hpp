/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:21:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/14 10:41:41 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public :
		AForm();
		AForm( const std::string name );
		AForm( const std::string name, const int gradeSign );
		AForm( const std::string name, const int gradeSign, const int gradeExec );
		AForm( const AForm& other );
		AForm&	operator=( const AForm& other );
		virtual ~AForm();

		std::string		getName( void ) const;
		int				checkGrade( int grade ) const;
		int				getGradeSign( void ) const;
		int				getGradeExec( void ) const;
		bool			getSigned( void ) const;
		bool			beSigned( Bureaucrat& executor );
		void			execute( Bureaucrat const & executor ) const;

	private :
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_signed;
		virtual void		_execute( void ) const = 0;

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
	class AFormNotSigned: public std::runtime_error
	{
		public :
			AFormNotSigned();
	};
};

std::ostream&	operator<<( std::ostream& os, const AForm& other );
