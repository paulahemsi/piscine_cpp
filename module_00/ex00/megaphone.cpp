/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:43:12 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/05 19:05:44 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	feedback()
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

static void	amplify_word(char *word)
{
	for (int i = 0; word[i] != '\0'; i++)
		word[i] = toupper(word[i]);
	std::cout << word << " ";
}

static void amplify(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
		amplify_word(argv[i]);
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		feedback();
	else
		amplify(argc, argv);
}
