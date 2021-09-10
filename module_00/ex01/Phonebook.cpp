/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 00:53:00 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/09 22:29:13 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Phonebook.hpp"

Phonebook::Phonebook(void) {
	std::cout << "phonebook instanciado\n";
	// for (int i = 0; i < 8; i++)
	// 	this->contacts[i] = NULL;
	this->contact_index = 0;
	return ;
}

Phonebook::~Phonebook(void) {
	std::cout << "phonebook destruido\n";
	return ;
}

bool Phonebook::add(void) {
//	std::cout << "Add\n";
	
	std::string buffer;
	
	this->contacts[0].set_firstName("vini");
	std::cout << this->contacts[0].get_firstName();
	return (true);
}

bool Phonebook::search(void) {
	std::cout << "Search\n";
	return (true);
}
