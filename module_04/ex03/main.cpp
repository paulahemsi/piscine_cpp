/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:39:46 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/17 12:28:04 by phemsi-a         ###   ########.fr       */
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
	//basic tests
	IMateriaSource* src = new MateriaSource();
	tic_tac(500000, 5);
	src->learnMateria(new Ice());
	tic_tac(500000, 5);
	src->learnMateria(new Cure());
	tic_tac(500000, 5);
	
	tic_tac(500000, 5);
	Character* una = new Character("una");
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
	tic_tac(500000, 5);

	//deep copy test MateriaSource and Materia
	MateriaSource* src2 = new MateriaSource();
	tic_tac(500000, 5);
	src2->learnMateria(new Ice());
	tic_tac(500000, 5);
	src2->learnMateria(new Cure());
	tic_tac(500000, 5);
	MateriaSource* srcCopy = new MateriaSource(*src2);
	tic_tac(500000, 5);
	delete src2;

	//full inventory and unequip test
	tic_tac(500000, 5);
	tmp = srcCopy->createMateria("ice");
	tic_tac(500000, 5);
	una->equip(tmp);
	tic_tac(500000, 5);
	AMateria *lastItem = srcCopy->createMateria("cure");
	tic_tac(500000, 5);
	una->equip(lastItem);
	tic_tac(500000, 5);
	una->equip(tmp);
	tic_tac(500000, 5);
	una->unequip(3);
	tic_tac(500000, 5);
	delete lastItem;
	tic_tac(500000, 5);

	ICharacter* bob = new Character("bob");
	tic_tac(500000, 5);

	//deep copy test character
	Character* unaCopy = new Character(*una);
	tic_tac(500000, 5);
	delete una;
	tic_tac(500000, 5);

	unaCopy->use(0, *bob);
	tic_tac(500000, 5);
	unaCopy->use(1, *bob);
	tic_tac(500000, 5);
	//empty slot, do nothing:
	unaCopy->use(3, *bob);
	tic_tac(500000, 5);

	//unkown materia
	tmp = src->createMateria("nectar");
	tic_tac(500000, 5);

	tmp = src->createMateria("ice");
	tic_tac(500000, 5);
	unaCopy->equip(tmp);
	tic_tac(500000, 5);
	unaCopy->use(3, *bob);
	tic_tac(500000, 5);

	delete bob;
	delete unaCopy;
	delete src;
	delete srcCopy;

	return 0;
}
