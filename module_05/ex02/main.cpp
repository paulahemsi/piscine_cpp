/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:21:27 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/14 23:44:59 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

// static void	tic_tac(int usleep_time, int duration)
// {
// 	for (int i = 0; i < duration; i++)
// 	{
// 		std::cout << "." << std::endl;
// 		usleep(usleep_time);
// 	}
// }

int main(void)
{
	std::cout << std::endl << "----Let the bureaucracy begin----" << std::endl << std::endl;
	
	PresidentialPardonForm form("the imposible future");
	ShrubberyCreationForm form2("lalalala");
	RobotomyRequestForm form3("popopo");
	// tic_tac(500000, 5);
	Bureaucrat	john;
	// tic_tac(500000, 5);
	Bureaucrat	fred("fred", 1);
	// tic_tac(500000, 5);
	form.execute(john);
	form.execute(fred);
	form3.execute(fred);
	form2.execute(fred);
	fred.signForm(form);
	fred.signForm(form3);
	fred.signForm(form2);
	form.execute(fred);
	form3.execute(fred);
	form2.execute(fred);
	std::cout << john << std::endl;
	// tic_tac(500000, 5);
	std::cout << fred << std::endl;
	// tic_tac(500000, 5);
	// tic_tac(500000, 5);
	fred.incrementGrade();
	fred.incrementGrade();
	fred.incrementGrade();
	john.decrementGrade();
	john.decrementGrade();
	john.decrementGrade();
	// tic_tac(500000, 5);
	std::cout << fred << std::endl;
	std::cout << john << std::endl;
	return (0);
}
