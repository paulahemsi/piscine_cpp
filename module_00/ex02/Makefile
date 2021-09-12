# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/11 21:22:51 by phemsi-a          #+#    #+#              #
#    Updated: 2021/09/12 11:27:50 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

OBJS =	./tests.o \
		./Account.o \

SRC =	./tests.cpp \
		./Account.cpp \

LOGS =	new_log.txt \
		old_log \
		new_log

CC	= clang++

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g -std=c++98

$(NAME):	$(SRC)
			$(CC) $(CFLAGS) $(SRC) -o $(NAME)

run:	$(NAME)
		@./account > new_log.txt

diff:	run
		bash diff.sh
		$(RM) $(LOGS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(OBJS)
			$(RM) diff

re:			fclean all

PHONY:		all clean fclean re diff run
