/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:11:18 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/12 20:57:52 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

# define GRAY			"\e[0;38;5;8m"

Form::Form(void) : _name("standartForm"), _gradeToSign(75), _gradeToExecute(75) 
{
	std::cout << GRAY << "Form created. " << this;
	return ;
}

Form::Form(std::string name, int gradeToSign, int gradeToexecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToexecute) 
{
	std::cout << GRAY << "Form created. " << this;
	return ;
}

Form::Form(Form const& instance) : _name(instance.getName()), _gradeToSign(instance.getGradeToSign()), _gradeToExecute(instance.getGradeToExecute())
{
	std::cout << GRAY << "Form copied. " << this;
	*this = instance;
	return ;
}

Form::~Form(void)
{
	std::cout << GRAY << "Form destroyed. " << this;
	return ;
}

Form	&Form::operator=(Form const &right_hand_side)
{
	this->_isSigned = right_hand_side.getIsSigned();
	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

int			Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int			Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

bool		Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

void		Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	else
		this->_isSigned = true;
	return ;
}

std::ostream &operator<<(std::ostream &outputFile, Form const &i)
{
	outputFile	<< GRAY
				<< i.getName()
				<< " Form. Grade to sign: "
				<< i.getGradeToSign()
				<< ". Grade to execute: "
				<< i.getGradeToExecute()
				<< " Is signed: ";
	if (i.getIsSigned())
		outputFile << "Yes." << std::endl;
	else
		outputFile << "No." << std::endl;
	return (outputFile);
}
