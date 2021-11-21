/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:44:58 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/21 19:50:32 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERSION_HPP
#define SCALAR_CONVERSION_HPP

#include <exception>
#include <string>

#define INT				0
#define FLOAT			1
#define DOUBLE			2
#define CHAR			3
#define PSEUDO_LITERAL	4

#define FLOAT_MIN		-340282346638528859811704183484516925440.0000000000000000
#define DOUBLE_MIN		-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0

class ScalarConversion
{
	private:
		char		*_str;
		int			_type;

		void		_detectType(void);
		
		static bool	_isDisplayableNANChar(char *str);
		static bool	_isInt(char *str);
		static bool	_isFloat(char *str);
		static bool	_isDouble(char *str);
		static bool	_isPseudoLiteral(char *str);
		static bool	_isFloatPseudoLiteral(std::string arg);
		static bool	_isDoublePseudoLiteral(std::string arg);
		
		static void	_defineFormatAndPrecision(void);
		void		_displayPseudoLiteral(void);
		static char	*_pseudoLiteralToDouble(char *str);
		void		_charConvertAllAndDisplay(void);
		void		_numberConvertAllAndDisplay(void);
		bool		_typeOverflow(double value);
		bool		_intOverflow(double value);
		bool		_floatOverflow(double value);
		bool		_doubleOverflow(double value);
		static void	_displayImpossible(void);
		void		_displayChar(double value);
		static bool	_isDisplayableChar(char c);
		void		_displayInt(double value);
		void		_displayFloat(double value);
		void		_displayDouble(double value);
 
		ScalarConversion(void);

	class TypeNotFound : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("\e[0;31mvalue is neither int, float, double or printable char\e[0m");
			}
	};

	public:
		ScalarConversion(char *str);
		ScalarConversion(ScalarConversion const &instance);
		~ScalarConversion(void);
		ScalarConversion	&operator=(ScalarConversion const &right_hand_side);

		void				display(void);
};

#endif
