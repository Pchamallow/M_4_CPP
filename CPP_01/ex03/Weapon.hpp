/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:55:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/15 13:30:48 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon{

	public :
		Weapon();
		Weapon( std::string typeTarget );
		const std::string&	getType( void );
		void				setType( std::string target );

	private :
		std::string	type;


};