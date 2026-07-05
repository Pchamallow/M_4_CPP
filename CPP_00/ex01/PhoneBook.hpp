/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 10:53:42 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/05 18:51:47 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class	PhoneBook {

	public :
		Contact	contacts[8];
		int		current;
		static const std::string	fields_names[5];

		void	add_contact(int index, const Contact& c);
		// add contact -> type contact
		// search

		PhoneBook();
};
