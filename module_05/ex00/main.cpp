/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:21:27 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/26 21:10:44 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "Bureaucrat.hpp"

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
	std::cout << "\n\n---------HEAP STACK TEST---------\n\n" << std::endl;

	tic_tac(500000, 5);
	Bureaucrat john;
	tic_tac(500000, 5);
	Bureaucrat *fred = new Bureaucrat("fred", 45);
	tic_tac(500000, 5);
	Bureaucrat peter("peter", 1);
	tic_tac(500000, 5);
	std::cout << john << std::endl;
	std::cout << *fred << std::endl;
	std::cout << peter << std::endl;
	tic_tac(500000, 5);

	std::cout << "\n\n---------COPY DEEP TEST---------\n\n" << std::endl;

	tic_tac(500000, 5);
	Bureaucrat *fredCopy = new Bureaucrat(*fred);
	tic_tac(500000, 5);
	std::cout << *fredCopy << std::endl;
	tic_tac(500000, 5);
	delete fred;
	tic_tac(500000, 5);
	std::cout << *fredCopy << std::endl;
	tic_tac(500000, 5);
	delete fredCopy;
	tic_tac(500000, 5);
	
	std::cout << "\n\n---------HI LOW CREATION GRADES TEST---------\n\n" << std::endl;

	tic_tac(500000, 5);
	try
	{
		Bureaucrat louise("louise", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	tic_tac(500000, 5);
	try
	{
		Bureaucrat mary("mary", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	tic_tac(500000, 5);

	std::cout << "\n\n---------INCREMENT DECREMENT TEST---------\n\n" << std::endl;

	tic_tac(500000, 5);
	std::cout << peter << std::endl;
	try
	{
		peter.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	tic_tac(500000, 5);
	std::cout << peter << std::endl;
	tic_tac(500000, 5);

	std::cout << john << std::endl;
	tic_tac(500000, 5);
	try
	{
		john.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << john << std::endl;
	tic_tac(500000, 5);

	return (0);
}
