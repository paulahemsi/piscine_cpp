/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:51:18 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/10 17:01:59 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:

	public:
	WrongCat(void);
	WrongCat(WrongCat const& instance);
	~WrongCat(void);
	WrongCat	&operator=(WrongCat const &right_hand_side);

	void makeSound(void)const;
};

#endif
