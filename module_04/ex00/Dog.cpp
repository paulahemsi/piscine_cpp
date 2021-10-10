/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:42:21 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/10 18:37:43 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
# define RED			"\e[0;31m"
# define L_RED			"\e[0;38;5;9m"
# define GREEN			"\e[0;32m"
# define D_GREEN		"\e[0;38;5;22m"
# define V_GREEN		"\e[0;38;5;82m"
# define P_GREEN		"\e[0;38;5;23m"
# define BLUE			"\e[0;34m"
# define V_BLUE			"\e[0;38;5;27m"
# define P_BLUE			"\e[0;38;5;24m"
# define CYAN			"\e[0;36m"
# define V_CYAN			"\e[0;38;5;44m"
# define MAGENTA		"\e[0;35m"
# define PURPLE			"\e[0;38;5;93m"
# define LILAC			"\e[0;38;5;13m"
# define PINK			"\e[0;38;5;199m"
# define YELLOW			"\e[0;33m"
# define L_YELLOW		"\e[0;38;5;191m"
# define BLACK			"\e[0;30m"
# define WHITE			"\e[0;37m"
# define GRAY			"\e[0;38;5;8m"
# define L_GRAY			"\e[0;38;5;245m"
# define ORANGE			"\e[0;38;5;166m"
# define V_ORANGE		"\e[0;38;5;202m"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << CYAN << "Heeey! Uhuuu! Hello! I'm a cute dog that loves you sooo much my dear human!!!" << std::endl;
	return ;
}

Dog::Dog(Animal const& instance) : Animal(instance)
{
	std::cout << CYAN << "Heey loook! Thats nice, now we're twooo dog! Uhuuu!" << std::endl;
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
	std::cout << CYAN << "rrrrr  aaaaau!" << std::endl;
	return ;
}
