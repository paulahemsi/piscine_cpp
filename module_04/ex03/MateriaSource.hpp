/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:50:12 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/17 11:30:06 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define MAX_MAGICS 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_magicBook[MAX_MAGICS];

		void		_storeMateria(AMateria *materia, int i);
		void		_initBook(void);

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &instace);
		~MateriaSource(void);

		MateriaSource &operator=(MateriaSource const &rightHandSide);

		void learnMateria(AMateria*) ;
		AMateria* createMateria(std::string const & type);
};

#endif
