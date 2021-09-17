/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 21:20:25 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/16 22:24:24 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Karen.hpp"
# include <iostream>

int main(int argc, char **argv)
{
	Karen		karen;
	std::string	message;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	message = PROBLEMS;
	if (argc == 1)
		message = USAGE;
	else if (argc == 2)
	{
		if (karen.complain(argv[1]))
			return (0);
	}
	std::cout << message << std::endl;
	return (0);
}
