/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:35:48 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/26 21:06:11 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <typeinfo>

Fixed::Fixed(void)
{
	this->_rawBits = 0;
	return ;
}

Fixed::Fixed(Fixed const &instance)
{
	*this = instance;
	return ;
}

Fixed::Fixed(int const int_number)
{
	this->_rawBits = int_number << Fixed::_fractional_bits;
}

Fixed::Fixed(float const float_number)
{
	this->_rawBits = (int)roundf(float_number * (1 << Fixed::_fractional_bits));
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed &Fixed::operator=(Fixed const &right_hand_side)
{
	this->_rawBits = right_hand_side.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(Fixed const &right_hand_side)
{
	return (this->toFloat() + right_hand_side.toFloat());
}

Fixed Fixed::operator-(Fixed const &right_hand_side)
{
	return (this->toFloat() - right_hand_side.toFloat());
}

Fixed Fixed::operator*(Fixed const &right_hand_side)
{
	return (this->toFloat() * right_hand_side.toFloat());
}

Fixed Fixed::operator/(Fixed const &right_hand_side)
{
	return (this->toFloat() / right_hand_side.toFloat());
}

bool	Fixed::operator>(Fixed const &right_hand_side) const
{
	return (this->getRawBits() > right_hand_side.getRawBits());
}

bool	Fixed::operator>=(Fixed const &right_hand_side) const
{
	return (this->getRawBits() >= right_hand_side.getRawBits());
}

bool	Fixed::operator<(Fixed const &right_hand_side) const
{
	return (this->getRawBits() < right_hand_side.getRawBits());
}

bool	Fixed::operator<=(Fixed const &right_hand_side) const
{
	return (this->getRawBits() <= right_hand_side.getRawBits());
}

bool	Fixed::operator==(Fixed const &right_hand_side) const
{
	return (this->getRawBits() == right_hand_side.getRawBits());
}

bool	Fixed::operator!=(Fixed const &right_hand_side) const
{
	return (this->getRawBits() != right_hand_side.getRawBits());
}

Fixed	&Fixed::operator++(void)
{
	this->_rawBits++;
	return (*this);
}
Fixed	&Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}
Fixed	Fixed::operator++(int)
{
	Fixed result(*this);
	this->_rawBits++;
	return (result);
}
Fixed	Fixed::operator--(int)
{
	Fixed result(*this);
	this->_rawBits--;
	return (result);
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

Fixed const	&Fixed::min(Fixed const &value1, Fixed const &value2)
{
	if (value1 < value2)
		return (value1);
	return (value2);
	
}
Fixed const	&Fixed::max(Fixed const &value1, Fixed const &value2)
{
	if (value1 > value2)
		return (value1);
	return (value2);
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
