/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:39:55 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 19:35:24 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
	public:
	Dog(void);
	Dog(Dog const& instance);
	~Dog(void);
	Dog	&operator=(Dog const &right_hand_side);

	Brain	*getBrain(void)const;
	void getIdea(void);
	void getIdea(int index);
	void makeSound(void)const;
};

#endif
