/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:21:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/31 15:58:44 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <exception>

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
		void			incrementGrade( void );
		void			decrementGrade( void );

	private :
		const std::string	_name;
		int					_grade;

		static int	_checkGrade( int grade );
	
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
