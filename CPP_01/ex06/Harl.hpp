/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 13:14:45 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/21 18:40:07 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#pragma once



class Harl
{
	public :
		Harl ();
		void	complain( std::string level );

	private :
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

};

Harl::Harl() {} // definition de la classe

typedef void (Harl::*method)(void);

struct	s_choose
{
	std::string	name;
	method		callback;
};

void Harl::complain(std::string level)
{

}