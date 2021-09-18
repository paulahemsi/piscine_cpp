/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 20:52:14 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/17 21:13:34 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <unistd.h>
# include "Karen.hpp"

Karen::Karen(void)
{
	return ;
}

Karen::~Karen(void)
{
	return ;
}

void Karen::debug (void)
{
	std::cout << K_DEBUG << std::endl;
}

void Karen::info (void)
{
	std::cout << K_INFO << std::endl;
}

void Karen::warning (void)
{
	std::cout << K_WARNING << std::endl;
}

void Karen::error (void)
{
	std::cout << K_ERROR << std::endl;
}

void	Karen::tic_tac(int usleep_time, int duration)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << "." << std::endl;
		usleep(usleep_time);
	}
}

bool Karen::complain(std::string level)
{
	void	(Karen::*functionPointer[4])(void) = {	&Karen::debug,
													&Karen::info,
													&Karen::warning,
													&Karen::error,
	};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;

	i = 0;
	while(i < 4 && levels[i] != level)
		i++;
	switch (i)
	{
		case 4:
			return (false);
		case 3:
			(this->*functionPointer[i])();
			Karen::tic_tac(400000, 5);
			i--;
		case 2:
			(this->*functionPointer[i])();
			Karen::tic_tac(400000, 5);
			i--;
		case 1:
			(this->*functionPointer[i])();
			Karen::tic_tac(400000, 5);
			i--;
		default:
			(this->*functionPointer[i])();
			Karen::tic_tac(400000, 5);
			return (true);
	}
}
