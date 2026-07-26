/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 10:48:50 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/26 13:27:32 by pswirgie         ###   ########.fr       */
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
		AMateria*			getFloor( int idx ) const;
		AMateria*			getInventory( int idx ) const;
		void				equip( AMateria* m );
		void				unequip( int idx );
		void				use( int idx, ICharacter& target );

	private :
		std::string			_name;
		AMateria*			_inventory[4];
		static AMateria*	_floor[50];
};