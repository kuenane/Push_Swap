# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkuenane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/08 14:06:51 by lkuenane          #+#    #+#              #
#    Updated: 2017/12/08 14:06:55 by lkuenane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = push_swap
NAME2 = checker
CC = gcc
FLAG = -Wall -Wextra -Werror

SRC1 = ./pushswap_src/push_main.c
SRC2 = ./checker_src/checker_main.c

LINK1 = -L ./pushswap_src/ -lpushswap
LINK2 = -L ./checker_src/ -lchecker

RM = rm -rf

.PHONY: all clean fclean re

all: $(NAME) $(NAME2)

$(NAME):
	make -C pushswap_src/
	$(CC) $(FLAG) $(SRC1) -o $(NAME) $(LINK1)

$(NAME2):
	make -C checker_src/
	$(CC) $(FLAG) $(SRC2) -o $(NAME2) $(LINK2)

clean:
	make -C pushswap_src/ clean
	make -C checker_src/ clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME2)
	make -C pushswap_src/ fclean
	make -C checker_src/ fclean

re: fclean all
