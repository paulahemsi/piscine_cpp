/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 20:52:14 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/16 21:56:41 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
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

void Karen::complain(std::string level)
{
	void	(Karen::*functionPointer[4])(void) = {	&Karen::debug,
													&Karen::info,
													&Karen::warning,
													&Karen::error,
	};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;

	i = -1;
	while(levels[++i] != level)
		continue ;
	(this->*functionPointer[i])();
}
