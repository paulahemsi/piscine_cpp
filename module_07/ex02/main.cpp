/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:20:27 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/06 21:51:33 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

# define V_CYAN			"\e[0;38;5;44m"
# define RESET			"\e[0m"

int main(void)
{
	std::cout << V_CYAN << "\n----initializing with 0 new int array fo size 5----\n" << std::endl;

	Array<int> test = Array<int>(5);

	std::cout << V_CYAN << "\n----looping throw and trying to access out of bounds----\n" << RESET << std::endl;

	for (unsigned int i = 0; i < test.size() + 2; i++)
	{
		try
		{
			std::cout << test[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << V_CYAN << "\n----assigning values (0 - 4)----\n" << RESET << std::endl;

	for (unsigned int i = 0; i < test.size(); i++)
	{
		try
		{
			test[i] = i;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << V_CYAN << "\n----loopping throw the array----\n" << RESET << std::endl;

	for (unsigned int i = 0; i < test.size(); i++)
	{
		try
		{
			std::cout << test[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << V_CYAN << "\n----changing specific index value----\n" << RESET << std::endl;

	std::cout << V_CYAN << "\nold value:" << RESET << std::endl;
	std::cout << "test[2]:" << test[2] << std::endl;
	test[2] = 42;
	std::cout << V_CYAN << "\nnew value (42):" << RESET << std::endl;
	std::cout << "test[2]:" << test[2] << std::endl;

	std::cout << V_CYAN << "\n----testing copy----\n" << RESET << std::endl;

	Array<int> testCopy(test);
	std::cout << "testCopy[2]:" << testCopy[2] << std::endl;
	test[2] = 7;
	std::cout << "test[2]:" << test[2] << std::endl;
	std::cout << "testCopy[2]:" << testCopy[2] << std::endl;

	std::cout << V_CYAN << "\n----testing small array atribution----\n" << RESET << std::endl;

	Array<int> smallArray = Array<int>(2);
	smallArray = test;

	// Array<int> t2 = Array<int>();
	// try
	// {
	// 	std::cout << t2[0] << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}
