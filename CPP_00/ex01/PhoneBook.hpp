/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 10:53:42 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/06 10:34:40 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class	PhoneBook {

	public :
		PhoneBook();
		static const std::string	fieldsNames[5];

		std::string	toString(int nb);
		void	addContact(const Contact& c);
		int		getIndex();
		int		getMaxIndex();
		void	incrementIndex();
		void	printFormat(std::string str);
		void	printContacts();
		void	printContact(int index);

	private :
		Contact	_contacts[8];
		int		_nextIndex;
		int		_maxIndex;

};
