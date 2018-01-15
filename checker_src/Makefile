# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnkanyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/24 17:11:06 by nnkanyan          #+#    #+#              #
#    Updated: 2017/12/08 14:07:23 by lkuenane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libchecker.a
CC = gcc
FLAG = -c -Wall -Wextra -Werror
SRC = ft_checker_helper.c \
		ft_checker_helper2.c \
		ft_checker_helper3.c \
		ft_checker_helper4.c \
		ft_checker_input_check.c \
		ft_checker_op.c \
		ft_checker_op2.c \
		ft_checker_op3.c \
		get_next_line.c \

OBJ = $(SRC:.c=.o)

INC = -I checker.h
AR = ar rc
RM = rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	$(CC) $(FLAG) $(SRC) $(INC)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
