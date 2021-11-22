/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:23:49 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/21 21:42:11 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConversion.hpp"

#define L_RED			"\e[0;38;5;9m"

static int print_usage(void)
{
	std::cout << L_RED << "usage: ./convert value_to_convert" << std::endl;
	return (0);
}

static bool wrong_args(int argc)
{
	if (argc != 2)
		return (true);
	return (false);
}

int main(int argc, char **argv)
{
	if (wrong_args(argc))
		return (print_usage());
	try
	{
		ScalarConversion value(argv[1]);
		value.display();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
