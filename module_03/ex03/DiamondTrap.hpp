/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:56:42 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/07 20:58:50 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
	std::string	_name;
	void		_setAttributes(std::string name);
public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const& instance);
	~DiamondTrap(void);

	void	attack(std::string const & target);
	DiamondTrap	&operator=(DiamondTrap const &right_hand_side);

	void whoAmI(void);
};

std::ostream &operator<<(std::ostream &outputFile, DiamondTrap const &i);

#endif
