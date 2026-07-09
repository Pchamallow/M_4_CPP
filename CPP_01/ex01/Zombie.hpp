/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:18:24 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/08 23:17:44 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie{

	public :
		Zombie();
		Zombie( std::string zombieName);
		~Zombie();

		void	announce( void );
		Zombie&	operator=( const Zombie& other );

	private :
		std::string	name;

};
