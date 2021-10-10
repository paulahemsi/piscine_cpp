/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:28:46 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/10 18:53:50 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

# define GRAY			"\e[0;38;5;8m"

WrongAnimal::WrongAnimal(void) : _type("generic")
{
	std::cout << GRAY << "New " << this->_type << " WrongAnimal created!" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(std::string _typeName) : _type(_typeName)
{
	std::cout << GRAY << "New " << this->_type << " WrongAnimal created!" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const& instance)
{
	*this = instance;
	std::cout << GRAY << this->_type << " WrongAnimal duplicated!" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << GRAY << this->_type << " WrongAnimal destroyed!" << std::endl;
	return ;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &right_hand_side)
{
	this->_type = right_hand_side.getType();
	return *this;
}

std::string WrongAnimal::getType(void)const
{
	return (this->_type);
}

void WrongAnimal::makeSound(void)const
{
	std::cout << GRAY << "..." << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &outputFile, WrongAnimal const *i)
{
	outputFile <<  GRAY << i->getType() << std::endl;
	return outputFile;
}

