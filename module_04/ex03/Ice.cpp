/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:25:25 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 16:37:31 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

# define CYAN		"\e[0;36m"
# define RESET		"\e[0m"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << CYAN << "New ice created!" << RESET << std::endl;
	return ;
}

Ice::Ice(Ice const &instance) : AMateria("ice")
{
	*this = instance;
	std::cout << CYAN << "Ice copied!" << RESET << std::endl;
	return ;
}

Ice::~Ice(void)
{
	std::cout << CYAN << "Ice destroyed" << RESET << std::endl;
	return ;
}

Ice	&Ice::operator=( Ice const & ringht_hand_side )
{
	(void)ringht_hand_side;
	return (*this);
}

Ice* Ice::clone(void) const
{
	return new Ice(*this);
}

void 	Ice::use(ICharacter& target)
{
	std::cout << CYAN << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
	return ;
}
