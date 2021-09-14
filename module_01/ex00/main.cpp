/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:30:38 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/13 22:28:24 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// your Zombies must be destroyed at the appropriate time (when they are not needed anymore). They must be allocated on the stack or the heap depending on its use: sometimes it’s appropriate to have them on the stack, at other times the heap may a better choice

# include <iostream>
# include <unistd.h>
# include "colors.hpp"
# include "Zombie.hpp"
# include "chapters.hpp"
# include "defines.hpp"

int main (void)
{
	std::string	name;
	Zombie firstZombie("bleergh");

	typewriter(WELCOME, PRESTISSIMO);
	std::getline(std::cin, name);
	std::cout << GREEN;
	prologue(name, firstZombie);
	randomChump("zzaaarghh");
	std::cout << RESET;
	typewriter(CONTINUE, ALLEGRO);
	tic_tac(ALLEGRO, 4);
}