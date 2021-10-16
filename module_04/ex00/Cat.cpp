/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:51:50 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 17:56:16 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"

# define MAGENTA		"\e[0;35m"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << MAGENTA << "who arrre you and hou you darrrre bother meeeau?" << std::endl;
	return ;
}

Cat::Cat(Cat const& instance) : Animal(instance)
{
	std::cout << MAGENTA << "miiiiiau... why another cat, stupid human?" << std::endl;
	return ;
}

Cat::~Cat(void)
{
	std::cout << MAGENTA << "farewell, human,and serve me better next timeeeeow" << std::endl;
	return ;
}

Cat	&Cat::operator=(Cat const &right_hand_side)
{
	this->_type = right_hand_side.getType();
	return *this;
}


void Cat::makeSound(void)const
{
	std::cout << MAGENTA << "miiiiiau!" << std::endl;
	return ;
}
