/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:51:50 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/10 22:39:40 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

# define MAGENTA		"\e[0;35m"

Cat::Cat(void) : Animal("Cat")
{
	this->_brain = new Brain();
	std::cout << MAGENTA << "who arrre you and hou you darrrre bother meeeoooow?" << std::endl;
	return ;
}

Cat::Cat(Cat const& instance) : Animal(instance)
{
	*this = instance;
	std::cout << MAGENTA << "meeoww... why another cat, stupid human?" << std::endl;
	return ;
}

Cat::~Cat(void)
{
	std::cout << MAGENTA << "farewell, human, serve me better next timeeeeoow" << std::endl;
	delete this->_brain;
	return ;
}

Cat	&Cat::operator=(Cat const &right_hand_side)
{
	this->_type = right_hand_side.getType();
	this->_brain = right_hand_side.getBrain();
	return *this;
}

void Cat::getIdea(void)
{
	std::cout << MAGENTA << this->_brain->ideas[rand() % 100] << std::endl;
}

void Cat::getIdea(int index)
{
	std::cout << MAGENTA << this->_brain->ideas[index] << std::endl;
}

Brain	*Cat::getBrain(void)const
{
	return (this->_brain);
}

void Cat::makeSound(void)const
{
	std::cout << MAGENTA << "meeooowww!" << std::endl;
	return ;
}
