/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:34:06 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/06 20:35:04 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <stdlib.h>

static void	display_prompt(void)
{
	std::cout << "Welcome to little contacts phone book! What do you wanna do?" << std::endl;
}

static void	read_input()
{
	std::string input;

	std::getline(std::cin, input);
	if (input == "ADD")
		std::cout << "--ADD--" << std::endl;
	else if (input == "SEARCH")
		std::cout << "--SEARCH--" << std::endl;
	else if (input == "EXIT")
	{
		std::cout << "--EXIT--" << std::endl;
		exit(0);
	}
	else
		std::cout << "invalid command" << std::endl;
}

int	main(void)
{
	while (true)
	{
		display_prompt();
		read_input();
	}
}
