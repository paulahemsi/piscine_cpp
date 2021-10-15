/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:11:18 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/14 23:17:48 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

# define GRAY			"\e[0;38;5;8m"
# define RESET			"\e[0m"

AForm::AForm(std::string name, int gradeToSign, int gradeToexecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToexecute)
{
	std::cout << GRAY << "Form created. " << *this << RESET << std::endl;
	return ;
}

AForm::AForm(AForm const& instance) : _name(instance.getName()), _gradeToSign(instance.getGradeToSign()), _gradeToExecute(instance.getGradeToExecute())
{
	std::cout << GRAY << "Form copied. " << *this << RESET << std::endl;
	*this = instance;
	return ;
}

AForm::~AForm(void)
{
	std::cout << GRAY << "Form destroyed. " << *this << RESET << std::endl;
	return ;
}

AForm	&AForm::operator=(AForm const &right_hand_side)
{
	this->_isSigned = right_hand_side.getIsSigned();
	return (*this);
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

int			AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int			AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

bool		AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

std::string	AForm::getTarget(void) const
{
	return (this->_target);
}

void		AForm::setTarget(std::string target)
{
	this->_target = target;
}

void		AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	else
		this->_isSigned = true;
	return ;
}

void		AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw AForm::NoSignatureException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	return ;
}


std::ostream &operator<<(std::ostream &outputFile, AForm const &i)
{
	outputFile	<< GRAY
				<< i.getName()
				<< " Form. Grade to sign: "
				<< i.getGradeToSign()
				<< ". Grade to execute: "
				<< i.getGradeToExecute()
				<< " Is signed: ";
	if (i.getIsSigned())
		outputFile << "Yes." << RESET << std::endl;
	else
		outputFile << "No." << RESET << std::endl;
	return (outputFile);
}
