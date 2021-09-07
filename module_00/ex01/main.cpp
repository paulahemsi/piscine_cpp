/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:34:06 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/07 03:22:26 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contatinhos.hpp"

static void	display_prompt(void)
{
	std::cout << PROMPT << std::endl;
}

static std::string	read_input()
{
	std::string input;
	Contatinhos	phonebook;

	std::getline(std::cin, input);
	if (input == "ADD")
		std::cout << "--ADD--" << std::endl;
	else if (input == "SEARCH")
		std::cout << "--SEARCH--" << std::endl;
	else if (input == "EXIT")
		std::cout << TELEPHONE << BYE;
	else
		std::cout << INSTRUCTIONS;
	return input;
}

static void	display_wellcome_msg()
{
	std::cout << TELEPHONE << WELCOME;
}

static void	phonebook(void)
{
	display_prompt();
	if (read_input() == "EXIT")
		return ;
	phonebook();
}

int	main(void)
{
	display_wellcome_msg();
	phonebook();
	return (0);
}
