/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:21:27 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/21 19:50:02 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

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
	
	Intern intern;
	tic_tac(500000, 5);
	AForm *formPresidential = intern.makeForm("presidential pardon", "the imposible future");
	tic_tac(500000, 5);
	AForm *formShrubbery = intern.makeForm("shrubbery creation", "intern_tree");
	tic_tac(500000, 5);
	AForm *formRobotomy = intern.makeForm("robotomy request", "my_boss");
	tic_tac(500000, 5);
	AForm *inexitentForm = intern.makeForm("piporopopopo", "nothing");
	tic_tac(500000, 5);
	Bureaucrat bureaucrat("Lucy", 1);
	tic_tac(500000, 5);
	bureaucrat.executeForm(*formPresidential);
	tic_tac(500000, 5);
	bureaucrat.signForm(*formPresidential);
	tic_tac(500000, 5);
	bureaucrat.executeForm(*formPresidential);
	tic_tac(500000, 5);
	bureaucrat.executeForm(*formShrubbery);
	tic_tac(500000, 5);
	bureaucrat.signForm(*formShrubbery);
	tic_tac(500000, 5);
	bureaucrat.executeForm(*formShrubbery);
	tic_tac(500000, 5);
	bureaucrat.executeForm(*formRobotomy);
	tic_tac(500000, 5);
	bureaucrat.signForm(*formRobotomy);
	tic_tac(500000, 5);
	bureaucrat.executeForm(*formRobotomy);
	tic_tac(500000, 5);
	delete formPresidential;
	delete formRobotomy;
	delete formShrubbery;
	delete inexitentForm;
	return (0);
}
