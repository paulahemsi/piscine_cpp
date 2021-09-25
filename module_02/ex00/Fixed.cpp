/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:35:48 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/25 12:05:41 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPoint = 0;
	return ;
}

Fixed::Fixed(Fixed const &instance)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = instance;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(Fixed const &right_hand_side)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixedPoint = right_hand_side.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void)const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const value)
{
	this->_fixedPoint = value;
}

int const	Fixed::_fractional_bits = 8;
