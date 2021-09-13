/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typewriter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 23:41:25 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/12 23:43:25 by phemsi-a         ###   ########.fr       */
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
