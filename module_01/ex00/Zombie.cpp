/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:14:34 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/13 22:32:22 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"
# include "defines.hpp"
# include "chapters.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	return ;
}

Zombie::~Zombie()
{
	std::cout	<< V_GREEN;
	if (this->_name == "zzaaarghh")
		typewriter(ZOMBIE_DYING1 + this->_name + ZOMBIE_DYING2, PRESTO);
	else
		typewriter(this->_name + ZOMBIE_HUNGRY, PRESTO);
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
	typewriter(this->_name + ANNOUCE2, PRESTO);
	std::cout << GREEN;
}
