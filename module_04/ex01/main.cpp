/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:09:26 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/13 18:52:51 by phemsi-a         ###   ########.fr       */
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
	const Animal* j = new Dog();
	tic_tac(500000, 5);
	const Animal* i = new Cat();
	tic_tac(500000, 5);
	delete j;
	tic_tac(500000, 5);
	delete i;
	tic_tac(500000, 5);
	Animal *animals[10];
	tic_tac(500000, 5);
	for(int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
		tic_tac(100000, 5);
	}
	for(int i = 0; i < 10; i++)
	{
		animals[i]->makeSound();
		tic_tac(500000, 5);	
		animals[i]->getIdea();
		tic_tac(500000, 5);
		delete animals[i];
		tic_tac(500000, 5);
	}
}
