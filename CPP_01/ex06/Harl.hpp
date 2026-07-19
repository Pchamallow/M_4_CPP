/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 13:14:45 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/19 15:05:31 by pswirgie         ###   ########.fr       */
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