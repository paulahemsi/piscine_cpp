/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choices.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:48:23 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/13 21:47:56 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "colors.hpp"

std::string	choice(std::string choices, std::string option1, std::string option2)
{
	std::string	option;
	std::string action;

	while (true)
	{
		std::cout << RESET << choices << std::endl;
		std::getline(std::cin, option);
		std::cout << GREEN;
		if (option == "1")
			return (option1);
		if (option == "2")
			return (option2);
	}
}
