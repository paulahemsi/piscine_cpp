/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:44:58 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/20 21:38:58 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERSION_HPP
#define SCALAR_CONVERSION_HPP

#include <exception>

#define CHAR			0
#define INT				1
#define FLOAT			2
#define DOUBLE			3
#define PSEUDO_LITERAL	4

class ScalarConversion
{
	private:
		char			*_str;
		int				_type;
		char	_char;
		int		_int;
		float	_float;
		double	_double;

		static bool	_isDisplayableNANChar(char *str);
		static bool	_isDisplayableChar(char c);
		static bool	_isInt(char *str);
		static bool	_isFloat(char *str);
		static bool	_isDouble(char *str);
		void		_detectType(void);

		void		_convertChar(void);
		void		_convertInt(void);
		void		_convertFloat(void);
		void		_convertDouble(void);
		// void		_convertPseudoLiteral(void);

		
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

		void				convertType(void);
		void				displayAllTypes(void);
};

#endif
