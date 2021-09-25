/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:35:48 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/25 17:08:29 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

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

Fixed::Fixed(int const number)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = number << Fixed::_fractional_bits;
}

Fixed::Fixed(float const number)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = number * (1 << this->_fractional_bits);
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
	return *this;
}

std::ostream &operator<<(std::ostream &outputFile, Fixed const &i)
{
	// std::cout << "Assignation operator called" << std::endl;
	outputFile << i.getRawBits();
	return outputFile;
}

int		Fixed::getRawBits(void)const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
	return ;
}

float	Fixed::toFloat(void)const
{
	return this->_rawBits / (1 << this->_fractional_bits);
}

int		Fixed::toInt(void)const
{
	return (this->_rawBits >> Fixed::_fractional_bits);
}

int const	Fixed::_fractional_bits = 8;
