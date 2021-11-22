/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:44:58 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/21 21:36:30 by phemsi-a         ###   ########.fr       */
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
		char		_char;
		int			_int;
		float		_float;
		double		_double;

		void		_detectType(void);
		
		static bool	_isDisplayableNANChar(char *str);
		static bool	_isInt(char *str);
		static bool	_isFloat(char *str);
		static bool	_isDouble(char *str);
		static bool	_isPseudoLiteral(char *str);
		static bool	_isFloatPseudoLiteral(std::string arg);
		static bool	_isDoublePseudoLiteral(std::string arg);
		
		void		_convertFromChar(void);
		void		_convertFromNums(void);
		void		_convertFromInt(void);
		void		_convertFromFloat(void);
		void		_convertFromDouble(void);

		static void	_defineFormatAndPrecision(void);
		void		_displayPseudoLiteral(void);
		static char	*_pseudoLiteralToDouble(char *str);
		void		_charDisplay(void);
		void		_numberDisplay(void);
		bool		_typeOverflow(double checkValue);
		bool		_intOverflow(double checkValue);
		bool		_floatOverflow(double checkValue);
		bool		_doubleOverflow(double checkValue);
		static void	_displayImpossible(void);
		void		_displayChar(double checkValue);
		static bool	_isDisplayableChar(char c);
		void		_displayInt(double checkValue);
		void		_displayFloat(double checkValue);
		void		_displayDouble(double checkValue);
 
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
