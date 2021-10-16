/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:23:48 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 16:37:40 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

# define V_GREEN	"\e[0;38;5;82m"
# define RESET		"\e[0m"


Cure::Cure(void) : AMateria("cure")
{
	std::cout << V_GREEN << "New cure created!" << RESET << std::endl;
	return ;
}

Cure::Cure(Cure const &instance) : AMateria("cure")
{
	*this = instance;
	std::cout << V_GREEN << "Cure copied!" << RESET << std::endl;
	return ;
}

Cure::~Cure(void)
{
	std::cout << V_GREEN << "Cure destroyed" << RESET << std::endl;
	return ;
}

Cure	&Cure::operator=( Cure const & ringht_hand_side )
{
	(void)ringht_hand_side;
	return (*this) ;
}

Cure* Cure::clone(void) const
{
	std::cout << "+++++" << this->_type << std::endl;
	return new Cure(*this);
}

void 	Cure::use(ICharacter& target)
{
	std::cout << V_GREEN << "* heals " << target.getName() << "’s wounds *" << RESET << std::endl;
	return ;
}
