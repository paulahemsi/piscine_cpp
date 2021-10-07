/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:39:42 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/06 23:18:38 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
	ClapTrap	littleRobot("littleRobot");
	tic_tac(500000, 5);
	ScavTrap	scavRobot("Scavy");
	tic_tac(1000000, 5);
	FragTrap	fragRobot("Fragy");
	tic_tac(1000000, 5);
	FragTrap	anonymusFrag;
	tic_tac(1000000, 5);
	FragTrap	copyFrag(fragRobot);
	tic_tac(500000, 5);
	std::cout << copyFrag << std::endl;
	tic_tac(500000, 5);
	std::cout << fragRobot << std::endl;
	tic_tac(500000, 5);
	std::cout << anonymusFrag << std::endl;
	tic_tac(1000000, 10);
	anonymusFrag.attack("fragRobot");
	tic_tac(500000, 5);
	fragRobot.takeDamage(anonymusFrag.getAttackDamage());
	tic_tac(1000000, 5);
	std::cout << anonymusFrag << std::endl;
	std::cout << fragRobot << std::endl;
	tic_tac(1000000, 10);
	fragRobot.highFivesGuys();
	tic_tac(500000, 5);
}
