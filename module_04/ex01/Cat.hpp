/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:51:18 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/10 22:36:21 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*_brain;
	public:
		Cat(void);
		Cat(Cat const& instance);
		~Cat(void);
		Cat	&operator=(Cat const &right_hand_side);

		Brain	*getBrain(void)const;
		virtual void getIdea(void);
		virtual void getIdea(int index);
		virtual void makeSound(void)const;
};

#endif
