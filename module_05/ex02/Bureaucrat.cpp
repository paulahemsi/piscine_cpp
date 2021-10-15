/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:18:59 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/14 23:52:35 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("John"), _grade(150)
{
	std::cout << "Bureaucrat with standard name (John) and grade (150) created" << std::endl << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	_checkGrade(0);
	std::cout << "Bureaucrat " << this->_name << " created with grade " << this->_grade << std::endl << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const& instance) : _name(instance.getName())
{
	*this = instance;
	std::cout << "Bureaucrat " << this->_name << " duplicated" << std::endl << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << this->_name << " destroyed" << std::endl << std::endl;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &right_hand_side)
{
	this->_grade = right_hand_side.getGrade();
	return (*this);
}

void	Bureaucrat::_checkGrade(int i)
{
	if (this->_grade < (1 + i))
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > (150 + i))
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
	try
	{
		_checkGrade(+1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	this->_grade--;
	std::cout << "incrementing " << this->_name << "'s grade" << std::endl << std::endl;
	return ;
}

void		Bureaucrat::decrementGrade(void)
{
	try
	{
		_checkGrade(-1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	this->_grade++;
	std::cout << "decrementing " << this->_name << "'s grade" << std::endl << std::endl;
	return ;
}

void		Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr	<< this->_name
					<< " cannot sign "
					<< form.getName()
					<< " because "
					<< e.what()
					<< std::endl;
		return ;
	}
	std::cout	<< this->_name
				<< " signs "
				<< form.getName()
				<< std::endl
				<< std::endl;
		return ;
}

void		Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr	<< this->_name
					<< " cannot sign "
					<< form.getName()
					<< " because "
					<< e.what()
					<< std::endl;
		return ;
	}
	std::cout	<< this->_name
				<< " executes "
				<< form.getName()
				<< std::endl
				<< std::endl;
		return ;
}


std::ostream &operator<<(std::ostream &outputFile, Bureaucrat const &i)
{
	outputFile << i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;
	return (outputFile);
}
