/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 23:28:10 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/14 00:22:34 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"
# include "chapters.hpp"
# include "defines.hpp"

int	main(void)
{
	Zombie *horde;

	typewriter(WELCOME_BACK, ALLEGRO);
	std::cout << GREEN;
	tic_tac(MODERATO, 4);
	typewriter(BEGINING, ALLEGRO);
	tic_tac(MODERATO, 5);
	typewriter(WAIT, ADAGIO);
	tic_tac(ADAGIO, 3);
	typewriter(ARE_U_LISTENING, ALLEGRO);
	tic_tac(ALLEGRO, 3);
	typewriter(NOT_ALONE, ALLEGRO);
	typewriter(SILHUETE, PRESTO);
	typewriter(RUN, PRESTO);
	typewriter(DOOR, PRESTO);
	typewriter(LIGHTER, ALLEGRO);
	tic_tac(MODERATO, 5);
	typewriter(OH_MY, ADAGIO);
	horde = zombieHorde(7, "ZzzaRgh");
	typewriter(HORDE, ALLEGRO);
	tic_tac(ALLEGRO, 5);
	typewriter(DEATH, ALLEGRO);
	typewriter(SILENCE, MODERATO);
	tic_tac(ALLEGRO, 7);
	delete [] horde;
	std::cout << RESET;
	typewriter(CONTINUE, ALLEGRO);
	tic_tac(ALLEGRO, 4);
}
