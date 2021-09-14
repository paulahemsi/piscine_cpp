# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 12:23:57 by phemsi-a          #+#    #+#              #
#    Updated: 2021/09/13 19:08:52 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = deep_in_the_night

OBJS =	./main.o \
		./Zombie.o \
		./newZombie.o \
		./randomChump.o \
		./prologue.o \
		./choices.o \
		./typewriter.o

SRC =	./main.cpp\
		./Zombie.cpp \
		./newZombie.cpp \
		./randomChump.cpp \
		./prologue.cpp \
		./choices.cpp \
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