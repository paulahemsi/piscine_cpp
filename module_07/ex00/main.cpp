/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 21:58:19 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/11/25 21:39:29 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"
#include "Student.hpp"

# define H_GREEN		"\e[0;92m"
# define D_GREEN		"\e[0;38;5;22m"
# define V_GREEN		"\e[0;38;5;82m"
# define P_GREEN		"\e[0;38;5;23m"
# define BOLD_GREEN		"\e[1;32m"

int main( void ) {

	std::cout << H_GREEN << "\n\n---- Int Test ----\n" << std::endl;
	int int1 = 2;
	int int2 = 3;
	std::cout << "before swap:" << std::endl;
	std::cout << "int1 = " << int1 << ", int2 = " << int2 << std::endl;
	swap( &int1, &int2 );
	std::cout << "after swap:" << std::endl;
	std::cout << "int1 = " << int1 << ", int2 = " << int2 << std::endl;
	std::cout << "min( int1, int2 ) = " << ::min( int1, int2 ) << std::endl;
	std::cout << "max( int1, int2 ) = " << ::max( int1, int2 ) << std::endl;

	std::cout << D_GREEN << "\n\n---- String Test ----\n" << std::endl;
	std::string str1 = "chaine1";
	std::string str2 = "chaine2";
	std::cout << "before swap:" << std::endl;
	std::cout << "str1 = " << str1 << ", str2 = " << str2 << std::endl;
	swap(&str1, &str2);
	std::cout << "after swap:" << std::endl;
	std::cout << "str1 = " << str1 << ", str2 = " << str2 << std::endl;
	std::cout << "min( str1, str2 ) = " << ::min( str1, str2 ) << std::endl;
	std::cout << "max( str1, str2 ) = " << ::max( str1, str2 ) << std::endl;

	std::cout << V_GREEN << "\n\n---- float Test ----\n" << std::endl;
	float float1 = 4.2;
	float float2 = 2.4;
	std::cout << "before swap:" << std::endl;
	std::cout << "float1 = " << float1 << ", float2 = " << float2 << std::endl;
	swap(&float1, &float2);
	std::cout << "after swap:" << std::endl;
	std::cout << "float1 = " << float1 << ", float2 = " << float2 << std::endl;
	std::cout << "min( float1, float2 ) = " << ::min( float1, float2 ) << std::endl;
	std::cout << "max( float1, float2 ) = " << ::max( float1, float2 ) << std::endl;

	std::cout << BOLD_GREEN << "\n\n---- char Test ----\n" << std::endl;
	char char1 = 'f';
	char char2 = 'z';
	std::cout << "before swap:" << std::endl;
	std::cout << "char1 = " << char1 << ", char2 = " << char2 << std::endl;
	swap(&char1, &char2);
	std::cout << "after swap:" << std::endl;
	std::cout << "char1 = " << char1 << ", char2 = " << char2 << std::endl;
	std::cout << "min( char1, char2 ) = " << ::min( char1, char2 ) << std::endl;
	std::cout << "max( char1, char2 ) = " << ::max( char1, char2 ) << std::endl;

	std::cout << P_GREEN << "\n\n---- classes Test ----\n" << std::endl;

	Student student1("Anna", 5.15);
	Student student2("John", 2.12);
	std::cout << "before swap:" << std::endl;
	std::cout << "student1 = " << student1 << ", student2 = " << student2 << std::endl;
	swap(&student1, &student2);
	std::cout << "after swap:" << std::endl;
	std::cout << "student1 = " << student1 << ", student2 = " << student2 << std::endl;
	std::cout << "min( student1, student2 ) = " << min(student1, student2) << std::endl;
	std::cout << "max( student1, student2 ) = " << max(student1, student2) << std::endl;

	std::cout << H_GREEN << "\n\n---- Equal values Test ----\n" << std::endl;
	int int3 = 42;
	int int4 = 42;
	std::cout << "values:" << std::endl;
	std::cout << "int3 = " << int3 << ", int4 = " << int4 << std::endl;
	std::cout << "pointers:" << std::endl;
	std::cout << "int3 = " << &int3 << ", int4 = " << &int4 << std::endl;
	std::cout << "min( int3, int4 ) = " << &min( int3, int4 ) << std::endl;
	std::cout << "max( int3, int4 ) = " << &max( int3, int4 ) << std::endl;

	std::cout << std::endl;
	return 0;
}
