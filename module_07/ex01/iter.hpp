/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:25:33 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/26 19:11:28 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *arrayAddress, size_t lenght, void (function)(T &arrayMember))
{
	for(size_t i = 0; i < lenght; i++)
		function(arrayAddress[i]);
}

template<typename T>
void iter(T const *arrayAddress, size_t lenght, void (function)(T const &arrayMember))
{
	for(size_t i = 0; i < lenght; i++)
		function(arrayAddress[i]);
}

template<typename T>
void addOne(T &n)
{
	n += 1.0;
}

template<typename T>
void doubleValue(T &n)
{
	n *= 2;
}

template<typename T>
void print(T const &n)
{
	std::cout << n << std::endl;
}

#endif
