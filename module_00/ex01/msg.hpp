/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 03:18:42 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/07 03:23:11 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define V_CYAN			"\e[0;38;5;44m"
# define BOLD_CYAN		"\e[1;36m"
# define LILAC			"\e[0;38;5;13m"
# define BOLD_MAGENTA	"\e[1;35m"
# define L_RED			"\e[0;38;5;9m"
# define RESET			"\e[0m"
# define INSTRUCTIONS	L_RED \
						"\n\nOooops, seems you wrote an invalid command\n\n" \
						V_CYAN \
						"-._.-.-._.-.-._.-.-._.-.-._.-.-._.-.-._.-.-._.-.\n\n" \
						"   ADD: Add a new contact in your phonebook     \n" \
						"   SEARCH: Shows your contacts                  \n" \
						"   EXIT: quit phonebook                         \n\n" \
						"-._.-.-._.-.-._.-.-._.-.-._.-.-._.-.-._.-.-._.-.\n\n" \
						RESET 
# define PROMPT			LILAC \
						"What do you wanna do?" \
						RESET
# define TELEPHONE		V_CYAN \
						"\n\n\t _____\n" \
						"\t(.---.)-._.-.\n" \
						"\t /:::\\ _.---'\n" \
						"\t'-----'\n\n" \
						RESET
# define WELCOME		BOLD_CYAN \
						"Welcome to contatinhos phonebook!\n\n" \
						RESET
# define BYE			BOLD_CYAN \
						"\tBye bye!\n\n" \
						RESET
