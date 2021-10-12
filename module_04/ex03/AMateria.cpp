/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:44:26 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/11 23:36:07 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): _type(type)
{
	std::cout << "New materia (" << type << ") created!" << std::endl;
	return ;
}

AMateria::AMateria(void)
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
	
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	if(this->_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else
		std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	return ;
}
