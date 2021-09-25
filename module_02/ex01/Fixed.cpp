/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:35:48 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/25 14:57:59 by phemsi-a         ###   ########.fr       */
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

// A constructor that takes a constant integer as a parameter and that converts it to
// the correspondant fixed(8) point value. The fractional bits value is initialized like
// in ex00.
// • A constructor that takes a constant floating point as a parameter and that converts
// it to the correspondant fixed(8) point value. The fractional bits value is initialized
// like in ex00.
// • A member function float toFloat( void ) const; that converts the fixed point
// value to a floating point value.
// • A member function int toInt( void ) const; that converts the fixed point value
// to an integer value.

Fixed::Fixed(int const number)
{
	this->_rawBits = number << Fixed::_fractional_bits;
}

Fixed::Fixed(float const number)
{
	
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

int		Fixed::getRawBits(void)const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
	return ;
}

float	Fixed::toFloat(void)const
{
	
}

int		Fixed::toInt(void)const
{
	return (this->_rawBits >> Fixed::_fractional_bits);
}	

int const	Fixed::_fractional_bits = 8;
