/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:21:21 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/09 22:13:22 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

Span::Span(void) {}

Span::Span(unsigned int N) : _numbers(new std::vector<int>(N))
{
	return ;
}

Span::~Span(void)
{
	delete this->_numbers;
}

Span::Span(Span const &instance)
{
	*this = instance;
}

Span &Span::operator=(Span const &rightHandSize)
{
	this->_numbers = new std::vector<int>(*rightHandSize._numbers);
	return (*this);
}

void	Span::_checkIsFull(void)
{
	std::cout << this->_numbers->size() << " " << this->_numbers->size() << std::endl;
	if (this->_numbers->at(this->_numbers->size() - 1))
		throw IsFullException();
}

void	Span::_chechIsEnoughElements(void)
{
	if (this->_numbers->capacity() <= 1)
		throw noSpanException();
}

void	Span::addNumber(int number)
{
	try
	{
		this->_checkIsFull();
		this->_numbers->push_back(number);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Span::addNumber(std::vector<int>::iterator firstNumber, std::vector<int>::iterator lastNumber)
{
	while (firstNumber != lastNumber)
	{
		this->_numbers->push_back(*firstNumber);
		firstNumber++;
	}
	this->_numbers->push_back(*lastNumber);
}

int		Span::shortestSpan(void)
{
	try
	{
		_chechIsEnoughElements();
		return (*min_element(this->_numbers->begin(), this->_numbers->end()));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
}

int		Span::longestSpan(void)
{
	try
	{
		_chechIsEnoughElements();
		return (*max_element(this->_numbers->begin(), this->_numbers->end()));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (0);
	}
}

