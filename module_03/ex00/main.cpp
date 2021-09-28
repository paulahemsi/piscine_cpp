/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:39:42 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/27 22:53:15 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	littleRobot("littleTrap");
	ClapTrap	bigRobot("bigTrap");

	bigRobot.attack("littleRobot");
	littleRobot.takeDamage(bigRobot.getAttackDamage());
	bigRobot.attack("the air");
	littleRobot.beRepaired(10);
}
