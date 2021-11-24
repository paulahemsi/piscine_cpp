/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 23:35:15 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/24 18:37:58 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //std::
#include <cstdlib> //rand srand
#include <unistd.h> //usleep

# define CYAN			"\e[0;36m"
# define V_BLUE			"\e[0;38;5;27m"
# define P_BLUE			"\e[0;38;5;24m"
# define V_CYAN			"\e[0;38;5;44m"
# define MAGENTA		"\e[0;35m"
# define PURPLE			"\e[0;38;5;93m"
# define LILAC			"\e[0;38;5;13m"
# define PINK			"\e[0;38;5;199m"
# define GREEN			"\e[0;32m"
# define V_GREEN		"\e[0;38;5;82m"

class Base { public: virtual ~Base(void){}};
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void)
{
	Base *class_pointer;
	int random_number;

	std::cout << "---------- generating class ----------\n" << std::endl;
	std::srand((unsigned int)time(NULL));
	random_number = rand() % 100;
	if (random_number < 33)
	{
		class_pointer = new A();
		std::cout << "class A generated\n" << std::endl;
	}
	else if (random_number < 66)
	{
		class_pointer = new B();
		std::cout << "class B generated\n" << std::endl;
	}
	else
	{
		class_pointer = new C();
		std::cout << "class C generated\n" << std::endl;
	}
	return class_pointer;
}

void identify(Base* p)
{
	std::cout << "----- identifying class by pointer -----\n" << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "A\n" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n" << std::endl;
}

void identify(Base& p)
{
	std::cout << "---- identifying class by reference ----\n" << std::endl;
	try 
	{
		dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << " Not A" << std::endl;
	}
	try 
	{
		dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << " Not B" << std::endl;
	}
	try 
	{
		dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << " Not C" << std::endl;
	}
}

static void	tic_tac(int usleep_time, int duration)
{
	for (int i = 0; i < duration; i++)
	{
		std::cout << "." << std::endl;
		usleep(usleep_time);
	}
}

int main(void)
{
	std::string colors[10] = {CYAN, V_BLUE, P_BLUE, V_CYAN, MAGENTA, PURPLE, LILAC, PINK, GREEN, V_GREEN};

	for (int i = 0; i < 10; i++, tic_tac(500000, 5))
	{
		std::cout << colors[i] << std::endl;
		Base *random_class = generate();
		Base &class_reference = *random_class;
		identify(random_class);
		identify(class_reference);
		delete random_class;
	}
}
