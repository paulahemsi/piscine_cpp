/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:34:06 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/08 22:40:21 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Phonebook.hpp"
# include "display.hpp"

static bool	is_command(std::string input, Phonebook *phonebook)
{
	if (input == ADD)
		return (phonebook->add());
	else if (input == SEARCH)
		return (phonebook->search());
	else if (input == EXIT)
		return (display_goodbye_msg());
	return (false);
}

static std::string	read_input(Phonebook *phonebook)
{
	std::string	input;

	std::getline(std::cin, input);
	if (!is_command(input, phonebook))
		display_instructions();
	return input;
}

static void	phonebook_on(Phonebook *phonebook)
{
	display_prompt();
	if (read_input(phonebook) == "EXIT")
		return ;
	phonebook_on(phonebook);
}

int	main(void)
{
	Phonebook	phonebook;

	display_wellcome_msg();
	phonebook_on(&phonebook);
	return (0);
}
