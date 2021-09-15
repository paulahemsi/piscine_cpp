/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 00:42:46 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/14 22:00:28 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
	private:
		std::string	_name;
		Weapon		_weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void		attack(void);
};

#endif
