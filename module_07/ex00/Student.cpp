/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:39:33 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/02 15:07:59 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Student.hpp"


Student::Student(std::string name, float level) : _name(name), _level(level)
{
	return ;
}

Student::Student(void) : _name("Noobie"), _level(0.0)
{
	return ;
}

Student::~Student(void)
{
	return ;
}


Student::Student(Student const &instance)
{
	*this = instance;
	return ;
}

std::string	Student::getName(void)const
{
	return (this->_name);
}

float		Student::getLevel(void)const
{
	return (this->_level);
}

Student &Student::operator=(Student const &right_hand_side)
{
	this->_name = right_hand_side.getName();
	this->_level = right_hand_side.getLevel();
	return (*this);
}

bool	Student::operator>(Student const &right_hand_side) const
{
	return (this->getLevel() > right_hand_side.getLevel());
}

bool	Student::operator>=(Student const &right_hand_side) const
{
	return (this->getLevel() >= right_hand_side.getLevel());
}

bool	Student::operator<(Student const &right_hand_side) const
{
	return (this->getLevel() < right_hand_side.getLevel());
}

bool	Student::operator<=(Student const &right_hand_side) const
{
	return (this->getLevel() <= right_hand_side.getLevel());
}

bool	Student::operator==(Student const &right_hand_side) const
{
	return (this->getLevel() == right_hand_side.getLevel());
}

bool	Student::operator!=(Student const &right_hand_side) const
{
	return (this->getLevel() != right_hand_side.getLevel());
}

std::ostream &operator<<(std::ostream &outputFile, Student const &i)
{
	outputFile << i.getName() << " level: " << i.getLevel();
	return (outputFile);
}
