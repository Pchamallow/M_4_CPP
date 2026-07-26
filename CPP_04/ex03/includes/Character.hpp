/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 10:48:50 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/26 11:45:49 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public :
		Character();
		Character( const std::string name );
		Character( const Character& other );
		Character&	operator=( const Character& other );
		~Character();
		
		std::string const	&getName() const;
		void				equip( AMateria* m );
		void				unequip( int idx );
		void				use( int idx, ICharacter& target );

	private :
		std::string		_name;
		AMateria		*_inventory[4];
};