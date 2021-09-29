/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:06:27 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/28 20:47:02 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

# define BOLD_H_BLACK	"\e[1;90m"
# define BOLD_H_RED		"\e[1;91m"
# define BOLD_H_GREEN	"\e[1;92m"
# define BOLD_H_YELLOW	"\e[1;93m"
# define BOLD_H_BLUE	"\e[1;94m"
# define BOLD_H_MAGENTA	"\e[1;95m"
# define BOLD_H_CYAN	"\e[1;96m"
# define BOLD_H_WHITE	"\e[1;97m"

ClapTrap::ClapTrap(void) : _name("nameless"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << BOLD_H_CYAN << "Nameless ClapTrap created!" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << BOLD_H_MAGENTA << "Rest in peace, " << this->_name << " ..." << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout	<< BOLD_H_CYAN
				<< "Hello, hello, "
				<< this->getName()
				<< " is here!"
				<< std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const& instance)
{
	*this = instance;
	std::cout	<< BOLD_H_CYAN
				<< "bipbip duplication on course..! "
				<< this->_name
				<< " duplicated!"
				<< std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &right_hand_side)
{
	this->_name = right_hand_side.getName();
	this->_hitPoints = right_hand_side.getHitPoints();
	this->_energyPoints = right_hand_side.getHitPoints();
	this->_attackDamage = right_hand_side.getAttackDamage();
	return (*this);
}

void	ClapTrap::attack(std::string const & target)
{
	if (this->_isBroken() || this->_isTired())
		return ;
	this->_energyPoints--;
	std::cout	<< BOLD_H_RED
				<< "ClapTrap "
				<< this->_name
				<< " attack "
				<< target
				<< " causing "
				<< this->_attackDamage
				<< " points of damage!"
				<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	std::cout	<< BOLD_H_RED
				<< "ClapTrap "
				<< this->_name
				<< " takes "
				<< amount
				<< " of damage "
				<< std::endl;
	this->_isBroken();
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_energyPoints += amount;
	this->_hitPoints += amount;
	std::cout	<< BOLD_H_BLUE
				<< "Beep Beeep!!! ClapTrap gains "
				<< amount
				<< " of repair!! "
				<< this->_name
				<< " is full of energy now!"
				<< std::endl;
}

bool	ClapTrap::_isBroken(void)
{
	if(this->_hitPoints <= 0)
	{
		std::cout	<< BOLD_H_MAGENTA
					<< "biip bip ClapTrap i-is bro-o-ken biip... "
					<< this->_name
					<< " needs repaaai-ir... bee-ep!"
					<< std::endl;
		return (true);
	}
	return (false);
}

bool	ClapTrap::_isTired(void)
{
	if(this->_energyPoints <= 0)
	{
		std::cout	<< BOLD_H_MAGENTA
					<< "biiip bip ClapTrap is tired... "
					<< this->_name
					<< " needs more energy... beep!"
					<< std::endl;
		return (true);
	}
	return (false);
}

void		ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void		ClapTrap::setHitPoints(unsigned int amount)
{
	this->_hitPoints = amount;
}

void		ClapTrap::setEnergyPoints(unsigned int amount)
{
	this->_energyPoints = amount;
}

void		ClapTrap::setAttackDamage(unsigned int amount)
{
	this->_attackDamage = amount;
}

std::string	ClapTrap::getName(void)const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void)const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void)const
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void)const
{
	return (this->_attackDamage);
}
