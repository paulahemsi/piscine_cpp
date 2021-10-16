/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:09:26 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 17:53:18 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
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
	tic_tac(500000, 5);
	const Animal* animal = new Animal();
	tic_tac(500000, 5);
	const Animal* dog = new Dog();
	tic_tac(500000, 5);
	const Animal* cat = new Cat();
	tic_tac(500000, 5);
	const WrongAnimal* wrongcat = new WrongCat();

	tic_tac(500000, 5);
	Dog copyDog(*dog);
	tic_tac(500000, 5);
	Cat otherCat;
	tic_tac(500000, 5);
	Cat copyCat(otherCat);
	tic_tac(500000, 5);

	std::cout << dog << std::endl;
	tic_tac(500000, 5);
	dog->makeSound();
	tic_tac(500000, 5);
	delete dog;
	tic_tac(500000, 5);

	std::cout << cat << std::endl;
	tic_tac(500000, 5);
	cat->makeSound();
	tic_tac(500000, 5);
	delete cat;
	tic_tac(500000, 5);

	std::cout << animal << std::endl;
	tic_tac(500000, 5);
	animal->makeSound();
	tic_tac(500000, 5);
	delete animal;
	tic_tac(500000, 5);

	std::cout << wrongcat << std::endl;
	tic_tac(500000, 5);
	wrongcat->makeSound();
	tic_tac(500000, 5);
	delete wrongcat;
	tic_tac(500000, 5);
}
