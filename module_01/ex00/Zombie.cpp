/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:14:34 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/13 00:03:53 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"
# include "utils.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::~Zombie()
{
	std::cout	<< V_GREEN
				<< "Aiizznnn brlpbrlp I'm "
				<< this->_name
				<< " and I'm dyiiingbrlpz "
				<< GREEN
				<< "----SILENCE----"
				<< RESET
				<< std::endl;
	return ;
}

void Zombie::annouce(void)
{
	std::cout << V_GREEN;
	typewriter("\n\naaaiiirzznnnnn ", PRESTISSIMO);
	typewriter(this->_name + " Whaaant'sss  BraiiiiiiinnnzzzZ...\n\n", PRESTO);
}
