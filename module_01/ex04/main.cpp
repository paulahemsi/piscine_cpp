/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 22:32:05 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/17 20:20:55 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
