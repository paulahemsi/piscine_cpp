/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:12:47 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/07 20:28:09 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

# define BOLD_H_MAGENTA	"\e[1;95m"

int ScavTrap::hitPointsInit = 100;
int ScavTrap::energyPointsInit = 50;
int ScavTrap::attackDamageInit = 20;

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoints(ScavTrap::hitPointsInit);
	this->setEnergyPoints(ScavTrap::energyPointsInit);
	this->setAttackDamage(ScavTrap::attackDamageInit);

	std::cout	<< BOLD_H_MAGENTA
				<< "Hello, my friends, "
				<< this->getName()
				<< ", a brand new ScavTrap, is here!"
				<< std::endl;
	return ;
}

ScavTrap::ScavTrap(void)
{
	this->setHitPoints(ScavTrap::hitPointsInit);
	this->setEnergyPoints(ScavTrap::energyPointsInit);
	this->setAttackDamage(ScavTrap::attackDamageInit);

	std::cout << BOLD_H_MAGENTA << "oh no, where's my name?! " << std::endl;
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

ScavTrap::ScavTrap(ScavTrap const& instance) : ClapTrap(instance)
{
	std::cout	<< BOLD_H_MAGENTA
				<< "beeeep! ScavTrap "
				<< this->_name
				<< " duplicated!"
				<< std::endl;
	return ;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &right_hand_side)
{
	this->_name = right_hand_side.getName();
	this->_hitPoints = right_hand_side.getHitPoints();
	this->_energyPoints = right_hand_side.getHitPoints();
	this->_attackDamage = right_hand_side.getAttackDamage();
	return (*this);
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

std::ostream &operator<<(std::ostream &outputFile, ScavTrap const &i)
{
	outputFile	<< BOLD_H_MAGENTA
				<< i.getName()
				<< std::endl
				<< "Hit points: "
				<< i.getHitPoints()
				<< std::endl
				<< "Energy points: "
				<< i.getEnergyPoints()
				<< std::endl
				<< "Attack damage: "
				<< i.getAttackDamage()
				<< std::endl;
	return outputFile;
}
