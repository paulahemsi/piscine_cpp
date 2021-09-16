/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 22:32:05 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/16 19:00:17 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Make a program called replace that takes a filename and two strings, let’s call them
** s1 and s2, that are NOT empty.
** It will open the file, and write its contents to FILENAME.replace, after replacing
** every occurrence of s1 with s2.
** All the member functions of the class std::string are allowed, except replace. Use
** them wisely!
** Of course, you will handle errors as best you can. Do not use the C file manipulation
** functions, because that would be cheating, and cheating’s bad, m’kay?
** You will turn in some test files to show your program works.
*/

# include <iostream>
# include <fstream>
# include <string.h>
# include <stdlib.h>
# include <string>
# include <cstring>
# include "replace.hpp"

static bool	openFile(const char *fileName, std::ifstream &inputFile)
{
	inputFile.open(fileName);
	if (!inputFile)
	{
		std::cerr << "Error opening the file" << std::endl;
		return (false);
	}
	return (true);
}

static bool	errors(int argc, char *fileName, std::ifstream *inputFile)
{
	if (argc != 4 || !openFile(fileName, *inputFile))
	{
		std::cout << "Usage: ./replace filename string1 string2" << std::endl;
		return (true);
	}
	return (false);
}

int main(int argc, char **argv)
{
	std::ifstream	inputFile;
	std::ofstream	outputFile;
	long size;

	if (errors(argc, argv[1], &inputFile))
		return (1);
	writeFile(argv, &outputFile, readFile(&size, &inputFile), size);
	inputFile.close();
	outputFile.close();
	return (0);
}
