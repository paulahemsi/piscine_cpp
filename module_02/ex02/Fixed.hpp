/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:01:24 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/26 20:42:33 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_rawBits;
		static int const	_fractional_bits;

	public:
		Fixed(void);
		Fixed(Fixed const &instance);
		Fixed(int const int_number);
		Fixed(float const float_number);
		~Fixed(void);

		Fixed	&operator=(Fixed const &right_hand_side);
		Fixed	operator+(Fixed const &right_hand_side);
		Fixed	operator-(Fixed const &right_hand_side);
		Fixed	operator*(Fixed const &right_hand_side);
		Fixed	operator/(Fixed const &right_hand_side);

		bool	operator>(Fixed const &right_hand_side) const;
		bool	operator>=(Fixed const &right_hand_side) const;
		bool	operator<(Fixed const &right_hand_side) const;
		bool	operator<=(Fixed const &right_hand_side) const;
		bool	operator==(Fixed const &right_hand_side) const;
		bool	operator!=(Fixed const &right_hand_side) const;

		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		int		getRawBits(void)const;
		void	setRawBits(int const raw);
		float	toFloat(void)const;
		int		toInt(void)const;

		static const Fixed	&min(Fixed const &value1, Fixed const &value2);
		static const Fixed	&max(Fixed const &value1, Fixed const &value2);
};

std::ostream &operator<<(std::ostream &outputFile, Fixed const &i);

#endif
