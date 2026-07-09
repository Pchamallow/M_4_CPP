/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:18:24 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/09 10:43:46 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>


class Zombie{

	public :
		Zombie( std::string zombieName);
		~Zombie();
		void	announce( void );
		Zombie&	operator= ( const Zombie& other );

	private :
		std::string	name;

};
