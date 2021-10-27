/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:11:18 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/25 19:52:10 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

# define GRAY			"\e[0;38;5;8m"
# define RESET			"\e[0m"

Form::Form(void) : _name("standardForm"), _isSigned(false), _gradeToSign(75), _gradeToExecute(75) 
{
	std::cout << GRAY << "Form created. " << *this << RESET << std::endl;
	return ;
}

Form::Form(std::string name, int gradeToSign, int gradeToexecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToexecute) 
{
	this->_checkGrade();
	std::cout << GRAY << "Form created. " << *this << RESET << std::endl;
	return ;
}

Form::Form(Form const& instance) : _name(instance.getName()), _gradeToSign(instance.getGradeToSign()), _gradeToExecute(instance.getGradeToExecute())
{
	*this = instance;
	std::cout << GRAY << "Form copied. " << *this << RESET << std::endl;
	return ;
}

Form::~Form(void)
{
	std::cout << GRAY << "Form destroyed. " << *this << RESET << std::endl;
	return ;
}

Form	&Form::operator=(Form const &right_hand_side)
{
	this->_isSigned = right_hand_side.getIsSigned();
	return (*this);
}

void	Form::_checkGrade(void) const
{
	if (this->_gradeToExecute < 1 || this->_gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
		throw Form::GradeTooLowException();
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
		outputFile << "Yes." << RESET << std::endl;
	else
		outputFile << "No." << RESET << std::endl;
	return (outputFile);
}
