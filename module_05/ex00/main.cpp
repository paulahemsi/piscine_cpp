/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:21:27 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 21:13:22 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\n\n---------HEAP STACK TEST---------\n\n" << std::endl;
	Bureaucrat john;
	Bureaucrat *fred = new Bureaucrat("fred", 45);
	Bureaucrat peter("peter", 1);
	std::cout << john << std::endl;
	std::cout << *fred << std::endl;
	std::cout << peter << std::endl;
	std::cout << "\n\n---------COPY DEEP TEST---------\n\n" << std::endl;
	Bureaucrat *fredCopy = new Bureaucrat(*fred);
	std::cout << *fredCopy << std::endl;
	delete fred;
	std::cout << *fredCopy << std::endl;
	delete fredCopy;
	std::cout << "\n\n---------HI LOW CREATION GRADES TEST---------\n\n" << std::endl;
	try
	{
		Bureaucrat louise("louise", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	//std::cout << louise; --> 'identifier "louise" is undefined'
	try
	{
		Bureaucrat mary("mary", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	//std::cout << mary; --> 'identifier "mary" is undefined'
	std::cout << std::endl;
	std::cout << "\n\n---------INCREMENT DECREMENT TEST---------\n\n" << std::endl;
	std::cout << peter << std::endl;
	try
	{
		peter.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << peter << std::endl;
	std::cout << john << std::endl;
	try
	{
		john.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << john << std::endl;
	return (0);
}
