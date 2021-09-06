# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 19:05:54 by phemsi-a          #+#    #+#              #
#    Updated: 2021/09/06 19:37:07 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = contatinhos

DIR_OBJS = objects

OBJS = main.o

SRC = main.cpp

CC	= clang++

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g  -std=c++98

$(NAME): $(OBJS)
		@-$(CC) $(CFLAGS) $(OBJS) $(HEADER) -o $(NAME)

$(OBJS): $(SRC)
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "Compiled "$<" successfully!"

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(OBJS)

re:		fclean all

PHONY:	all clean fclean re
