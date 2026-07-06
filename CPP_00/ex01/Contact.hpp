/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 11:03:20 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/06 14:28:57 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	Contact{

	public :
		Contact();
		Contact(std::string	firstName,
				std::string	lastName,
				std::string	nickname,
				std::string	phoneNumber,
				std::string	darkestSecret);

		const std::string&	getField(int index) const;

		Contact&	operator=(const Contact& other);

	private :
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		std::string	*_fields[5];

		void		initFields();
};
