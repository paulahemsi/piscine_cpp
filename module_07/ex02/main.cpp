/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:20:27 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/26 20:25:49 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

# define V_CYAN			"\e[0;38;5;44m"
# define RESET			"\e[0m"

int main(void)
{
	std::cout << V_CYAN << "\n----initializing with 0 new int array fo size 5----\n" << std::endl;

	Array<int> intArray = Array<int>(5);
	Array<const int> intArray2(5);


	std::cout << V_CYAN << "\n----looping throw and trying to access out of bounds----\n" << RESET << std::endl;

	for (unsigned int i = 0; i < intArray.size() + 2; i++)
	{
		try
		{
			std::cout << intArray[i] << std::endl;
			std::cout << intArray2[i] << std::endl;
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
			std::cout << "intArray[" << i << "] = " << i << std::endl;
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

	std::cout << V_CYAN << "\n----changing specific index value----\n" << RESET << std::endl;

	std::cout << V_CYAN << "\nold value:" << RESET << std::endl;
	std::cout << "intArray[2]:" << intArray[2] << std::endl;
	intArray[2] = 42;
	std::cout << V_CYAN << "\nnew value (42):" << RESET << std::endl;
	std::cout << "intArray[2]:" << intArray[2] << std::endl;


	std::cout << V_CYAN << "\n----copy test----\n" << RESET << std::endl;

	Array<int> intArrayCopy(intArray);
	std::cout << "intArrayCopy[2]:" << intArrayCopy[2] << std::endl;
	intArray[2] = 7;
	std::cout << "intArray[2]:" << intArray[2] << std::endl;
	std::cout << "intArrayCopy[2]:" << intArrayCopy[2] << std::endl;


	std::cout << V_CYAN << "\n----testing array too small to copy----\n" << RESET << std::endl;

	Array<int> smallArray(2);
	smallArray = intArray;


	std::cout << V_CYAN << "\n----empty constructor and accessing test----\n" << RESET << std::endl;

	Array<int> t2 = Array<int>();

	try
	{
		std::cout << t2[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "t2 size: " << t2.size() << std::endl;

	std::cout << V_CYAN << "\n----char array test----\n" << RESET << std::endl;

	Array<char> charArray(3);

	for (unsigned int i = 0; i < charArray.size(); i++)
	{
		try
		{
			charArray[i] = 'a' + i;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	for (unsigned int i = 0; i < charArray.size(); i++)
	{
		try
		{
			std::cout << charArray[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
