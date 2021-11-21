/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:31:35 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/21 13:31:18 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"
#include <iostream>
#include <stdlib.h> //stroll
#include <float.h> //float e dbl limits
#include <string> //to_string
#include <errno.h>
#include <iomanip>
#include <limits.h>
#include <limits>
#include <stdlib.h>

ScalarConversion::ScalarConversion(void) {}

ScalarConversion::ScalarConversion(char *str) : _str(str), _type(0), _impossible(false)
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

bool ScalarConversion::_isPseudoLiteral(char *str)
{
	std::string arg = str;
	if (_isFloatPseudoLiteral(arg) || _isDoublePseudoLiteral(arg))
		return (true);
	return (false);
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
	else if (_isPseudoLiteral(this->_str))
		this->_type = PSEUDO_LITERAL;
	else
		throw ScalarConversion::TypeNotFound();
	std::cout << this->_type << "\nCHAR-0 INT-1 FLOAT-2 DOUBLE-3" << std::endl;
}

// void ScalarConversion::convertType(void)
// {
// 	if (this->_type == PSEUDO_LITERAL)
// 		return ;
// 	void	(ScalarConversion::*convert[4])(void) = {	&ScalarConversion::_convertInt,
// 														&ScalarConversion::_convertFloat,
// 														&ScalarConversion::_convertDouble,
// 														&ScalarConversion::_convertChar };

// 	(this->*convert[this->_type])();
// }

// void	ScalarConversion::_convertChar(void)
// {
// 	this->_char = this->_str[0];
// 	this->_int = static_cast<int>(this->_char);
// 	this->_float = static_cast<float>(this->_char);
// 	this->_double = static_cast<double>(this->_char);
// }

// void	ScalarConversion::_convertInt(void)
// {
// 	long long limitsChecking = strtoll(this->_str, NULL, 0);
// 	if (limitsChecking < INT_MIN || limitsChecking > INT_MAX)
// 	{
// 		this->_impossible = true;
// 		return ;
// 	}
// 	this->_int = atoi(this->_str);
// 	this->_char = static_cast<char>(this->_int);
// 	this->_float = static_cast<float>(this->_int);
// 	this->_double = static_cast<double>(this->_int);
// }

// void	ScalarConversion::_convertFloat(void)
// {
// 	long long limitsChecking = strtoll(this->_str, NULL, 0);
// 	if (limitsChecking < FLT_MIN || limitsChecking > FLT_MAX || errno == ERANGE)
// 	{
// 		this->_impossible = true;
// 		return ;
// 	}
// 	std::cout << this->_str << std::endl;
// 	this->_float = atof(this->_str);
// 	std::cout << std::fixed << atof(this->_str) << "-->FLOAT--->" << this->_float << std::endl;
// 	this->_int = static_cast<int>(this->_float);
// 	this->_char = static_cast<char>(this->_float);
// 	this->_double = static_cast<double>(this->_float);
// }

// void	ScalarConversion::_convertDouble(void)
// {
// 	long long limitsChecking = strtoll(this->_str, NULL, 0);
// 	std::cout << limitsChecking << "---" << std::fixed << DBL_MAX << std::endl;
// 	if (limitsChecking < DBL_MIN || limitsChecking > DBL_MAX || errno == ERANGE)
// 	{
// 		this->_impossible = true;
// 		return ;
// 	}
// 	this->_float = strtoll(this->_str, NULL, 0);//atol(this->_str);
// 	this->_float = static_cast<float>(this->_double);
// 	this->_int = static_cast<int>(this->_double);
// 	this->_char = static_cast<char>(this->_double);
// }

char *ScalarConversion::_pseudoLiteralToDouble(char *str)
{
	int i = 0;
	while (str[i + 1] != '\0')
		i++;
	str[i] = '\0';
	return (str);
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

// void ScalarConversion::_displayChar(void)
// {
// 	std::cout << "char: ";
// 	if (this->_isDisplayableChar(this->_char))
// 		std::cout << "'" << this->_char << "'" << std::endl;
// 	else
// 		std::cout << "Non displayable" << std::endl;
// }

void ScalarConversion::_displayChar(long long value)
{
	char c;
	std::cout << "char: ";
	if (value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	c = static_cast<char>(value);
	if (this->_isDisplayableChar(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void ScalarConversion::_charConvertAllAndDisplay(void)
{
	std::cout << "char: '" << this->_str[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(this->_str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(this->_str[0]) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(this->_str[0]) << std::endl;
}

void ScalarConversion::_displayImpossible(void)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "impossible" << std::endl;
	std::cout << "double: " << "impossible" << std::endl;
}


// void ScalarConversion::displayAllTypes(void)
// {
// 	if (this->_type == PSEUDO_LITERAL)
// 	{
// 		this->_displayPseudoLiteral();
// 		return ;
// 	}
// 	if (this->_impossible)
// 	{
// 		_displayImpossible();
// 		return ;
// 	}
// 	// this->_displayChar();
// 	std::cout << std::fixed << std::setprecision(1);
// 	std::cout << "int: " << this->_int << std::endl;
// 	std::cout << "float: " << this->_float << "f" << std::endl;
// 	std::cout << "double: " << this->_double << std::endl;
// }

void ScalarConversion::_defineFormatAndPrecision(void)
{
	std::cout << std::fixed << std::setprecision(1);
}

bool ScalarConversion::_intOverflow(long long value)
{
	if (value < INT_MIN || value > INT_MAX)
		return (true);
	return (false);
}

bool ScalarConversion::_floatOverflow(long long value)
{
	if (value < FLT_MAX|| value > FLT_MIN)
		return (true);
	return (false);
}

bool ScalarConversion::_doubleOverflow(long long value)
{
	if (value < DBL_MIN || value > DBL_MAX)
		return (true);
	return (false);
}

bool ScalarConversion::_typeOverflow(long long value)
{
	bool (ScalarConversion::*TypeOverflow[3])(long long value) = {	&ScalarConversion::_intOverflow,
																	&ScalarConversion::_floatOverflow,
																	&ScalarConversion::_doubleOverflow };
	if (errno == ERANGE)
		return (true);
	if ((this->*TypeOverflow[this->_type])(value))
		return (true);
	return (false);
}

void ScalarConversion::_numberConvertAllAndDisplay(void)
{
	long long value = strtoll(this->_str, NULL, 0);
	if (_typeOverflow(value))
		_displayImpossible();
	this->_displayChar(value);
}

void ScalarConversion::display(void)
{
	_defineFormatAndPrecision();
	if (this->_type == PSEUDO_LITERAL)
		this->_displayPseudoLiteral();
	else if (this->_type == CHAR)
		this->_charConvertAllAndDisplay();
	else
		this->_numberConvertAllAndDisplay();
}
