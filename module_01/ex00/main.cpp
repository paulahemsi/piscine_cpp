/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:30:38 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/12 23:30:25 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// your Zombies must be destroyed at the appropriate time (when they are not needed anymore). They must be allocated on the stack or the heap depending on its use: sometimes it’s appropriate to have them on the stack, at other times the heap may a better choice

# include <iostream>
# include <unistd.h>
# include "colors.hpp"
# include "Zombie.hpp"

//  ADAGIO		
//  MODERATO
//  ALLEGRO
//  PRESTO	
//  PRESTISSIMO

static void	tic_tac(int usleep_time, int duration)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << "." << std::endl;
		usleep(usleep_time);
	}
}

static void	typewriter(std::string str, int velocity)
{
	int i = 0;
	while (str[i] != '\0')
	{
		std::cout << str[i] << "\xDB" << std::flush;
		usleep(velocity);
		std::cout << "\b \b" <<std::flush;
		usleep(velocity);
		i++;
	}
}

static void	intro(std::string name)
{
	std::cout << GREEN << std::endl << std::endl;
	typewriter("00h58\n", ALLEGRO);
	tic_tac(ADAGIO, 5);
	typewriter("Hello " + name, PRESTO);
	tic_tac(MODERATO, 7); 
	typewriter(" you are walking alone in a dark street...\n\n", PRESTO);
	tic_tac(MODERATO, 5);
	typewriter("suddenly....", PRESTISSIMO);
	tic_tac(ALLEGRO, 7);
	typewriter(" you heard a strange sound. What did you do?", PRESTO);
	tic_tac(PRESTO, 10);
}

static void	choose(std::string name)
{
	std::string	option;
	std::string	action;

	while (true)
	{
		std::cout << V_GREEN << "Whait still (PRESS 1) \nRun (PRESS 2)" << std::endl;
		std::getline(std::cin, option);
		if (option == "1")
		{
			action = "You whait, " + name + ". But the noise came closer and closer...";
			break;
		}
		if (option == "2")
		{
			action = "RUN, " + name + "!!!!";
			break ;
		}
	}
}

int main (void)
{
	std::string	name;

	typewriter("\n\n\nWelcome. Please, write your name:\n\n", PRESTISSIMO);
	std::getline(std::cin, name);
	intro(name);
	choose(name);
	
	randomChump("zzaaarghh");
	typewriter("\n\nto be continued...\n\n", ALLEGRO);
	tic_tac(ADAGIO, 4);
}