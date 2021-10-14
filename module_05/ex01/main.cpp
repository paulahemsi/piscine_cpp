/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:21:27 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/14 20:51:13 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	std::cout << std::endl << "----Let the bureaucracy begin----" << std::endl << std::endl;
	tic_tac(500000, 5);
	Bureaucrat	john;
	tic_tac(500000, 5);
	Bureaucrat	fred("fred", 45);
	tic_tac(500000, 5);
	Form		form42("42", 42, 42);
	tic_tac(500000, 5);
	Form		form149("149", 149, 149);
	tic_tac(500000, 5);
	std::cout << john << std::endl;
	tic_tac(500000, 5);
	std::cout << fred << std::endl;
	tic_tac(500000, 5);
	john.signForm(form42);
	tic_tac(500000, 5);
	john.signForm(form149);
	tic_tac(500000, 5);
	fred.signForm(form149);
	tic_tac(500000, 5);
	fred.signForm(form42);
	tic_tac(500000, 5);
	fred.incrementGrade();
	fred.incrementGrade();
	fred.incrementGrade();
	tic_tac(500000, 5);
	std::cout << fred << std::endl;
	tic_tac(500000, 5);
	fred.signForm(form42);
	tic_tac(500000, 5);
	return (0);
}
