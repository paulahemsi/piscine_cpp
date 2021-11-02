/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 21:56:16 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/01 22:12:41 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T x, T y)
{
	T z;

	z = x;
	x = y;
	y = z;
}

template<typename T>
T const & min(T const & x, T const & y)
{
	return (x < y ? x : y);
}

template<typename T>
T const & max(T const & x, T const & y)
{
	return (x > y ? x : y);
}
#endif
