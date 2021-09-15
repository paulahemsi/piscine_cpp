/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 00:41:54 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/14 20:52:51 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
{
	this->setType(weaponType);
	return ;
}

Weapon::~Weapon()
{
	return ;
}

std::string const &Weapon::getType()
{
	return (this->_type);
}

void		Weapon::setType(std::string weaponType)
{
	this->_type = weaponType;
}
