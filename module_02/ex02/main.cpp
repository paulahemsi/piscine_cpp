/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:01:26 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/27 19:36:16 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed c(10);
	Fixed d(2.25f);
	std::cout << std::endl << "c: " << c << " d: " << d << std::endl;
	std::cout << "c / d: " << c / d << std::endl;
	std::cout << "c * d: " << c * d << std::endl;
	std::cout << "c + d: " << c + d << std::endl;
	std::cout << "c - d: " << c - d << std::endl;

	if (c < d)
		std::cout << "c < d" << std::endl;
	else
		std::cout << "c > d" << std::endl;
	if ((c / d) <= (c / d))
		std::cout << "deu bom" << std::endl;
	else
		std::cout << "deu ruim" << std::endl;
	if ((c * d) >= (c * d))
		std::cout << "deu bom" << std::endl;
	else
		std::cout << "deu ruim" << std::endl;
	if (c == d)
		std::cout << "c == d" << std::endl;
	else
		std::cout << "c != d" << std::endl;
	if ((c - d) != (c - d))
		std::cout << "deu ruim" << std::endl;
	else
		std::cout << "deu bom" << std::endl;

	return 0;
}
