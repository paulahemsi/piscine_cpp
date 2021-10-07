/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:42:46 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/05 20:27:25 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:

	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const& instance);
		~FragTrap(void);

		FragTrap	&operator=(FragTrap const &right_hand_side);

		void	 highFivesGuys(void);
};

std::ostream &operator<<(std::ostream &outputFile, FragTrap const &i);

#endif
