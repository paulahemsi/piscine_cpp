# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 12:23:57 by phemsi-a          #+#    #+#              #
#    Updated: 2021/09/13 23:41:20 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = chapter_two

OBJS =	./main.o \
		./Zombie.o \
		./ZombieHorde.o \
		./typewriter.o

SRC =	./main.cpp\
		./Zombie.cpp \
		./ZombieHorde.cpp \
		./typewriter.cpp

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