/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 00:53:00 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/11 21:01:05 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->_lastIndex = -1;
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

std::string Phonebook::_truncate(std::string value, size_t limit)
{
	if (value.length() <= limit)
		return value;
	return value.substr(0, limit - 1) + DOT;
}

int	Phonebook::_defineLastIndex(void)
{
	_lastIndex++;
	if (_lastIndex == 8)
		_lastIndex = 0;
	return (_lastIndex);
}

int	Phonebook::_getIndex(void)
{
	for (int i = 0; i < 8; i++)
		if (this->_contacts[i].isEmpty())
			return (i);
	return (_defineLastIndex());
}

bool Phonebook::add(void)
{
	std::string buffer;
	int i;

	i = _getIndex();
	this->_contacts[i].set_firstName(buffer);
	this->_contacts[i].set_lastName(buffer);
	this->_contacts[i].set_nickName(buffer);
	this->_contacts[i].set_phoneNumber(buffer);
	this->_contacts[i].set_darkestSecret(buffer);

	return (true);
}

void Phonebook::_displayLine(int index)
{
	std::cout << std::right << std::setw(10) << (index + 1) << PIPE ;
	std::cout << std::right << std::setw(10)
		<< _truncate(this->_contacts[index].get_firstName(), 10) << PIPE ;
	std::cout << std::right << std::setw(10)
		<< _truncate(this->_contacts[index].get_lastName(), 10) << PIPE ;
	std::cout << std::right << std::setw(10)
		<< _truncate(this->_contacts[index].get_nickName(), 10) << PIPE ;
	std::cout << std::endl;
}

void Phonebook::_displayTable(void)
{
	std::cout << TABLE_HEADER << std::endl;
	for (int i = 0; i < 8; i++)
		if (!(this->_contacts[i].isEmpty()))
			_displayLine(i);
	std::cout << END_TABLE << std::endl;
}

void Phonebook::_displayContact()
{
	std::string	index_str;
	int			index;
	
	index = -1;
	while (index <= 0 || index > 8 )
	{
		std::cout << CHOOSE_A_CONTACT;
		std::getline(std::cin, index_str);
		index = atoi(index_str.c_str());
		if (index <= 0 || index > 8 )
			std::cout << ENTER_VALID;
	}
	this->_contacts[index - 1].displayContact();
}

bool Phonebook::search(void)
{
	_displayTable();
	_displayContact();
	return (true);
}
