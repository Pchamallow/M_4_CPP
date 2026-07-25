/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:03:33 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 16:10:42 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
		WrongCat();
		WrongCat( const WrongCat& other );
		WrongCat& operator=( const WrongCat& other );
		~WrongCat();

		void			makeSound( void ) const;
		std::string		getType( void ) const;
};