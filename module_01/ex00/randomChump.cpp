/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:28:53 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/13 00:04:44 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"
#include "utils.hpp"

static void	choose()
{
	std::string	option;
	std::string action;

	while (true)
	{
		std::cout << H_GREEN << "Hit him with your notebook (PRESS 1 + ENTER) \nPunch him (PRESS 2 + ENTER)\n" << RESET << std::endl;
		std::getline(std::cin, option);
		std::cout << GREEN;
		if (option == "1")
		{
			action = "You take your old and heavy notebook and hit the zombie head! A creepy noise is heard...\n\nSeems you loose your notebook for good.\n";
			break ;
		}
		if (option == "2")
		{
			action = "You give a deep breath and punch that horrible zombie. Yor fist becamed dirty with zombie gellys\n\n";
			break ;
		}
	}
	typewriter(action, PRESTO);
}


void randomChump( std::string name )
{
	Zombie	*zargh;

	zargh = newZombie(name);
	zargh->annouce();
	typewriter("\n\nOh- Oh...!\n\n", MODERATO);
	typewriter("A big creepy green smeely zombie just appears in front of you... What did you do now?!\n\n", PRESTO);
	choose();
	typewriter("The Zombies head falls apart...! The body felt on the floor... He seems to be dying...\n\n", PRESTO);
	delete zargh;
	typewriter("You breath in relief\n\n", PRESTO);
}