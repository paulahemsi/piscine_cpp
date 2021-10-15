/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:37:28 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/14 23:55:29 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>

# define PINK			"\e[0;38;5;199m"
# define RESET			"\e[0m"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->setTarget(target);
	std::cout << *this << std::endl;
	return ;
}

void		RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		AForm::execute(executor);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	std::srand((unsigned int)time(NULL));
	if ((rand() % 2) != 0)
		std::cout << PINK << "Robotomization Failure" << RESET << std::endl;
	else
		std::cout << PINK << "Beeeep Bzzztrrrrr beeeeeeeep! " << this->getTarget() << "  has been robotomized successfully" << RESET << std::endl;
}

std::ostream &operator<<(std::ostream &outputFile, RobotomyRequestForm const &i)
{
	outputFile	<< PINK
				<< i.getName()
				<< std::endl
				<< "Grade to sign: "
				<< i.getGradeToSign()
				<< std::endl
				<< "Grade to execute: "
				<< i.getGradeToExecute()
				<< std::endl
				<< "Target: "
				<< i.getTarget()
				<< std::endl
				<< "Is signed: ";
	if (i.getIsSigned())
		outputFile << "Yes." << RESET << std::endl;
	else
		outputFile << "No." << RESET << std::endl;
	return (outputFile);
}
