/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:35:48 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/26 13:45:28 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <math.h>
#include <typeinfo>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawBits = 0;
	return ;
}

Fixed::Fixed(Fixed const &instance)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = instance;
	return ;
}

Fixed::Fixed(int const int_number)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = int_number << Fixed::_fractional_bits;
}

Fixed::Fixed(float const float_number)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = (int)round(float_number * (1 << Fixed::_fractional_bits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(Fixed const &right_hand_side)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = right_hand_side.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &outputFile, Fixed const &i)
{
	outputFile << i.toFloat();
	return outputFile;
}

int		Fixed::getRawBits(void)const
{
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
	return ;
}

float	Fixed::toFloat(void)const
{
	return ((float)this->_rawBits / (float)(1 << this->_fractional_bits));
}

int		Fixed::toInt(void)const
{
	return (this->_rawBits >> Fixed::_fractional_bits);
}

int const	Fixed::_fractional_bits = 8;
