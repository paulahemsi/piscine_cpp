/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 03:18:42 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/07 19:30:56 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"

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
