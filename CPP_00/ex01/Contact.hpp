/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 11:03:20 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/05 18:23:22 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	Contact{

	public :
		Contact();
		Contact(std::string	first_name,
				std::string	last_name,
				std::string	nickname,
				std::string	phone_number,
				std::string	darkest_secret);
		// ~Contact();

	private :
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};
