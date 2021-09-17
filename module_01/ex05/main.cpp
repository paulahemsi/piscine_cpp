/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 21:20:25 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/16 21:57:30 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Karen.hpp"
# include <iostream>
# include <unistd.h>

static void	tic_tac(int usleep_time, int duration)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << "." << std::endl;
		usleep(usleep_time);
	}
}

int main(void)
{
	Karen	karen;

	tic_tac(400000, 5);
	karen.complain("DEBUG");
	tic_tac(400000, 5);
	karen.complain("INFO");
	tic_tac(400000, 5);
	karen.complain("WARNING");
	tic_tac(400000, 5);
	karen.complain("ERROR");
	tic_tac(400000, 5);
	
}