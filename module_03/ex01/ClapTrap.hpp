/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:00:07 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/29 22:38:30 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap
{
	private:
		std::string		_name;

	protected:
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

		bool			_isBroken(void);
		bool			_isTired(void);

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const& instance);
		~ClapTrap(void);

		ClapTrap	&operator=(ClapTrap const &right_hand_side);

		void		attack(std::string const & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		void			setName(std::string name);
		void			setHitPoints(unsigned int amount);
		void			setEnergyPoints(unsigned int amount);
		void			setAttackDamage(unsigned int amount);

		std::string		getName(void)const;
		unsigned int	getHitPoints(void)const;
		unsigned int	getEnergyPoints(void)const;
		unsigned int	getAttackDamage(void)const;
};

std::ostream &operator<<(std::ostream &outputFile, ClapTrap const &i);
