/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:04:45 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 12:09:11 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice : public AMateria
{
private:
	/* data */
public:
	Ice(void);
	Ice(Ice const &instance);
	virtual	~Ice(void);
	
	Ice	&operator=( Ice const & ringht_hand_side );

	Ice		*clone(void) const;
	void	use(ICharacter& target);
};

#endif
