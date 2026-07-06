/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 14:46:06 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/06 14:28:15 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() : _firstName(""), _lastName(""),
					_nickname(""), _phoneNumber(""),
					_darkestSecret("") {}

Contact:: Contact(std::string firstName, std::string lastName,
			std::string nickname, std::string phoneNumber,
			std::string darkestSecret){

	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;

	initFields();
}

void Contact:: initFields(){
	_fields[0] = &_firstName;
	_fields[1] = &_lastName;
	_fields[2] = &_nickname;
	_fields[3] = &_phoneNumber;
	_fields[4] = &_darkestSecret;
}

Contact& Contact:: operator=(const Contact& other){
	
	if (this != &other)
	{
		_firstName = other._firstName;
		_lastName = other._lastName;
		_nickname = other._nickname;
		_phoneNumber = other._phoneNumber;
		_darkestSecret = other._darkestSecret;
		initFields();
	}
	return (*this);
}

const std::string& Contact:: getField(int index) const {
	return (*_fields[index]);
};
