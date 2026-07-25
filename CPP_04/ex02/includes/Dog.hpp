/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:03:33 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 17:52:59 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog( const Dog& other );
		Dog& operator=( const Dog& other );
		~Dog();

		void			makeSound( void ) const;
		void			setIdea( int index, std::string content );
		std::string		getType( void ) const;
		std::string		getIdea( int index ) const;

	private :
		Brain *_brain;
};