/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:00:29 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 18:28:51 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Animal
{
	public :
		Animal();
		Animal( const Animal& other );
		Animal& operator=( const Animal& other );
		virtual ~Animal();

		virtual void	makeSound( void ) const = 0;
		std::string		getType( void ) const;

	protected :
		std::string	type;
};