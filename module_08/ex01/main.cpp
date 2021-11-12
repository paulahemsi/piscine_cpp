/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:20:16 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/11 20:54:08 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

# define RESET			"\e[0m"
# define CYAN			"\e[0;36m"

int main(void)
{
	std::cout << CYAN << "\n----SIMPLE TEST----\n" << RESET << std::endl;

	Span sp = Span(5);
	sp.addNumber(-6);
	sp.addNumber(3);
	sp.addNumber(19);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(11);
	sp.addNumber(11);
	sp.addNumber(11);
	sp.addNumber(11);
	sp.addNumber(11);
	sp.addNumber(11);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << CYAN << "\n----BIG SPAN TEST----\n" << RESET << std::endl;

	Span bigSp = Span(50000);
	for (int i = 0; i < 50000; i++)
	{
		usleep(10);
		std::srand((unsigned int)time(NULL));
		bigSp.addNumber(rand());
	}
	bigSp.addNumber(42);

	std::cout << bigSp.shortestSpan() << std::endl;
	std::cout << bigSp.longestSpan() << std::endl;

	std::cout << CYAN << "\n----ITERATOR TEST----\n" << RESET << std::endl;

	Span  itSp = Span(30);
	std::vector<int> itVector;

	for (int i = 0; i < 15; i++)
	{
		itSp.addNumber(i + 10);
		itVector.push_back(i * i);
	}

	std::vector<int>::iterator v_beging = itVector.begin();
	std::vector<int>::iterator v_end = itVector.end() - 1;

	itSp.addNumber(v_beging, v_end);
	
	std::cout << itSp.shortestSpan() << std::endl;
	std::cout << itSp.longestSpan() << std::endl;

	itSp.addNumber(v_beging, v_end);

	std::cout << CYAN << "\n----DEEP COPY TEST----\n" << RESET << std::endl;

	Span *ptrSp = new Span(5);

	for (int i = 0; i < 5; i++)
		ptrSp->addNumber((1000 * i) + 7);

	std::cout << ptrSp->shortestSpan() << std::endl;
	std::cout << ptrSp->longestSpan() << std::endl;

	Span *copySp = new Span(*ptrSp);
	delete ptrSp;

	std::cout << copySp->shortestSpan() << std::endl;
	std::cout << copySp->longestSpan() << std::endl;
	
	delete copySp;

	std::cout << CYAN << "\n----SHORT SPAN TEST----\n" << RESET << std::endl;

	Span noSp(0);
	Span littleSp(3);

	littleSp.addNumber(1);
	std::cout << noSp.shortestSpan() << std::endl;
	std::cout << noSp.longestSpan() << std::endl;
	std::cout << littleSp.shortestSpan() << std::endl;
	std::cout << littleSp.longestSpan() << std::endl;
}
