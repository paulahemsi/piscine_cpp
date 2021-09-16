/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readFile.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:24:55 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/16 18:32:45 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>
# include <string.h>

static void	getSize(long *size, std::ifstream &inputFile)
{
	inputFile.seekg(0, inputFile.end);
	*size = inputFile.tellg();
	inputFile.seekg(0);
}

char	*readFile(long *size, std::ifstream *inputFile)
{
	getSize(size, *inputFile);
	char *buffer = new char[*size];
	(*inputFile).read(buffer, *size);
	return buffer;
}
