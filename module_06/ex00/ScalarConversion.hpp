/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:44:58 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/21 13:57:40 by phemsi-a         ###   ########.fr       */
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
		bool		_typeOverflow(long long value);
		bool		_intOverflow(long long value);
		bool		_floatOverflow(long long value);
		bool		_doubleOverflow(long long value);
		static void	_displayImpossible(void);
		void		_displayChar(long long value);
		static bool	_isDisplayableChar(char c);
		void		_displayInt(long long value);
		void		_displayFloat(long long value);
		void		_displayDouble(long long value);
 
		ScalarConversion(void);

	class TypeNotFound : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("\e[0;31mvalue is neither char, int, float or double\e[0m");
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
