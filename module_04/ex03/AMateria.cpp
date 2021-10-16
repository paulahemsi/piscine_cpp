/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:44:26 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 12:58:00 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): _type(type)
{
	std::cout << "New materia (" << type << ") created!" << std::endl;
	return ;
}

AMateria::AMateria(void) : _type("empty")
{
	std::cout << "New empty materia created!" << std::endl;
	return ;
}

AMateria::AMateria(AMateria const & instance )
{
	*this = instance;
	std::cout << "Materia (" << instance.getType() << ") duplicated!" << std::endl;
	return ;
}

AMateria::~AMateria(void)
{
	std::cout << "Is the end of this Materia (" << this->getType() << ") !" << std::endl;
	return ;
}

AMateria	&AMateria::operator=( AMateria const & ringht_hand_side )
{
	(void)ringht_hand_side;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	return ;
}
