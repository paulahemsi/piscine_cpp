/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:43:11 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/30 19:12:45 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

# define H_RED			"\e[0;91m"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);

	std::cout	<< H_RED
				<< "mUAhAhAaHA, I'm "
				<< this->getName()
				<< " a terrible FRAGTRAAAAP! "
				<< std::endl;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout	<< H_RED
				<< "Ohhh Nooo! "
				<< this->getName()
				<< " is gone...! "
				<< std::endl;
	return ;
}

void FragTrap::highFivesGuys(void)
{
	std::cout	<< H_RED
				<< "Hey, guys! Hi five!!"
				<< std::endl;
	return ;
}

#endif
