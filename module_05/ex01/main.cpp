/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:21:27 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/12 20:54:23 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat john;
	Bureaucrat fred("fred", 45);
	Form		form42("42", 42, 42);
	Form		form149("149", 149, 149);
	std::cout << john << std::endl;
	std::cout << fred << std::endl;
	john.signForm(form42);
	john.signForm(form149);
	fred.signForm(form149);
	fred.signForm(form42);
	return (0);
}
