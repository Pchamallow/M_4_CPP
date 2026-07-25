/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:00:29 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 13:09:56 by pswirgie         ###   ########.fr       */
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

		std::string		getType( void );
		virtual void	makeSound( void );

	protected :
		std::string	type;
};