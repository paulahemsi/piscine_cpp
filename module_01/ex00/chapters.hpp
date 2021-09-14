/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chapters.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:06:52 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/13 22:30:20 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHAPTERS_HPP
# define CHAPTERS_HPP

# include "Zombie.hpp"

void		prologue(std::string name, Zombie &firstZombie);
void		tic_tac(int usleep_time, int duration);
void		typewriter(std::string str, int velocity);
std::string	choice(std::string choices, std::string option1, std::string option2);

# endif