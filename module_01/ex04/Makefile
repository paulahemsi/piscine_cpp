# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 22:31:25 by phemsi-a          #+#    #+#              #
#    Updated: 2021/09/16 19:01:52 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace

OBJS =	./main.o \
		./readFile.o \
		./writeFile.o

SRC =	./main.cpp\
		./readFile.cpp \
		./writeFile.cpp

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
