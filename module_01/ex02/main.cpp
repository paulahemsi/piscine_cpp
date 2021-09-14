/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 00:24:25 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/14 00:34:38 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main(void)
{
	std::string brain;
	brain = "HI THIS IS BRAIN";

	std::string *brainPTR;
	brainPTR = &brain;

	std::string &brainREF = brain;

	std::cout	<< &brain << std::endl
				<< brainPTR << std::endl
				<< &brainREF << std::endl;
	
	std::cout	<< *brainPTR << std::endl
				<< brainREF << std::endl;
}
