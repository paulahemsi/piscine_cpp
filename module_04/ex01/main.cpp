/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:09:26 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 18:51:08 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <unistd.h>

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
	std::cout << "\n\n---------HEAP TEST---------\n\n" << std::endl;
	tic_tac(500000, 5);

	const Animal* heapDog = new Dog();
	tic_tac(500000, 5);
	const Animal* heapCat = new Cat();
	tic_tac(500000, 5);
	delete heapDog;
	tic_tac(500000, 5);
	delete heapCat;
	tic_tac(500000, 5);

	std::cout << "\n\n---------STACK + DEEP TEST---------\n\n" << std::endl;
	tic_tac(500000, 5);

	Dog dog;
	tic_tac(500000, 5);
	Cat cat;
	tic_tac(500000, 5);
	Cat catCopy(cat);
	tic_tac(500000, 5);
	Dog dogCopy(dog);
	tic_tac(500000, 5);
	cat.getIdea(5);
	catCopy.getIdea(5);
	tic_tac(500000, 5);
	dog.getIdea(5);
	dogCopy.getIdea(5);
	tic_tac(500000, 5);

	std::cout << "\n\n---------ARRAY TEST---------\n\n" << std::endl;
	tic_tac(500000, 5);

	Animal *animals[4];
	tic_tac(500000, 5);
	for(int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
		tic_tac(100000, 5);
	}
	for(int i = 0; i < 4; i++)
	{
		animals[i]->makeSound();
		tic_tac(500000, 5);	
		animals[i]->getIdea();
		tic_tac(500000, 5);
		delete animals[i];
		tic_tac(500000, 5);
	}
}
