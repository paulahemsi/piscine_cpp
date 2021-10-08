# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 19:56:51 by phemsi-a          #+#    #+#              #
#    Updated: 2021/10/03 19:11:53 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

OBJS =	./main.o \
		./ClapTrap.o \
		./ScavTrap.o \
		./FragTrap.o \
		./DiamondTrap.o

SRC =	./main.cpp \
		./ClapTrap.cpp \
		./ScavTrap.cpp \
		./FragTrap.cpp \
		./DiamondTrap.cpp

CC	= clang++

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g -std=c++98 -Wshadow -Wno-shadow

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS):	$(SRC)
			$(CC) $(CFLAGS) -c $(SRC)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(OBJS)

re:			fclean all

PHONY:		all clean fclean re
