/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 20:03:08 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/09 21:08:43 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

std::string Contact::get_firstName(void) const {
	return (this->_firstName);
}

std::string Contact::get_lastName(void) const {
	return (this->_lastName);
}

std::string Contact::get_nickName(void) const {
	return (this->_nickname);
}

std::string Contact::get_phoneNumber(void) const {
	return (this->_phoneNumber);
}

std::string Contact::get_darkestSecret(void) const {
	return (this->_darkestSecret);
}

void Contact::set_firstName(std::string str) {
	this->_firstName = str;
}

void Contact::set_lastName(std::string str) {
	this->_lastName = str;
}

void Contact::set_nickName(std::string str) {
	this->_nickname = str;
}

void Contact::set_phoneNumber(std::string str) {
	this->_phoneNumber = str;
}

void Contact::set_darkestSecret(std::string str) {
	this->_darkestSecret = str;
}
