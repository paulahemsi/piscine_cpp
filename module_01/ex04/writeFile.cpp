/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeFile.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:29:53 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/19 09:45:33 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string.h>
# include <fstream>
# include <stdlib.h>

static std::string	strToUpper(std::string &file)
{
	char		*fileUpper;
	size_t		nameLength;
	std::string	fileUpperStr;

	nameLength = file.length();
	fileUpper = new char[nameLength];
	file.copy(fileUpper, nameLength);
	for (size_t i = 0; i < nameLength; i++)
		fileUpper[i] = std::toupper(file[i]);
	fileUpper[nameLength] = '\0';
	fileUpperStr = std::string(fileUpper);
	delete [] fileUpper;
	return (fileUpperStr);
}

static void	replaceWord(std::string *text, std::string *replacebleStr, std::string *newStr, size_t i)
{
	(*text).erase(i, (*replacebleStr).length());
	(*text).insert(i, (*newStr));
}

static void replaceFile(std::string *text, char **argv)
{
	std::string		replacebleStr = argv[2];
	std::string		newStr = argv[3];
	
	for (size_t i = 0; i != std::string::npos; i = (*text).find(replacebleStr, i + 1))
		if (i != std::string::npos && i != 0)
			replaceWord(text, &replacebleStr, &newStr, i);
}

void writeFile(char **argv, std::ofstream *outputFile, char *buffer, long size)
{
	std::string		argvName;
	std::string		fileName;
	std::string		text;

	argvName = std::string(argv[1]);
	text = std::string(buffer);
	fileName = strToUpper(argvName) + ".replace";
	(*outputFile).open(fileName.c_str());
	replaceFile(&text, argv);
	(*outputFile).write(text.c_str(), size);
	delete [] buffer;
}
