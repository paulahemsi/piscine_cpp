/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:31:35 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/20 21:37:17 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"
#include <iostream>
#include <iomanip>

#include <stdlib.h>

ScalarConversion::ScalarConversion(void) {}

ScalarConversion::ScalarConversion(char *str) : _str(str), _type(0)
{
	this->_detectType();
}

ScalarConversion::~ScalarConversion(void) {}

ScalarConversion::ScalarConversion(ScalarConversion const &instance)
{
	*this = instance;
}

ScalarConversion &ScalarConversion::operator=(ScalarConversion const &right_hand_side)
{
	this->_str = right_hand_side._str;
	return *this;
}

bool ScalarConversion::_isDisplayableChar(char c)
{
	if (c >= '!' && c <= '~')
		return (true);
	return (false);
}

bool ScalarConversion::_isDisplayableNANChar(char *str)
{
	if ((str[0] >= '!' && str[0] < '0') && str[1] == '\0')
		return (true);
	if ((str[0] > '9' && str[0] <= '~') && str[1] == '\0')
		return (true);
	return (false);
}

bool ScalarConversion::_isInt(char *str)
{
	int i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool ScalarConversion::_isFloat(char *str)
{
	int i = 0;
	bool point = false;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != 'f')
			return (false);
		if (str[i] == '.' && point == true)
			return (false);
		if (str[i] == 'f' && str[i + 1] != '\0')
			return (false);
		if (str[i] == '.')
			point = true;
		i++;
	}
	return (true);
}

bool ScalarConversion::_isDouble(char *str)
{
	int i = 0;
	bool point = false;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			return (false);
		if (str[i] == '.' && point == true)
			return (false);
		if (str[i] == '.')
			point = true;
		i++;
	}
	return (true);
}

void ScalarConversion::_detectType()
{
	if (_isDisplayableNANChar(this->_str))
		this->_type = CHAR;
	else if (_isInt(this->_str))
		this->_type = INT;
	else if (_isFloat(this->_str))
		this->_type = FLOAT;
	else if (_isDouble(this->_str))
		this->_type = DOUBLE;
	else
		throw ScalarConversion::TypeNotFound();
}

void ScalarConversion::convertType(void)
{
	void	(ScalarConversion::*convert[4])(void) = {	&ScalarConversion::_convertChar,
														&ScalarConversion::_convertInt,
														&ScalarConversion::_convertFloat,
														&ScalarConversion::_convertDouble };

	(this->*convert[this->_type])();
	// if (this->_type == CHAR)
	// {
	// 	this->_char = this->_str[0];
	// 	this->_int = static_cast<int>(this->_char);
	// 	this->_float = static_cast<float>(this->_char);
	// 	this->_double = static_cast<double>(this->_char);
	// }
	// if (this->_type == INT)
	// {
	// 	this->_int = atoi(this->_str);
	// 	this->_char = static_cast<char>(this->_int);
	// 	this->_float = static_cast<float>(this->_int);
	// 	this->_double = static_cast<double>(this->_int);
	// }
	// if (this->_type == FLOAT)
	// {
	// 	this->_float = atof(this->_str);
	// 	this->_int = static_cast<int>(this->_float);
	// 	this->_char = static_cast<char>(this->_float);
	// 	this->_double = static_cast<double>(this->_float);
	// }
	// if (this->_type == DOUBLE)
	// {
	// 	this->_double = atol(this->_str);
	// 	this->_float = static_cast<float>(this->_double);
	// 	this->_int = static_cast<int>(this->_double);
	// 	this->_char = static_cast<char>(this->_double);
	// }
}

void ScalarConversion::displayAllTypes(void)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "char: ";
	if (this->_isDisplayableChar(this->_char))
		std::cout << "'" << this->_char << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << this->_int << std::endl;
	std::cout << "float: " << this->_float << "f" << std::endl;
	std::cout << "double: " << this->_double << std::endl;
}

void	ScalarConversion::_convertChar(void)
{
	this->_char = this->_str[0];
	this->_int = static_cast<int>(this->_char);
	this->_float = static_cast<float>(this->_char);
	this->_double = static_cast<double>(this->_char);
}

void	ScalarConversion::_convertInt(void)
{
	this->_int = atoi(this->_str);
	this->_char = static_cast<char>(this->_int);
	this->_float = static_cast<float>(this->_int);
	this->_double = static_cast<double>(this->_int);
}

void	ScalarConversion::_convertFloat(void)
{
	this->_float = atof(this->_str);
	this->_int = static_cast<int>(this->_float);
	this->_char = static_cast<char>(this->_float);
	this->_double = static_cast<double>(this->_float);
}

void	ScalarConversion::_convertDouble(void)
{
	this->_double = atol(this->_str);
	this->_float = static_cast<float>(this->_double);
	this->_int = static_cast<int>(this->_double);
	this->_char = static_cast<char>(this->_double);
}

															
// void ScalarConversion::displayConversions(void)
// {
// 	void	(ScalarConversion::*convertAndPrint[5])(void) = {	&ScalarConversion::_printChar,
// 															&ScalarConversion::_printInt,
// 															&ScalarConversion::_printFloat,
// 															&ScalarConversion::_printDouble,
// 															&ScalarConversion::_printPseudoLiteral };
	
// 	std::cout << std::fixed << std::setprecision(1);
// 	(this->*convertAndPrint[this->_type])();
// }
