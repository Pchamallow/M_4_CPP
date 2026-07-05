/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 14:46:06 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/05 18:23:17 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// savoir comment Phonebook doit construire
// son array de contact, il a besoin d avoir des valeurs par defaut
Contact::Contact() : _first_name(""), _last_name(""),
					_nickname(""), _phone_number(""),
					_darkest_secret("") {}

// pour creer un contact depuis le main donne ces infos la
Contact:: Contact(std::string first_name, std::string last_name,
			std::string nickname, std::string phone_number,
			std::string darkest_secret){

	this->_first_name = first_name;
	this->_last_name = last_name;
	this->_nickname = nickname;
	this->_phone_number = phone_number;
	this->_darkest_secret = darkest_secret;
}

// std::string Contact::fields_name() : "first_name", "last_name"{}

// Contact:: ~Contact(){};
