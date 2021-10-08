/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:43:11 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/07 20:24:17 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

# define H_RED			"\e[0;91m"

int FragTrap::hitPointsInit = 100;
int FragTrap::energyPointsInit = 100;
int FragTrap::attackDamageInit = 30;

FragTrap::FragTrap(void)
{
	this->setHitPoints(FragTrap::hitPointsInit);
	this->setEnergyPoints(FragTrap::energyPointsInit);
	this->setAttackDamage(FragTrap::attackDamageInit);

	std::cout << H_RED << "One FragTrap. Zero name.  " << std::endl;
	return ;
}


FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoints(FragTrap::hitPointsInit);
	this->setEnergyPoints(FragTrap::energyPointsInit);
	this->setAttackDamage(FragTrap::attackDamageInit);

	std::cout	<< H_RED
				<< "mUAhAhAaHA, I'm "
				<< this->getName()
				<< " a terrible FRAGTRAAAAP! "
				<< std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout	<< H_RED
				<< "Ohhh Nooo! "
				<< this->getName()
				<< " is gone...! "
				<< std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const& instance): ClapTrap(instance)
{
	std::cout	<< H_RED
				<< this->_name
				<< " DUPLICATED! RUN!!!!!"
				<< std::endl;
	return ;
}

FragTrap &FragTrap::operator=(FragTrap const &right_hand_side)
{
	this->_name = right_hand_side.getName();
	this->_hitPoints = right_hand_side.getHitPoints();
	this->_energyPoints = right_hand_side.getHitPoints();
	this->_attackDamage = right_hand_side.getAttackDamage();
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout	<< H_RED
				<< "Hey, guys! Hi five!!"
				<< std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &outputFile, FragTrap const &i)
{
	outputFile	<< H_RED
				<< i.getName()
				<< std::endl
				<< i.getHitPoints()
				<< std::endl
				<< i.getEnergyPoints()
				<< std::endl
				<< i.getAttackDamage()
				<< std::endl;
	return outputFile;
}
