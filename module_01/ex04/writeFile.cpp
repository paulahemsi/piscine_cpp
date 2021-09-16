/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeFile.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:29:53 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/16 19:46:18 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string.h>
# include <fstream>
# include <stdlib.h>

static std::string	strToUpper(char *file)
{
	char		*fileUpper;
	std::string	fileUpperStr;

	fileUpper = (char *)malloc(strlen(file) * sizeof(char));
	if (!fileUpper)
		return NULL;
	int i = -1;
	while(file[++i] != '\0')
		fileUpper[i] = toupper(file[i]);
	fileUpper[i] = '\0';
	fileUpperStr = std::string(fileUpper);
	free(fileUpper);
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
		if (i != std::string::npos)
			replaceWord(text, &replacebleStr, &newStr, i);
}

void writeFile(char **argv, std::ofstream *outputFile, char *buffer, long size)
{
	std::string		fileName;
	std::string		text;

	text = std::string(buffer);
	fileName = strToUpper(argv[1]) + ".replace";
	(*outputFile).open(fileName.c_str());
	replaceFile(&text, argv);
	(*outputFile).write(text.c_str(), size);
	delete [] buffer;
}
