# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 19:05:54 by phemsi-a          #+#    #+#              #
#    Updated: 2021/09/07 21:34:09 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = contatinhos

OBJS =	./main.o \
		./Phonebook.o \
		./Contact.o \
		./display.o

SRC =	./main.cpp\
		./Phonebook.cpp \
		./Contact.cpp \
		./display.cpp

CC	= clang++

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g  -std=c++98

$(NAME):	$(SRC)
			$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(OBJS)

re:			fclean all

PHONY:		all clean fclean re
