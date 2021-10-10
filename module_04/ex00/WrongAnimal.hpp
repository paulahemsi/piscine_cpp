/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:08:03 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/10 18:53:39 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
private:

protected:
	std::string _type;
	WrongAnimal(std::string typeName);

public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const& instance);
	~WrongAnimal(void);
	WrongAnimal	&operator=(WrongAnimal const &right_hand_side);

	void makeSound(void)const;
	std::string getType(void)const;
};

std::ostream &operator<<(std::ostream &outputFile, WrongAnimal const *i);

#endif
