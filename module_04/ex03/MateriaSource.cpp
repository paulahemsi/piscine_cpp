/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:51:59 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/16 17:20:08 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

# define PURPLE			"\e[0;38;5;93m"
# define RESET			"\e[0m"

MateriaSource::MateriaSource(void)
{
	for(int i = 0; i < MAX_MAGICS; i++)
		_magicBook[i] = NULL;
	std::cout << PURPLE << "Magic Book Materia Source created" << RESET << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &instace)
{
	*this = instace;
	std::cout << PURPLE << "Magic Book copied" << RESET << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for(int i = 0; i < MAX_MAGICS; i++)
		if(this->_magicBook[i])
			delete this->_magicBook[i];
	std::cout << PURPLE << "Magic Book destroyed" << RESET << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rightHandSide)
{
	for(int i = 0; i < MAX_MAGICS; i++)
		this->_magicBook[i] = rightHandSide._magicBook[i];
	return *this;
}

void MateriaSource::_storeMateria(AMateria *materia, int i) 
{
	this->_magicBook[i] = materia;
	std::cout << PURPLE << "Materia " << materia->getType() << " learned" << RESET << std::endl;
	return ;
}

void MateriaSource::learnMateria(AMateria *materia) 
{
	for(int i = 0; i < MAX_MAGICS; i++)
		if (!this->_magicBook[i])
			return (_storeMateria(materia, i));
	std::cout << PURPLE << "Oh-oh no more space to learn here" << RESET << std::endl;
	return ;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < MAX_MAGICS && this->_magicBook[i]; i++)
		if (this->_magicBook[i]->getType() == type)
			return (this->_magicBook[i]->clone());
	std::cout << PURPLE << "Sorry, we don't know this kind of \"" << type <<  "\" magic" << RESET << std::endl;
	return (NULL);
}
