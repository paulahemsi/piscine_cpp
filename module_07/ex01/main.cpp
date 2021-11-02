/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:38:32 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/02 17:56:03 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include "Student.hpp"

# define H_GREEN		"\e[0;92m"
# define D_GREEN		"\e[0;38;5;22m"
# define V_GREEN		"\e[0;38;5;82m"
# define P_GREEN		"\e[0;38;5;23m"
# define BOLD_GREEN		"\e[1;32m"

int main(void)
{
	std::cout << D_GREEN << "\n----INT----\n" << std::endl;

	int numbers[10];
	for (int i = 0; i < 10; i++)
		numbers[i] = i;
	std::cout <<"before addOne:" << std::endl;
	iter(numbers, 10, print);
	iter(numbers, 10, addOne);
	std::cout <<"\nafter addOne:" << std::endl;
	iter(numbers, 10, print);
	iter(numbers, 10, doubleValue);
	std::cout <<"\nafter doubleValue:" << std::endl;
	iter(numbers, 10, print);

	std::cout << V_GREEN << "\n----CHAR----\n" << std::endl;

	char characters[10];
	for (int i = 0; i < 10; i++)
		characters[i] = 'a' + i;
	std::cout <<"before addOne:" << std::endl;
	iter(characters, 10, print);
	iter(characters, 10, addOne);
	std::cout <<"\nafter addOne:" << std::endl;
	iter(characters, 10, print);

	std::cout << std::endl;

	char str[5] = "test";
	std::cout <<"before addOne:" << std::endl;
	iter<char>(str, 5, print);
	iter<char>(str, 5, addOne);
	std::cout <<"\nafter addOne:" << std::endl;
	iter<char>(str, 5, print);

	std::cout << P_GREEN << "\n----CLASS----\n" << std::endl;

	Student student[5];
	for (int i = 0; i < 10; i++)
		student[i].setLevel((1 * i) + (0.2 * i));
	std::cout <<"before addOne:" << std::endl;
	iter<Student>(student, 5, print);
	iter<Student>(student, 5, addOne);
	std::cout <<"\nafter addOne:" << std::endl;
	iter<Student>(student, 5, print);
	iter<Student>(student, 5, doubleValue);
	std::cout <<"\nafter doubleValue:" << std::endl;
	iter<Student>(student, 5, print);
}
