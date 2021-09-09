/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 00:53:00 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/08 22:04:20 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Phonebook.hpp"

Phonebook::Phonebook(void) {
	std::cout << "phonebook instanciado\n";
	return ;
}

Phonebook::~Phonebook(void) {
	std::cout << "phonebook destruido\n";
	return ;
}

bool Phonebook::add(void) {
	std::cout << "Add\n";
	return (true);
}

bool Phonebook::search(void) {
	std::cout << "Search\n";
	return (true);
}
