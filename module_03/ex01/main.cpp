/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:39:42 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/29 23:51:53 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "ScavTrap.hpp"

static void	tic_tac(int usleep_time, int duration)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << "." << std::endl;
		usleep(usleep_time);
	}
}

int main(void)
{
	tic_tac(500000, 5);
	ClapTrap	littleRobot("littleRobot");
	tic_tac(500000, 5);
	ClapTrap	bigRobot("bigRobot");
	tic_tac(500000, 5);
	bigRobot.attack("littleRobot");
	tic_tac(300000, 5);
	littleRobot.takeDamage(bigRobot.getAttackDamage());
	tic_tac(300000, 5);
	bigRobot.attack("the air");
	tic_tac(1000000, 5);
	littleRobot.beRepaired(10);
	tic_tac(1000000, 5);
	ScavTrap	scavRobot("Scavy");
	tic_tac(500000, 5);
	scavRobot.attack("littleRobot");
	tic_tac(500000, 5);
	littleRobot.takeDamage(scavRobot.getAttackDamage());
	tic_tac(500000, 5);
}
