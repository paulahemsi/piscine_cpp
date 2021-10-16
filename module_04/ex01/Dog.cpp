/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:42:21 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 18:41:53 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include "Dog.hpp"

# define CYAN			"\e[0;36m"

Dog::Dog(void) : Animal("Dog")
{
	this->_brain = new Brain;
	std::cout << CYAN << "Heeey! Uhuuu! Hello! I'm a cute dog that loves you sooo much my dear human!!!" << std::endl;
	return ;
}

Dog::Dog(Dog const& instance) : Animal(instance)
{
	// this->_brain = new Brain;
	*this = instance;
	std::cout << CYAN << "Heey loook! Thats nice, now we're twooo dogys! Uhuuu!" << std::endl;
	return ;
}

Dog::~Dog(void)
{
	std::cout << CYAN << "Bye human! Was a plasure to live with you for this program! Miss you already!" << std::endl;
	delete this->_brain;
	return ;
}

Dog	&Dog::operator=(Dog const &right_hand_side)
{
	this->_type = right_hand_side.getType();
	this->_brain = new Brain (*right_hand_side.getBrain());
	return *this;
}

Brain	*Dog::getBrain(void)const
{
	return (this->_brain);
}

void Dog::getIdea(void)
{
	std::cout << CYAN << this->_brain->ideas[rand() % 100] << std::endl;
}

void Dog::getIdea(int index)
{
	std::cout << CYAN << this->_brain->ideas[index] << std::endl;
}

void Dog::makeSound(void)const
{
	std::cout << CYAN << "rrrrr woof woof woooof!" << std::endl;
	return ;
}
