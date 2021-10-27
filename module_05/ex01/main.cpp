/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:21:27 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/21 19:44:29 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
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
	std::cout << "\n\n---------CREATION TEST---------\n\n" << std::endl;
	tic_tac(500000, 5);
	Bureaucrat	john;
	tic_tac(500000, 5);
	Bureaucrat	fred("fred", 45);
	tic_tac(500000, 5);
	Form		form42("42", 42, 42);
	tic_tac(500000, 5);
	Form		form149("149", 149, 149);
	tic_tac(500000, 5);
	Form		*form77_61 = new Form("77_61", 77, 61);
	tic_tac(500000, 5);

	std::cout << "\n\n---------COPY AND DEEPNESS TEST---------\n\n" << std::endl;
	tic_tac(500000, 5);

	Form		*form77_61Copy = new Form(*form77_61);
	tic_tac(500000, 5);
	delete form77_61;
	tic_tac(500000, 5);
	std::cout << *form77_61Copy << std::endl;
	tic_tac(500000, 5);
	delete form77_61Copy;

	std::cout << "\n\n---------HI LOW GRADES FORM CREATION TEST---------\n\n" << std::endl;
	tic_tac(500000, 5);

	try
	{
		Form		form777_1("777_1", 777, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	tic_tac(500000, 5);
	try
	{
		Form		form3_minus1("3_minus1", 777, -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	tic_tac(500000, 5);

	std::cout << "\n\n---------SIGNS TESTS---------\n\n" << std::endl;
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
	tic_tac(500000, 5);
	fred.incrementGrade();
	fred.incrementGrade();
	tic_tac(500000, 5);
	std::cout << fred << std::endl;
	tic_tac(500000, 5);
	fred.signForm(form42);
	tic_tac(500000, 5);
	return (0);
}
