/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 20:03:08 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/11 20:58:30 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

/*
** GETTERS
*/
std::string Contact::get_firstName(void) const
{
	return (this->_firstName);
}

std::string Contact::get_lastName(void) const
{
	return (this->_lastName);
}

std::string Contact::get_nickName(void) const
{
	return (this->_nickname);
}

std::string Contact::get_phoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string Contact::get_darkestSecret(void) const
{
	return (this->_darkestSecret);
}

/*
** SETTERS
*/
void Contact::set_firstName(std::string buffer)
{
	std::cout << FIRSTNAME;
	std::getline(std::cin, buffer);
	this->_firstName = buffer;
}

void Contact::set_lastName(std::string buffer)
{
	std::cout << LASTNAME;
	std::getline(std::cin, buffer);
	this->_lastName = buffer;
}

void Contact::set_nickName(std::string buffer)
{
	std::cout << NICKNAME;
	std::getline(std::cin, buffer);
	this->_nickname = buffer;
}

void Contact::set_phoneNumber(std::string buffer)
{
	std::cout << PHONENUMBER;
	std::getline(std::cin, buffer);
	this->_phoneNumber = buffer;
}

void Contact::set_darkestSecret(std::string buffer)
{
	std::cout << DARKESTSECRET;
	std::getline(std::cin, buffer);
	this->_darkestSecret = buffer;
}

/*
** AUX
*/
bool Contact::isEmpty(void)
{
	if (this->get_firstName() != "")
		return (false);
	if (this->get_lastName() != "")
		return (false);
	if (this->get_nickName() != "")
		return (false);
	if (this->get_phoneNumber() != "")
		return (false);
	if (this->get_darkestSecret() != "")
		return (false);
	return (true);
}

void Contact::_printEmpty(void)
{
	std::cout << EMPTY_CONTACT;
}

void Contact::displayContact(void)
{
	if (this->isEmpty())
		return (_printEmpty());
	std::cout << FIRSTNAME << this->get_firstName() << std::endl;
	std::cout << LASTNAME << this->get_lastName() << std::endl;
	std::cout << NICKNAME << this->get_nickName() << std::endl;
	std::cout << PHONENUMBER << this->get_phoneNumber() << std::endl;
	std::cout << DARKESTSECRET << this->get_darkestSecret() << std::endl;
}
