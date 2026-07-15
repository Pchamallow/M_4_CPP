/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:18:24 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/15 12:57:03 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie{

	public :
		Zombie();
		Zombie( std::string zombieName );
		~Zombie();

		void	announce( void );
		Zombie&	operator=( const Zombie& other );

	private :
		std::string	name;

};
