# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 12:48:59 by phemsi-a          #+#    #+#              #
#    Updated: 2021/10/16 19:37:47 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = a.out

SRC =	./main.cpp \
		./Animal.cpp \
		./Dog.cpp \
		./Cat.cpp \
		./Brain.cpp

OBJS =	./main.o \
		./Animal.o \
		./Dog.o \
		./Cat.o \
		./Brain.o

CC	= clang++

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g -std=c++98

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS):	$(SRC)
			$(CC) $(CFLAGS) -c $(SRC)

all:		$(NAME)

run:		$(NAME)
			valgrind ./$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(OBJS)

re:			fclean all

PHONY:		all clean fclean re
