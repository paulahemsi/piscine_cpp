/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:10:19 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/12 14:23:18 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Cure : public AMateria
{
private:
	/* data */
public:
	Cure(void);
	Cure(Cure const &instance);
	virtual	~Cure(void);
	
	Cure	&operator=( Cure const & ringht_hand_side );

	Cure* clone(void) const;
	void 	use(ICharacter& target);
};

#endif
