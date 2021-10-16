/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.MAX_ITENS2sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:33:23 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/12 12:20:38 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
	this->_initInventory();
	std::cout << "New character " << name << " created!" << std::endl;
	return ;
}

Character::Character(void) : _name("nameless")
{
	this->_initInventory();
	std::cout << "New nameless character created!" << std::endl;
	return ;
}

Character::Character(Character const & instance)
{
	*this = instance;
	std::cout << "Character " << instance.getName() << " copied!" << std::endl;
	return ;
}

Character::~Character(void)
{
	for(int i = 0; i < MAX_ITENS; i++)
		if(this->_inventory[i])
			delete this->_inventory[i];
	std::cout << "Character " << this->getName() << " destroyed" << std::endl;
	return ;
}

void Character::_initInventory(void)
{
	for(int i = 0; i < MAX_ITENS; i++)
		this->_inventory[i] = NULL;
}

Character	&Character::operator=( Character const & right_hand_side )
{
	this->_name = right_hand_side.getName();
	for(int i = 0; i < MAX_ITENS; i++)
		this->_inventory[i] = right_hand_side.getInventoryItem(i);
	return *this;
}

std::string const &Character::getName(void)const
{
	return (this->_name);
}

AMateria * const &Character::getInventoryItem(int index)const
{
	return (this->_inventory[index]);
}

void Character::setName(std::string name)
{
	this->_name = name;
	return ;
}

void Character::_fillInventory(AMateria *m, int i)
{
	this->_inventory[i] = m;
	return ;
}

void Character::equip(AMateria *m)
{
	for(int i = 0; i < MAX_ITENS; i++)
		if(!this->_inventory[i])
			return(this->_fillInventory(m, i));
	return ;
}

void Character::unequip(int idx)
{
	if (this->_inventory[idx])
		this->_inventory[idx] = NULL;
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->_inventory[idx])
	{
		std::cout << this->_inventory[idx]->getType();
		this->_inventory[idx]->use(target);
	}
	return ;
}
