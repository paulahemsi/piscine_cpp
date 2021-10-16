/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:39:46 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 19:59:18 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

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
	IMateriaSource* src = new MateriaSource();
	tic_tac(500000, 5);
	src->learnMateria(new Ice());
	tic_tac(500000, 5);
	src->learnMateria(new Cure());
	tic_tac(500000, 5);

	ICharacter* una = new Character("una");
	tic_tac(500000, 5);

	AMateria* tmp;
	tic_tac(500000, 5);
	tmp = src->createMateria("ice");
	tic_tac(500000, 5);
	una->equip(tmp);
	tic_tac(500000, 5);
	tmp = src->createMateria("cure");
	tic_tac(500000, 5);
	una->equip(tmp);
	una->equip(tmp);
	una->equip(tmp);
	una->equip(tmp);
	
	tic_tac(500000, 5);

	ICharacter* bob = new Character("bob");
	tic_tac(500000, 5);

	una->use(0, *bob);
	tic_tac(500000, 5);
	una->use(1, *bob);
	tic_tac(500000, 5);

	tmp = src->createMateria("nectar");
	una->equip(tmp);
	una->use(3, *bob);
	bob->use(3, *una);
	tic_tac(500000, 5);

	delete bob;
	delete una;
	delete src;

	return 0;
}
