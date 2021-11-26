/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:20:29 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/26 20:25:12 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private:
		unsigned int	_n;
		T				*_ptr;

	public:
		Array(void): _n(0), _ptr(0) {};
		Array(unsigned int n): _n(n), _ptr(new T[n]()) {};

		Array(Array const &instance): _n(instance.size()), _ptr(new T[this->_n]())
		{
			*this = instance;
		};

		~Array(void)
		{
			if(this->_ptr)
				{delete[] this->_ptr;}
		}

		T &operator[](unsigned int index) const
		{
			if ((index < 0) || (index >= this->_n))
				throw OutOfBoundsException();
			return (_ptr[index]);
		}

		Array &operator=(Array const &rightHandSide)
		{
			try
			{
				for(unsigned int i = 0; i < rightHandSide.size(); i++)
				{
					if (i >= this->_n)
						throw OutOfBoundsException();
					this->_ptr[i] = rightHandSide._ptr[i];
				}
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			return (*this);
		}
		unsigned int size(void) const {return (_n);};

	class OutOfBoundsException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("\e[0;31mout of bounds\e[0m");
			}
	};
};

#endif
