/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:39:27 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/26 15:51:12 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
	public :
		Cure( void );
		Cure( const Cure& other );
		Cure& operator=( const Cure& other );
		~Cure();

		AMateria*		clone( void ) const;
		std::string		getType( void ) const;
		void			use(ICharacter& target);
};