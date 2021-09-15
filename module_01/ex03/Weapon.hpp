/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 00:42:06 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/14 20:53:03 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(std::string weaponType);
		~Weapon();

		std::string const &getType();
		void		setType(std::string weaponType);
};

#endif
