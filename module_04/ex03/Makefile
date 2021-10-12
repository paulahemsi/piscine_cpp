# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 14:26:07 by phemsi-a          #+#    #+#              #
#    Updated: 2021/10/12 14:27:38 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = a.out

SRC =	./main.cpp \
		./AMateria.cpp \
		./Character.cpp \
		./Cure.cpp \
		./Ice.cpp \
		./MateriaSource.cpp 

OBJS =	./main.o \
		./AMateria.o \
		./Character.o \
		./Cure.o \
		./Ice.o \
		./MateriaSource.o

CC	= clang++

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g -std=c++98

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
