/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:20:27 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/26 17:43:14 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

# define V_CYAN			"\e[0;38;5;44m"
# define RESET			"\e[0m"

int main(void)
{
	std::cout << V_CYAN << "\n----initializing with 0 new int array fo size 5----\n" << std::endl;

	Array<int>intArray(5);

	std::cout << V_CYAN << "\n----looping throw and trying to access out of bounds----\n" << RESET << std::endl;

	for (unsigned int i = 0; i < intArray.size() + 2; i++)
	{
		try
		{
			std::cout << intArray[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << V_CYAN << "\n----assigning values (0 - 4)----\n" << RESET << std::endl;

	for (unsigned int i = 0; i < intArray.size(); i++)
	{
		try
		{
			intArray[i] = i;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << V_CYAN << "\n----loopping throw the array----\n" << RESET << std::endl;

	for (unsigned int i = 0; i < intArray.size(); i++)
	{
		try
		{
			std::cout << intArray[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	// std::cout << V_CYAN << "\n----changing specific index value----\n" << RESET << std::endl;

	// std::cout << V_CYAN << "\nold value:" << RESET << std::endl;
	// std::cout << "intArray[2]:" << intArray[2] << std::endl;
	// intArray[2] = 42;
	// std::cout << V_CYAN << "\nnew value (42):" << RESET << std::endl;
	// std::cout << "intArray[2]:" << intArray[2] << std::endl;

	// std::cout << V_CYAN << "\n----copy test----\n" << RESET << std::endl;

	// Array<int> intArrayCopy(intArray);
	// std::cout << "intArrayCopy[2]:" << intArrayCopy[2] << std::endl;
	// intArray[2] = 7;
	// std::cout << "intArray[2]:" << intArray[2] << std::endl;
	// std::cout << "intArrayCopy[2]:" << intArrayCopy[2] << std::endl;

	// std::cout << V_CYAN << "\n----testing small array atribution----\n" << RESET << std::endl;

	// Array<int> smallArray = Array<int>(2);
	// smallArray = intArray;

	// std::cout << V_CYAN << "\n----empty constructor and accessing test----\n" << RESET << std::endl;

	// Array<int> t2 = Array<int>();
	// try
	// {
	// 	std::cout << t2[0] << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// std::cout << V_CYAN << "\n----char array test----\n" << RESET << std::endl;

	// Array<char> constCharArray = Array<char>(2);
	// try
	// {
	// 	std::cout << constCharArray[0] << std::endl;
	// 	std::cout << constCharArray[1] << std::endl;
	// 	std::cout << constCharArray[2] << std::endl;
	// 	constCharArray[0] = 'c';
	// 	std::cout << constCharArray[0] << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// Array<char> charArray = Array<char>(3);

	// for (unsigned int i = 0; i < charArray.size(); i++)
	// {
	// 	try
	// 	{
	// 		charArray[i] = 'a' + i;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// }

	// for (unsigned int i = 0; i < charArray.size(); i++)
	// {
	// 	try
	// 	{
	// 		std::cout << charArray[i] << std::endl;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// }
}
