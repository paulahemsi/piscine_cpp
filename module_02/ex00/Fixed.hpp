/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:01:24 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/25 13:06:34 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int					_rawBits;
		static int const	_fractional_bits;

	public:
		Fixed(void);
		Fixed(Fixed const &instance);
		~Fixed();

		Fixed	&operator=(Fixed const &right_hand_side);

		int		getRawBits(void)const;
		void	setRawBits(int const raw);
};

#endif
