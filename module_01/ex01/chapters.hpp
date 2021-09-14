/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chapters.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:06:52 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/13 23:42:54 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHAPTERS_HPP
# define CHAPTERS_HPP

# include "Zombie.hpp"

void		tic_tac(int usleep_time, int duration);
void		typewriter(std::string str, int velocity);
Zombie*		zombieHorde(int N, std::string name);
char		getChar(void);

# endif