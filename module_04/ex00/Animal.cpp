/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:28:46 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/10 18:50:51 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

# define WHITE			"\e[0;37m"

Animal::Animal(void) : _type("generic")
{
	std::cout << WHITE << "New " << this->_type << " Animal created!" << std::endl;
	return ;
}

Animal::Animal(std::string _typeName) : _type(_typeName)
{
	std::cout << WHITE << "New " << this->_type << " Animal created!" << std::endl;
	return ;
}

Animal::Animal(Animal const& instance)
{
	*this = instance;
	std::cout << WHITE << this->_type << " Animal duplicated!" << std::endl;
	return ;
}

Animal::~Animal(void)
{
	std::cout << WHITE << this->_type << " Animal destroyed!" << std::endl;
	return ;
}

Animal	&Animal::operator=(Animal const &right_hand_side)
{
	this->_type = right_hand_side.getType();
	return *this;
}

std::string Animal::getType(void)const
{
	return (this->_type);
}

void Animal::makeSound(void)const
{
	std::cout << WHITE << "..." << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &outputFile, Animal const *i)
{
	outputFile << WHITE << i->getType() << std::endl;
	return outputFile;
}

