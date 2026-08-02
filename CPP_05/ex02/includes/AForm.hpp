/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:21:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/02 14:58:49 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
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
		virtual void	execute( Bureaucrat const & executor ) const = 0;

	protected :
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_signed;
		void				_execute( Bureaucrat const & executor ) const;

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
	class ExecutorGradeTooLowException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
	class FormAlreadySigned: public std::exception
	{
		public :
			virtual const char* what() const throw();
	};
};

std::ostream&	operator<<( std::ostream& os, const AForm& other );
