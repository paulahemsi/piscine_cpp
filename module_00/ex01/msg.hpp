/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 03:18:42 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/09/11 19:14:56 by phemsi-a         ###   ########.fr       */
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
						"\nWhat do you wanna do?" \
						RESET


# define TELEPHONE		V_CYAN \
						"\n\n\t _____\n" \
						"\t(.---.)-._.-.\n" \
						"\t /:::\\ _.---'\n" \
						"\t'-----'\n\n" \
						RESET


# define WELCOME		BOLD_CYAN \
						"Welcome to contatinhos phonebook!\n" \
						"Please hit Enter to start\n\n" \
						RESET


# define BYE			BOLD_CYAN \
						"\tBye bye!\n\n" \
						RESET


# define FIRSTNAME		BOLD_CYAN \
						"\nFIRST_NAME: " \
						RESET


# define LASTNAME		BOLD_CYAN \
						"\nLAST_NAME: " \
						RESET


# define NICKNAME		BOLD_CYAN \
						"\nNICKNAME: " \
						RESET


# define PHONENUMBER	BOLD_CYAN \
						"\nPHONE_NUMBER: " \
						RESET


# define DARKESTSECRET	BOLD_CYAN \
						"\nDARKEST_SECRET: " \
						RESET


# define DOT			"."

# define PIPE			LILAC \
						"|" \
						RESET


# define TABLE_HEADER	LILAC \
						"-._.-.-._.-.-._.-.-._.-.-._.-.-._.-.-._.-.-.\n\n" \
						"     INDEX|FIRST_NAME| LAST_NAME|  NICKNAME|\n" \
						"--------------------------------------------" \
						RESET


# define END_TABLE		LILAC \
						"-._.-.-._.-.-._.-.-._.-.-._.-.-._.-.-._.-.-.\n\n" \
						RESET


# define CHOOSE_A_CONTACT	LILAC \
							"\nChoose a contact id:\n" \
							RESET


# define ENTER_VALID		L_RED \
							"\nEnter a valid number\n" \
							RESET


# define EMPTY_CONTACT		L_RED \
							"\nThis contact is empty\n" \
							RESET