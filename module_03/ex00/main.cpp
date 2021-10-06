/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:39:42 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/05 21:11:36 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "ClapTrap.hpp"

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
	ClapTrap	namelessRobot;
	tic_tac(500000, 5);
	ClapTrap	littleRobot("littleRobot");
	tic_tac(500000, 5);
	ClapTrap	bigRobot("bigRobot");
	tic_tac(500000, 5);
	ClapTrap	duplicatedRobot(bigRobot);
	tic_tac(500000, 5);
	bigRobot.attack("littleRobot");
	tic_tac(500000, 5);
	littleRobot.takeDamage(bigRobot.getAttackDamage());
	tic_tac(500000, 10);
	std::cout << bigRobot << std::endl;
	tic_tac(1000000, 5);
	bigRobot.attack("the air");
	tic_tac(1000000, 10);
	std::cout << std::endl << littleRobot << std::endl;
	tic_tac(500000, 5);
	littleRobot.beRepaired(10);
	tic_tac(500000, 5);
	std::cout << littleRobot;
	tic_tac(500000, 10);
}
