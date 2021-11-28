/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:20:16 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/28 11:16:06 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

# define RESET			"\e[0m"
# define CYAN			"\e[0;36m"

static void tryShortestSpan(Span &span)
{
	try
	{
		std::cout << span.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void tryLongestSpan(Span &span)
{
	try
	{
		std::cout << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static void simpleTest(void)
{
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
	
	tryShortestSpan(sp);
	tryLongestSpan(sp);
}

static void bigSpanTest(void)
{
	Span bigSp = Span(50000);
	for (int i = 0; i < 50000; i++)
	{
		usleep(10);
		std::srand((unsigned int)time(NULL));
		bigSp.addNumber(rand());
	}
	bigSp.addNumber(42);

	tryShortestSpan(bigSp);
	tryLongestSpan(bigSp);
}

static void iteratorTest(void)
{
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
	
	tryShortestSpan(itSp);
	tryLongestSpan(itSp);

	itSp.addNumber(v_beging, v_end);
}

static void shortSpanTest(void)
{
	Span noSp(0);
	Span littleSp(3);

	littleSp.addNumber(1);
	tryShortestSpan(noSp);
	tryLongestSpan(noSp);
	tryShortestSpan(littleSp);
	tryLongestSpan(littleSp);
}

static void deepCopyTest(void)
{
	Span *originalSp = new Span(5);

	for (int i = 0; i < 4; i++)
		originalSp->addNumber((1000 * i) + 7);

	std::cout << "originalSp shortestSpan: " << std::endl;
	tryShortestSpan(*originalSp);
	std::cout << "originalSp longestSpan: " << std::endl;
	tryLongestSpan(*originalSp);

	Span *copySp = new Span(*originalSp);

	std::cout << "\ncopySp shortestSpan: " << std::endl;
	tryShortestSpan(*copySp);
	std::cout << "copySp longestSpan: " << std::endl;
	tryLongestSpan(*copySp);

	originalSp->addNumber(1);
	std::cout << "\noriginalSp new shortestSpan: " << std::endl;
	tryShortestSpan(*originalSp);
	std::cout << "copySp shortestSpan: " << std::endl;
	tryShortestSpan(*copySp);

	delete originalSp;
	std::cout << "copySp longestSpan: " << std::endl;
	tryLongestSpan(*copySp);
	
	delete copySp;
}

int main(void)
{
	std::cout << CYAN << "\n----SIMPLE TEST----\n" << RESET << std::endl;
	simpleTest();
	std::cout << CYAN << "\n----BIG SPAN TEST----\n" << RESET << std::endl;
	bigSpanTest();
	std::cout << CYAN << "\n----ITERATOR TEST----\n" << RESET << std::endl;
	iteratorTest();
	std::cout << CYAN << "\n----SHORT SPAN TEST----\n" << RESET << std::endl;
	shortSpanTest();
	std::cout << CYAN << "\n----DEEP COPY TEST----\n" << RESET << std::endl;
	deepCopyTest();
}
