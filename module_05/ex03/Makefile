# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 19:44:22 by phemsi-a          #+#    #+#              #
#    Updated: 2021/10/15 21:23:28 by phemsi-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRC =	Bureaucrat.cpp \
		AForm.cpp \
		main.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		Intern.cpp

OBJS =	Bureaucrat.o \
		AForm.o \
		main.o \
		PresidentialPardonForm.o \
		RobotomyRequestForm.o \
		ShrubberyCreationForm.o \
		Intern.o

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
			$(RM) *_shrubbery

re:			fclean all

PHONY:		all clean fclean re
