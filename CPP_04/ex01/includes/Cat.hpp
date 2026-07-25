/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:03:33 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 18:00:06 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public :
		Cat();
		Cat( const Cat& other );
		Cat& operator=( const Cat& other );
		~Cat();

		void			makeSound( void ) const;
		void			setIdea( int index, std::string content );
		std::string		getType( void ) const;
		std::string		getIdea( int index ) const;

	private :
		Brain *_brain;
};