/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 22:44:49 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/13 23:39:41 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
		horde[i].annouce();
	}
	return horde;
}
