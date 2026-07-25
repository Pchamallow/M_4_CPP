/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:03:33 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 13:03:11 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog( const Dog& other );
		Dog& operator=( const Dog& other );
		~Dog();

		void			makeSound( void );
		std::string		getType( void );

	private :
	
};