/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:49:24 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/27 11:48:45 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>

# define RESET			"\e[0m"
# define CYAN			"\e[0;36m"


static void vectorTest(void)
{
	std::vector<int> intVector;

	for (int i = 0; i < 10; i++)
		intVector.push_back((i * 10) + i);
		
	std::cout << "intVector: " << std::endl;
	std::vector<int>::iterator arrayIterator = intVector.begin();
	while (arrayIterator != intVector.end())
	{
		std::cout << *arrayIterator << std::endl;
		arrayIterator++;
	}
	try
	{
		std::vector<int>::iterator valueIterator = easyfind(intVector, 11);
		std::cout << "found: " << *valueIterator << std::endl;
		std::cout << "at index: " << std::distance(intVector.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::vector<int>::iterator valueIterator = easyfind(intVector, 1111);
		std::cout << "found: " << *valueIterator << std::endl;
		std::cout << "at index: " << std::distance(intVector.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void dequeTest(void)
{
	std::deque<int> intDeque;

	for (int i = 0; i < 10; i++)
		intDeque.push_front(i * i);
		
	std::cout << "intDeque: " << std::endl;
	std::deque<int>::iterator arrayIterator = intDeque.begin();
	while (arrayIterator != intDeque.end())
	{
		std::cout << *arrayIterator << std::endl;
		arrayIterator++;
	}
	try
	{
		std::deque<int>::iterator valueIterator = easyfind(intDeque, 25);
		std::cout << "found: " << *valueIterator << std::endl;
		std::cout << "at index: " << std::distance(intDeque.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::deque<int>::iterator valueIterator = easyfind(intDeque, 1111);
		std::cout << "found: " << *valueIterator << std::endl;
		std::cout << "at index: " << std::distance(intDeque.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void listTest(void)
{
	std::list<int> intList;

	for (int i = 0; i < 10; i++)
		intList.push_front(std::rand());
	intList.push_front(22);
	intList.sort();
	std::cout << "intList: " << std::endl;
	std::list<int>::iterator arrayIterator = intList.begin();
	while (arrayIterator != intList.end())
	{
		std::cout << *arrayIterator << std::endl;
		arrayIterator++;
	}
	try
	{
		std::list<int>::iterator valueIterator = easyfind(intList, 22);
		std::cout << "found: " << *valueIterator << std::endl;
		std::cout << "at index: " << std::distance(intList.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::list<int>::iterator valueIterator = easyfind(intList, 1111);
		std::cout << "found: " << *valueIterator << std::endl;
		std::cout << "at index: " << std::distance(intList.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void setTest(void)
{
	std::set<int> intSet;

	for (int i = 0; i < 10; i++)
		intSet.insert(i);
	std::cout << "intSet: " << std::endl;
	std::set<int>::iterator arrayIterator = intSet.begin();
	while (arrayIterator != intSet.end())
	{
		std::cout << *arrayIterator << std::endl;
		arrayIterator++;
	}
	try
	{
		std::set<int>::iterator valueIterator = easyfind(intSet, 9);
		std::cout << "found: " << *valueIterator << std::endl;
		std::cout << "at index: " << std::distance(intSet.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::set<int>::iterator valueIterator = easyfind(intSet, 1111);
		std::cout << "found: " << *valueIterator << std::endl;
		std::cout << "at index: " << std::distance(intSet.begin(), valueIterator) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(void)
{
	std::cout << CYAN << "\n-----Vector Test-----\n" << RESET << std::endl;
	vectorTest();
	std::cout << CYAN << "\n-----Deque Test-----\n" << RESET << std::endl;
	dequeTest();
	std::cout << CYAN << "\n-----List Test-----\n" << RESET << std::endl;
	listTest();
	std::cout << CYAN << "\n-----Set Test-----\n" << RESET << std::endl;
	setTest();
}
