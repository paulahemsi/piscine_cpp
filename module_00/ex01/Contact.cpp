/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 20:03:08 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/11 17:52:51 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

void Contact::displayContact(void) {
	if (this->get_firstName() == "")
	{
		std::cout << "empty contact" << std::endl;
		return ;
	}
	std::cout << this->get_firstName() << std::endl;
	std::cout << this->get_lastName() << std::endl;
	std::cout << this->get_nickName() << std::endl;
	std::cout << this->get_phoneNumber() << std::endl;
	std::cout << this->get_darkestSecret() << std::endl;
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

void Contact::set_firstName(std::string buffer) {
	std::cout << FIRSTNAME;
	std::cin.ignore();
	std::getline(std::cin, buffer);
	std::cout << buffer << "<------\n";
	this->_firstName = buffer;
}

void Contact::set_lastName(std::string buffer) {
	std::cout << LASTNAME;
	std::cin.ignore();
	std::getline(std::cin, buffer);
	std::cout << buffer << "<------\n";
	
	this->_lastName = buffer;
}

void Contact::set_nickName(std::string buffer) {
	std::cout << NICKNAME;
	std::cin.ignore();
	std::getline(std::cin, buffer);
	std::cout << buffer << "<------\n";
	
	this->_nickname = buffer;
}

void Contact::set_phoneNumber(std::string buffer) {
	std::cout << PHONENUMBER;
	std::cin.ignore();
	std::getline(std::cin, buffer);
	std::cout << buffer << "<------\n";

	this->_phoneNumber = buffer;
}

void Contact::set_darkestSecret(std::string buffer) {
	std::cout << DARKESTSECRET;
	std::cin.ignore();

	std::getline(std::cin, buffer);
	std::cout << buffer << "<------\n";
	this->_darkestSecret = buffer;
}
