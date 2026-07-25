/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:03:33 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 13:03:19 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
	public :
		Cat();
		Cat( const Cat& other );
		Cat& operator=( const Cat& other );
		~Cat();

		void			makeSound( void );
		std::string		getType( void );

	private :
	
};