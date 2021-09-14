# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 00:39:51 by phemsi-a          #+#    #+#              #
#    Updated: 2021/09/14 00:41:38 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = violence

OBJS =	./main.o \
		./Weapon.o \
		./HumanA.o \
		./HumanB.o

SRC =	./main.cpp \
		./Weapon.cpp \
		./HumanA.cpp \
		./HumanB.cpp

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