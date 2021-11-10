/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:43:00 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/09 22:10:53 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
private:
	std::vector<int>	*_numbers;
	void				_checkIsFull(void);
	void				_chechIsEnoughElements(void);
	Span(void);

	class IsFullException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("\e[0;31mSpan is full\e[0m");
			}
	};

	class noSpanException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("\e[0;31mno Span to find\e[0m");
			}
	};

public:
	Span(unsigned int N);
	Span(Span const &instance);
	~Span(void);

	Span	&operator=(Span const &rightHandSize);
	void	addNumber(int number);
	void	addNumber(std::vector<int>::iterator firstNumber, std::vector<int>::iterator lastNumber);
	int		shortestSpan(void);
	int		longestSpan(void);
};

#endif
