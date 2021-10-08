/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:39:42 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/07 21:17:16 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

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
	DiamondTrap	namelessDiamond;
	tic_tac(1000000, 5);
	DiamondTrap	diamond("Diamond");
	tic_tac(1000000, 5);
	DiamondTrap	copyDiamond(diamond);
	tic_tac(500000, 5);
	std::cout << copyDiamond << std::endl;
	tic_tac(500000, 5);
	std::cout << diamond << std::endl;
	tic_tac(500000, 5);
	std::cout << namelessDiamond << std::endl;
	tic_tac(1000000, 10);
	namelessDiamond.attack("Diamond");
	tic_tac(500000, 5);
	diamond.takeDamage(namelessDiamond.getAttackDamage());
	tic_tac(1000000, 5);
	std::cout << namelessDiamond << std::endl;
	std::cout << diamond << std::endl;
	tic_tac(1000000, 10);
	diamond.highFivesGuys();
	tic_tac(500000, 5);
	diamond.guardGate();
	tic_tac(500000, 5);
	diamond.whoAmI();
	tic_tac(500000, 5);
	namelessDiamond.whoAmI();
	tic_tac(500000, 5);
	copyDiamond.whoAmI();
	tic_tac(500000, 5);
}
