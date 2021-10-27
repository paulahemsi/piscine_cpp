/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:21:27 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/21 19:49:09 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

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
	
	std::cout << "\n\n---------FORMS CREATION TEST---------\n\n" << std::endl;

	PresidentialPardonForm form("the imposible future");
	tic_tac(500000, 5);
	ShrubberyCreationForm form2("my_beautyfull_ASCII_trees");
	tic_tac(500000, 5);
	RobotomyRequestForm form3("someone");
	tic_tac(500000, 5);

	std::cout << "\n\n---------SIGN AND EXECUTE TEST---------\n\n" << std::endl;

	Bureaucrat	john;
	tic_tac(500000, 5);
	Bureaucrat	fred("fred", 1);
	tic_tac(500000, 5);
	
	john.executeForm(form);
	tic_tac(500000, 5);
	fred.executeForm(form);
	tic_tac(500000, 5);
	fred.executeForm(form2);
	tic_tac(500000, 5);
	fred.executeForm(form3);
	tic_tac(500000, 5);

	john.signForm(form);
	tic_tac(500000, 5);
	std::cout << form << std::endl;
	tic_tac(500000, 5);
	fred.signForm(form);
	tic_tac(500000, 5);
	fred.signForm(form3);
	tic_tac(500000, 5);
	fred.signForm(form2);
	tic_tac(500000, 5);
	
	john.executeForm(form);
	tic_tac(500000, 5);
	fred.executeForm(form);
	tic_tac(500000, 5);
	fred.executeForm(form3);
	tic_tac(500000, 5);
	fred.executeForm(form2);
	tic_tac(500000, 5);

	std::cout << "\n\n---------NEW INCREMENT DECREMENT CHECK TEST---------\n\n" << std::endl;

	std::cout << john << std::endl;
	tic_tac(500000, 5);
	std::cout << fred << std::endl;
	tic_tac(500000, 5);
	
	fred.incrementGrade();
	fred.incrementGrade();
	fred.incrementGrade();
	john.decrementGrade();
	john.decrementGrade();
	john.decrementGrade();
	tic_tac(500000, 5);
	
	std::cout << fred << std::endl;
	tic_tac(500000, 5);
	std::cout << john << std::endl;
	tic_tac(500000, 5);

	return (0);
}
