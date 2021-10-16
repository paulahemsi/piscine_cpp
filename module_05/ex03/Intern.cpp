/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:08:21 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/15 21:29:24 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cctype>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#define TOTAL_FORMS 3

Intern::Intern(void)
{
	std::cout << "new intern created\n" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "intern destroyed\n" << std::endl;
}

Intern::Intern(Intern const& instance)
{
	*this = instance;
	std::cout << "intern copied\n" << std::endl;
}

Intern	&Intern::operator=(Intern const &right_hand_side)
{
	(void)right_hand_side;
	return (*this);
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string namesArray[TOTAL_FORMS] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	AForm	*(Intern::*createForm[TOTAL_FORMS])(std::string target) = {	&Intern::_createShrubberyForm,
																		&Intern::_createRobotomyForm,
																		&Intern::_createPresidentialForm};
	
	for(int i = 0; i < TOTAL_FORMS; i++)
	{
		if(name == namesArray[i])
			return ((this->*createForm[i])(target));
	}
	std::cout << "Intern creates " << name << std::endl;
	return (NULL);
}

AForm *Intern::_createPresidentialForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::_createRobotomyForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::_createShrubberyForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}
