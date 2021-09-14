/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 23:28:10 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/14 00:13:50 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"
# include "chapters.hpp"
# include "defines.hpp"

int	main(void)
{
	Zombie *horde;

	typewriter(WELCOME_BACK, ALLEGRO);
	tic_tac(MODERATO, 4);
	typewriter(BEGINING, ALLEGRO);
	tic_tac(MODERATO, 5);
	typewriter(WAIT, ADAGIO);
	tic_tac(3, ADAGIO);
	typewriter(ARE_U_LISTENING, ALLEGRO);
	tic_tac(7, PRESTO);
	typewriter(NOT_ALONE, ALLEGRO);
	typewriter(SILHUETE, PRESTO);
	typewriter(RUN, PRESTISSIMO);
	typewriter(DOOR, PRESTO);
	typewriter(LIGHTER, ALLEGRO);
	tic_tac(5, MODERATO);
	typewriter(OH_MY, ADAGIO);
	horde = zombieHorde(7, "ZzzaRgh");
	typewriter(HORDE, ALLEGRO);
	tic_tac(5, ALLEGRO);
	typewriter(DEATH, ALLEGRO);
	typewriter(SILENCE, MODERATO);
	tic_tac(7, ALLEGRO);
	delete [] horde;
	std::cout << RESET;
	typewriter(CONTINUE, ALLEGRO);
	tic_tac(ALLEGRO, 4);
}
