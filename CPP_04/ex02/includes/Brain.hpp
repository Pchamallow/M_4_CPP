/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:00:29 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/25 17:51:29 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Brain
{
	public :
		Brain();
		Brain( const Brain& other );
		Brain& operator=( const Brain& other );
		virtual ~Brain();

		void			setIdea( int index, std::string content );
		std::string		getIdea( int index ) const;

	protected :
		std::string	ideas[100];

};