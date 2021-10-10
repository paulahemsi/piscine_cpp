/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:39:55 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/10 17:43:11 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private:

	public:
	Dog(void);
	Dog(Animal const& instance);
	~Dog(void);
	Dog	&operator=(Dog const &right_hand_side);

	virtual void makeSound(void)const;
};

#endif
