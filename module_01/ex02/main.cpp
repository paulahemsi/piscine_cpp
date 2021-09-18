/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 00:24:25 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/17 19:41:51 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <unistd.h>

static void	typewriter(std::string str, int velocity)
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
	std::cout << std::endl;
}

static void	tic_tac(int usleep_time, int duration)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << "." << std::endl;
		usleep(usleep_time);
	}
}

static void	intro()
{
	std::cout << "\e[0;32m" << std::endl;
	typewriter("Wait... where are you....?", 100000);
	tic_tac(1000000, 3);
	typewriter("WOW....! You are in the zombie's stomach...!", 100000);
	tic_tac(500000, 5);
	typewriter("Listen.........!", 50000);
	std::cout << "\e[0;38;5;82m" << std::endl;
}

static void end()
{
	std::cout << "\e[0;32m" << std::endl;
	typewriter("...yes... you are one more brain amoung brains...\n...and you lived happily ever after..!", 100000);
	std::cout << std::endl;
	tic_tac(1000000, 3);
}

int main(void)
{
	std::string brain;
	brain = "HI THIS IS BRAIN";

	std::string *brainPTR;
	brainPTR = &brain;
	std::string &brainREF = brain;

	intro();
	std::cout	<< &brain << std::endl
				<< brainPTR << std::endl
				<< &brainREF << std::endl;

	std::cout << "\e[0;32m" << std::endl;
	typewriter("Ooops....! That's a strange language... Let's tune our ears...:", 70000);

	std::cout << "\e[0;38;5;82m" << std::endl;
	std::cout	<< *brainPTR << std::endl
				<< brainREF << std::endl;
	end();

	return (0);
}
