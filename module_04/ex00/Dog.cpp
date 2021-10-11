/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:42:21 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/10 21:08:33 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

# define CYAN			"\e[0;36m"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << CYAN << "Heeey! Uhuuu! Hello! I'm a cute dog that loves you sooo much my dear human!!!" << std::endl;
	return ;
}

Dog::Dog(Animal const& instance) : Animal(instance)
{
	std::cout << CYAN << "Heey loook! Thats nice, now we're twooo dogys! Uhuuu!" << std::endl;
	return ;
}

Dog::~Dog(void)
{
	std::cout << CYAN << "Bye human! Was a plasure to live with you for this program! Miss you already!" << std::endl;
	return ;
}

Dog	&Dog::operator=(Dog const &right_hand_side)
{
	this->_type = right_hand_side.getType();
	return *this;
}

void Dog::makeSound(void)const
{
	std::cout << CYAN << "rrrrr woof woof woooof!" << std::endl;
	return ;
}
