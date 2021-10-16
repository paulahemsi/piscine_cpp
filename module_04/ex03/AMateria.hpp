/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:45:28 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 12:03:55 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(std::string const & type);
		AMateria(void);
		AMateria(AMateria const & src );
		virtual	~AMateria(void);
		
		AMateria	&operator=( AMateria const & ringht_hand_side );

		std::string const	&getType() const; //Returns the materia type
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter& target);
};

#endif
