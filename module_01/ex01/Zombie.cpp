/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:14:34 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/14 00:22:01 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"
# include "defines.hpp"
# include "chapters.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	return ;
}

Zombie::Zombie()
{
	return ;
}

Zombie::~Zombie()
{
	std::cout	<< V_GREEN;
	typewriter(getName() + ZOMBIE_WANTS_MORE, PRESTISSIMO);
	std::cout << GREEN;
	return ;
}

void Zombie::noise(void)
{
	std::cout << V_GREEN;
	typewriter(NOISE, PRESTISSIMO);
	std::cout << GREEN;
}

void Zombie::annouce(void)
{
	std::cout << V_GREEN;
	typewriter(ANNOUCE1, PRESTISSIMO);
	typewriter(getName(), PRESTO);
	typewriter (ANNOUCE2, PRESTISSIMO);
	std::cout << GREEN;
}


std::string	Zombie::getName(void)
{
	return (this->_name);
}

# include <stdlib.h> 


char getChar(void)
{
	return ('a' + rand()%26);
}

void	Zombie::setName(std::string name)
{
	this->_name = getChar() + name + getChar();
}
