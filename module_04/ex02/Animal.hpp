/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:08:03 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/11 22:17:47 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
private:

protected:
	std::string _type;
public:
	Animal(std::string typeName);
	Animal(void);
	Animal(Animal const& instance);
	virtual void getIdea(void);
	virtual void getIdea(int index);
	virtual ~Animal(void);
	Animal	&operator=(Animal const &right_hand_side);

	virtual void makeSound(void)const = 0;
	std::string getType(void)const;
};

std::ostream &operator<<(std::ostream &outputFile, Animal const *i);

#endif
