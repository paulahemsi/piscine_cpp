/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 12:56:53 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/13 22:22:00 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include "colors.hpp"

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(std::string name);
		~Zombie(void);
		void annouce(void);
		void noise(void);
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
