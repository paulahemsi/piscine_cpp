/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:51:50 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/10 18:30:48 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

# define L_GRAY			"\e[0;38;5;245m"


WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << L_GRAY << "who arrre you and hou you darrrre bother meeeau?" << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const& instance)
{
	*this = instance;
	std::cout << L_GRAY << "miiiiiau... why another Wrongcat, stupid human?" << std::endl;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << L_GRAY << "farewell" << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=(WrongCat const &right_hand_side)
{
	this->_type = right_hand_side.getType();
	return *this;
}


void WrongCat::makeSound(void)const
{
	std::cout << L_GRAY << "miiiiiau!" << std::endl;
	return ;
}
