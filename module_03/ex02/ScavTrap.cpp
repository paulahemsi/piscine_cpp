/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:12:47 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/29 23:02:38 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

# define BOLD_H_MAGENTA	"\e[1;95m"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);

	std::cout	<< BOLD_H_MAGENTA
				<< "Hello, my friends, "
				<< this->getName()
				<< ", a brand new ScavTrap, is here!"
				<< std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout 	<< BOLD_H_MAGENTA
				<< "Bye bye, "
				<< this->getName()
				<< " our beloved ScavTrap..."
				<< std::endl;
	return ;
}

void	ScavTrap::attack(std::string const & target)
{
	if (this->_isBroken() || this->_isTired())
		return ;
	this->_energyPoints--;
	std::cout	<< BOLD_H_MAGENTA
				<< "SCAAAAVTRAP "
				<< this->getName()
				<< " attacks "
				<< target
				<< " causing "
				<< this->_attackDamage
				<< " of severe damage! OH NO!!!"
				<< std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout	<< BOLD_H_MAGENTA
				<< "Beeep Scavtrap "
				<< this->getName()
				<< " is in Gate keep mode beep beep "
				<< std::endl;
}
