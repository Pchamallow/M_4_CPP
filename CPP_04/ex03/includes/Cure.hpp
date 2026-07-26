/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:39:27 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/26 12:39:31 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
	public :
		Cure();
		Cure( const Cure& other );
		Cure& operator=( const Cure& other );
		~Cure();

		AMateria*		clone() const;
		std::string		getType( void ) const;
		void			use(ICharacter& target);
};