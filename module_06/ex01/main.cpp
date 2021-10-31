/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 22:50:13 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/31 11:54:54 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialization.hpp"
#include <stdint.h>
#include <iostream>

# define V_CYAN			"\e[0;38;5;44m"
# define V_GREEN		"\e[0;38;5;82m"
# define V_ORANGE		"\e[0;38;5;202m"

static void	define_data(Data *student)
{
	student->name = "Paula";
	student->level = 4;
	student->project = "CPP module06";
	student->xp = 4.42;
}

static void	print_data(Data *data)
{
	std::cout	<< "Name: "		<< data->name << std::endl
				<< "Level: "	<< data->level << std::endl
				<< "Project: "	<< data->project << std::endl
				<< "Xp: "		<< data->xp << std::endl;
}

int main(void)
{
	Data *student = new Data();
	Data *deserialize_data;
	uintptr_t serialized_data;

	std::cout << V_CYAN << std::endl;
	std::cout << "----- Original data: -----" << std::endl;
	define_data(student);
	print_data(student);

	std::cout << V_ORANGE << std::endl;
	std::cout << "--- After serialization: ---" << std::endl;
	serialized_data = serialize(student);
	std::cout << serialized_data << std::endl;

	std::cout << V_GREEN << std::endl;
	std::cout << "-- After deserialization: --" << std::endl;
	deserialize_data = deserialize(serialized_data);
	print_data(deserialize_data);
}
