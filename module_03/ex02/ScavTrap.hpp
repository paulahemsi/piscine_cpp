/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:24:38 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/05 20:24:49 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
	private:

	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const& instance);
		~ScavTrap(void);

		ScavTrap	&operator=(ScavTrap const &right_hand_side);

		void	attack(std::string const & target);
		void	guardGate(void);
};

std::ostream &operator<<(std::ostream &outputFile, ScavTrap const &i);

#endif
