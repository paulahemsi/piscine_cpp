# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 19:56:51 by phemsi-a          #+#    #+#              #
#    Updated: 2021/09/27 19:59:19 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

OBJS =	./main.o \
		./ClapTrap.o

SRC =	./main.cpp\
		./ClapTrap.cpp

CC	= clang++

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g -std=c++98

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
