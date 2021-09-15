/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 22:32:05 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/14 23:12:54 by phemsi-a         ###   ########.fr       */
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

static bool	return_error(std::string msg)
{
	std::cout << msg << std::endl;
	return (true);
}

static bool	error(int argc)
{
	if (argc != 4)
		return_error("Usage: ./replace filename string1 string2");
	return (false);
}

static void	getSize(long *size, std::ifstream &inputFile)
{
	inputFile.seekg (0, inputFile.end);
	*size = inputFile.tellg();
	inputFile.seekg(0);
}

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

int main(int argc, char **argv)
{
	std::ifstream inputFile;
	std::ofstream outputFile;
	long size;

	if (error(argc))
		return (1);
	if (!openFile(argv[1], inputFile))
		return (1);
	getSize(&size, inputFile);

	char *buffer = new char[size];
	inputFile.read(buffer, size);
	outputFile.open("FILENAME.replace");
	outputFile.write(buffer, size);
	delete[] buffer;
	inputFile.close();
	outputFile.close();
	return (0);
}
