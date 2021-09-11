/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:33:43 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/11 18:43:19 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes.hpp"

void	display_prompt(void)
{
	std::cout << PROMPT << std::endl;
}

void	display_wellcome_msg(void)
{
	std::cout << TELEPHONE << WELCOME;
}

void	display_instructions(void)
{
	std::cout << INSTRUCTIONS;
}

bool	display_goodbye_msg(void)
{
	std::cout << TELEPHONE << BYE;
	return (true);
}
