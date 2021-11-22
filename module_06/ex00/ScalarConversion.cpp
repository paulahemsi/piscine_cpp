/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:31:35 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/21 21:38:55 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"
#include <iostream>
#include <limits.h>
#include <stdlib.h> //strtod
#include <float.h> //float and dbl limit
#include <iomanip> //setprecision
#include <errno.h>

ScalarConversion::ScalarConversion(void) {}

ScalarConversion::ScalarConversion(char *str) : _str(str)
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
	this->_type = right_hand_side._type;
	return *this;
}

/*
** functions to detect input type:
**
**
** (there's easiests ways to do it in c++ but the subject only allow us to use few functions, so I was forced to do some checks in C way)
*/

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
	else if (_isPseudoLiteral(this->_str))
		this->_type = PSEUDO_LITERAL;
	else
		throw ScalarConversion::TypeNotFound();
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
		if (str[i] == 'f' && (str[i + 1] != '\0' || !point))
			return (false);
		if (str[i] == '.')
			point = true;
		i++;
	}
	if (str[i - 1] == 'f')
		return (true);
	return (false);
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

bool ScalarConversion::_isPseudoLiteral(char *str)
{
	std::string arg = str;
	if (_isFloatPseudoLiteral(arg) || _isDoublePseudoLiteral(arg))
		return (true);
	return (false);
}

bool ScalarConversion::_isFloatPseudoLiteral(std::string arg)
{
	if (arg == "-inff" || arg == "+inff" || arg == "nanf")
		return (true);
	return (false);
}

bool ScalarConversion::_isDoublePseudoLiteral(std::string arg)
{
	if (arg == "-inf" || arg == "+inf" || arg == "nan")
		return (true);
	return (false);
}

/*
** conversion functions
*/

void ScalarConversion::_convertFromChar(void)
{
	this->_char = this->_str[0];
	this->_int = static_cast<int>(this->_char);
	this->_float = static_cast<float>(this->_char);
	this->_double = static_cast<double>(this->_char);
}

void ScalarConversion::_convertFromNums(void)
{
	void (ScalarConversion::*convert[3])(void) = {	&ScalarConversion::_convertFromInt,
													&ScalarConversion::_convertFromFloat,
													&ScalarConversion::_convertFromFloat };
	(this->*convert[this->_type])();
}

void ScalarConversion::_convertFromInt(void)
{
	this->_int = atoi(this->_str);
	this->_char = static_cast<char>(this->_int);
	this->_float = static_cast<float>(this->_int);
	this->_double = static_cast<double>(this->_int);
}

void ScalarConversion::_convertFromFloat(void)
{
	this->_float = atof(this->_str);
	this->_char = static_cast<char>(this->_float);
	this->_int = static_cast<int>(this->_float);
	this->_double = static_cast<double>(this->_float);
}

void ScalarConversion::_convertFromDouble(void)
{
	this->_double = strtod(this->_str, NULL);
	this->_char = static_cast<char>(this->_double);
	this->_float = static_cast<float>(this->_double);
	this->_int = static_cast<int>(this->_double);
}


/*
** functions and auxiliar functions to display input value in all types:
*/

void ScalarConversion::display(void)
{
	_defineFormatAndPrecision();
	if (this->_type == PSEUDO_LITERAL)
		this->_displayPseudoLiteral();
	else if (this->_type == CHAR)
		this->_charDisplay();
	else
		this->_numberDisplay();
}

void ScalarConversion::_defineFormatAndPrecision(void)
{
	std::cout << std::fixed << std::setprecision(1);
}

void ScalarConversion::_displayPseudoLiteral(void)
{
	std::string pseudoLitral = this->_str;
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	if (_isDoublePseudoLiteral(pseudoLitral))
	{
		std::cout << "float: " << pseudoLitral << "f" << std::endl;
		std::cout << "double: " << pseudoLitral << std::endl;
		return ;
	}
	std::cout << "float: " << pseudoLitral << std::endl;
	pseudoLitral = _pseudoLiteralToDouble(this->_str);
	std::cout << "double: " << pseudoLitral << std::endl;
}

char *ScalarConversion::_pseudoLiteralToDouble(char *str)
{
	int i = 0;
	while (str[i + 1] != '\0')
		i++;
	str[i] = '\0';
	return (str);
}

void ScalarConversion::_charDisplay(void)
{
	this->_convertFromChar();
	std::cout << "char: '" << this->_char << "'" << std::endl;
	std::cout << "int: " << this->_int << std::endl;
	std::cout << "float: " << this->_float << "f" << std::endl;
	std::cout << "double: " << this->_double << std::endl;
}

void ScalarConversion::_numberDisplay(void)
{
	errno = 0;
	double checkValue = strtod(this->_str, NULL);
	if (_typeOverflow(checkValue))
		return (_displayImpossible());
	this->_convertFromNums();
	this->_displayChar(checkValue);
	this->_displayInt(checkValue);
	this->_displayFloat(checkValue);
	this->_displayDouble(this->_double);
}

bool ScalarConversion::_typeOverflow(double checkValue)
{
	bool (ScalarConversion::*TypeOverflow[3])(double checkValue) = {	&ScalarConversion::_intOverflow,
																	&ScalarConversion::_floatOverflow,
																	&ScalarConversion::_doubleOverflow };
	if (errno == ERANGE)
		return (true);
	if ((this->*TypeOverflow[this->_type])(checkValue))
		return (true);
	return (false);
}

bool ScalarConversion::_intOverflow(double checkValue)
{
	if (checkValue < INT_MIN || checkValue > INT_MAX)
		return (true);
	return (false);
}

bool ScalarConversion::_floatOverflow(double checkValue)
{
	if (checkValue < -FLT_MAX|| checkValue > FLT_MAX)
		return (true);
	return (false);
}

bool ScalarConversion::_doubleOverflow(double checkValue)
{
	if (checkValue < -DBL_MAX || checkValue > DBL_MAX)
		return (true);
	return (false);
}

void ScalarConversion::_displayImpossible(void)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "impossible" << std::endl;
	std::cout << "double: " << "impossible" << std::endl;
}

void ScalarConversion::_displayChar(double checkValue)
{
	std::cout << "char: ";
	if (checkValue < 0 || checkValue > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (this->_isDisplayableChar(this->_char))
			std::cout << "'" << this->_char << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
}

bool ScalarConversion::_isDisplayableChar(char c)
{
	if (c >= '!' && c <= '~')
		return (true);
	return (false);
}

void ScalarConversion::_displayInt(double checkValue)
{
	std::cout << "int: ";
	if (this->_intOverflow(checkValue))
		std::cout << "impossible" << std::endl;
	else
		std::cout << this->_int << std::endl;
}

void ScalarConversion::_displayFloat(double checkValue)
{
	std::cout << "float: ";
	if (this->_floatOverflow(checkValue))
		std::cout << "impossible" << std::endl;
	else
		std::cout << this->_float << "f" << std::endl;
}

void ScalarConversion::_displayDouble(double checkValue)
{
	std::cout << "double: " << checkValue << std::endl;
}
