/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typewriter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 23:41:25 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/13 18:42:17 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <unistd.h>

void	typewriter(std::string str, int velocity)
{
	int i = 0;
	while (str[i] != '\0')
	{
		std::cout << str[i] << "\xDB" << std::flush;
		usleep(velocity);
		std::cout << "\b \b" <<std::flush;
		usleep(velocity);
		i++;
	}
}

void	tic_tac(int usleep_time, int duration)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << "." << std::endl;
		usleep(usleep_time);
	}
}
