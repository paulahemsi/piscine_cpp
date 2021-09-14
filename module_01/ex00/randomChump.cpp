/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:28:53 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/13 22:34:03 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Zombie.hpp"
# include "defines.hpp"
# include "chapters.hpp"

void randomChump( std::string name )
{
	Zombie	*zargh;

	zargh = newZombie(name);
	zargh->annouce();
	typewriter(OH_OH, MODERATO);
	typewriter(ZOMBIE_APPEARS, PRESTO);
	typewriter(choice(SECOND_CHOICE, NOTEBOOK_HIT, PUNCH), PRESTISSIMO);
	typewriter(ZOMBIE_DYING, PRESTO);
	delete zargh;
	typewriter(SILENCE, MODERATO);
	typewriter(RELIEF, PRESTO);
	tic_tac(ADAGIO, 4);
}
