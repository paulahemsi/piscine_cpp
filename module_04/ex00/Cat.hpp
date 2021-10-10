/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:51:18 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/10 17:47:13 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:

	public:
	Cat(void);
	Cat(Cat const& instance);
	~Cat(void);
	Cat	&operator=(Cat const &right_hand_side);

	virtual void makeSound(void)const;
};

#endif
