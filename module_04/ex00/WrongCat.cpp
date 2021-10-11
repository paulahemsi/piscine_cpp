/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:51:50 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/10 21:09:36 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

# define L_GRAY			"\e[0;38;5;245m"


WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << L_GRAY << "who arrre you and hou you darrrre bother meeeow?" << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const& instance)
{
	*this = instance;
	std::cout << L_GRAY << "meeow... why another Wrongcat, stupid human?" << std::endl;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << L_GRAY << "farewell, human,and serve me better next timeeeeow" << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=(WrongCat const &right_hand_side)
{
	this->_type = right_hand_side.getType();
	return *this;
}


void WrongCat::makeSound(void)const
{
	std::cout << L_GRAY << "meoow!" << std::endl;
	return ;
}
