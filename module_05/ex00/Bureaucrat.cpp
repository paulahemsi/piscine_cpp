/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:18:59 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/12 19:32:40 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("John"), _grade(150)
{
	std::cout << "Bureaucrat with standard name (John) and grade (150) created" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	_checkGrade();
	std::cout << "Bureaucrat " << this->_name << " created with grade " << this->_grade << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const& instance) : _name(instance.getName())
{
	*this = instance;
	std::cout << "Bureaucrat " << this->_name << " duplicated" << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << this->_name << " destroyed" << std::endl;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &right_hand_side)
{
	this->_grade = right_hand_side.getGrade();
	return (*this);
}

void	Bureaucrat::_checkGrade(void)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void		Bureaucrat::incrementGrade(void)
{
	this->_grade--;
	_checkGrade();
}

void		Bureaucrat::decrementGrade(void)
{
	this->_grade++;
	_checkGrade();
}

std::ostream &operator<<(std::ostream &outputFile, Bureaucrat const &i)
{
	outputFile << i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;
	return (outputFile);
}
