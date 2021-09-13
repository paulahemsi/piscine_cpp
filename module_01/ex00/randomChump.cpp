/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:28:53 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/12 21:26:16 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie	*zargh;

	zargh = newZombie(name);
	zargh->annouce();
}