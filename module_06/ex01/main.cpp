/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 22:50:13 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/10/30 23:22:59 by phemsi-a         ###   ########.fr       */
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

static void	print_original_data(Data *student)
{
	std::cout	<< V_CYAN << "\n----- Original data: ----- \n" << std::endl;

	std::cout	<< "Name: "		<< student->name << std::endl
				<< "Level: "	<< student->level << std::endl
				<< "Project: "	<< student->project << std::endl
				<< "Xp: "		<< student->xp << std::endl;
}

static void	print_serialized_data(uintptr_t serialized_data)
{
	std::cout	<< V_ORANGE << "\n----- After serialization: -----" << std::endl;
	std::cout << std::endl << serialized_data << std::endl;
}

static void	print_deserialized_data(Data *deserialize_data)
{
	std::cout	<< V_GREEN << "\n----- After deserialization: ----- \n" << std::endl;
	std::cout	<< "Name: "		<< deserialize_data->name << std::endl
				<< "Level: "	<< deserialize_data->level << std::endl
				<< "Project: "	<< deserialize_data->project << std::endl
				<< "Xp: "		<< deserialize_data->xp << std::endl << std::endl;
}

int main(void)
{
	Data *student = new Data();
	Data *deserialize_data;
	uintptr_t serialized_data;

	define_data(student);
	print_original_data(student);

	serialized_data = serialize(student);
	print_serialized_data(serialized_data);

	deserialize_data = deserialize(serialized_data);
	print_deserialized_data(deserialize_data);
}
