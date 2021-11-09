/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:05:08 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/08 22:10:49 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASEFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("\e[0;31mValue not found\e[0m");
		}
};

template<typename T>
typename T::iterator easyfind(T &container, int number)
{
	typename T::iterator found = std::find(container.begin(), container.end(), number);
	if (found == container.end())
		throw NotFoundException();
	return (found);
}

#endif
