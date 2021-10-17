/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:33:04 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 23:05:12 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MAX_ITENS 4

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[MAX_ITENS];//ptr is ok, but the array directly isn't
		void		_fillInventory(AMateria *m, int i);
		void 		_initInventory(void);

	public:
		Character(std::string name);
		Character(void);
		Character(Character const & src );
		virtual	~Character(void);
	
		Character	&operator=( Character const & ringht_hand_side );
	
		std::string const	&getName(void) const;
		void 				setName(std::string name);
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif
