/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prologue.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:04:38 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/13 22:28:40 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "colors.hpp"
# include "defines.hpp"
# include "chapters.hpp"
# include "Zombie.hpp"

void	prologue(std::string name, Zombie &firstZombie)
{
	std::cout << GREEN;
	tic_tac(ADAGIO, 5);
	typewriter(CLOCK, ALLEGRO);
	tic_tac(ADAGIO, 5);
	typewriter(HELLO + name, PRESTO);
	tic_tac(MODERATO, 7);
	typewriter(WALKING, PRESTO);
	tic_tac(MODERATO, 5);
	typewriter(SUDDENLY, PRESTISSIMO);
	tic_tac(ALLEGRO, 7);
	firstZombie.noise();
	typewriter(SOUND, PRESTO);
	tic_tac(PRESTO, 10);
	typewriter(choice(FIRST_CHOICE, WHAIT, RUN), PRESTO);
}
