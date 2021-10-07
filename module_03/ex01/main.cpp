/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:39:42 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/06 22:06:37 by phemsi-a         ###   ########.fr       */
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
	ScavTrap	scavRobot("Scavy");
	tic_tac(1000000, 5);
	ScavTrap	anonymusScav;
	tic_tac(1000000, 5);
	ScavTrap	copyScav(scavRobot);
	tic_tac(500000, 5);
	ClapTrap	copyClap(littleRobot);
	tic_tac(500000, 5);
	std::cout << scavRobot << std::endl;
	std::cout << littleRobot << std::endl;
	tic_tac(1000000, 10);
	scavRobot.attack("littleRobot");
	littleRobot.takeDamage(scavRobot.getAttackDamage());
	tic_tac(1000000, 5);
	std::cout << scavRobot << std::endl;
	std::cout << littleRobot << std::endl;
	tic_tac(1000000, 10);
	anonymusScav.guardGate();
	tic_tac(500000, 5);
}
