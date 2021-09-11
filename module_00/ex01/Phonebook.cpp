/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 00:53:00 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/11 01:27:40 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Phonebook.hpp"

Phonebook::Phonebook(void) {
	std::cout << "phonebook instanciado\n";
	// for (int i = 0; i < 8; i++)
	// 	this->contacts[i] = NULL;
	this->_contact_index = 0;
	return ;
}

Phonebook::~Phonebook(void) {
	std::cout << "phonebook destruido\n";
	return ;
}

bool Phonebook::add(void) {
	std::string buffer;
	int i = this->_contact_index;

	this->_contacts[i].set_firstName(buffer);
	this->_contacts[i].set_lastName(buffer);
	this->_contacts[i].set_nickName(buffer);
	this->_contacts[i].set_phoneNumber(buffer);
	this->_contacts[i].set_darkestSecret(buffer);
	
	return (true);
}

static std::string truncate(std::string value, size_t limit) {
	if (value.length() <= limit)
		return value;
	return value.substr(0, limit - 1) + DOT;
}

bool Phonebook::search(void) {
	int i = this->_contact_index;

	display_table_header();
	std::cout << truncate(this->_contacts[i].get_firstName(), 10) << std::endl;
	std::cout << truncate(this->_contacts[i].get_lastName(), 10) << std::endl;
	std::cout << truncate(this->_contacts[i].get_nickName(), 10) << std::endl;
	std::cout << truncate(this->_contacts[i].get_phoneNumber(), 10) << std::endl;
	std::cout << truncate(this->_contacts[i].get_darkestSecret(), 10) << std::endl;
	std::cout << END_TABLE << std::endl;
	return (true);
}
