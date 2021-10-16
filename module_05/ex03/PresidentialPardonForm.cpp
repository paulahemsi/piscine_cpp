/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:59:02 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 01:16:03 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

# define MAGENTA		"\e[0;35m"
# define RESET			"\e[0m"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	this->setTarget(target);
	std::cout << *this << std::endl;
	return ;
}

bool		PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (AForm::execute(executor))
	{
		std::cout << MAGENTA << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << RESET << std::endl;
		return (true);
	}
	return (false);
}

std::ostream &operator<<(std::ostream &outputFile, PresidentialPardonForm const &i)
{
	outputFile	<< MAGENTA
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
