# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 11:25:58 by plaurent          #+#    #+#              #
#    Updated: 2019/03/11 14:05:21 by plaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = fillit

RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"
BLUE = "\033[0;34m"
PURPLE = "\033[0;35m"
CYAN = "\033[0;36m"
MAGENTA = "\033[0;35;1m"
RESET = "\033[0m"

SRC = $(wildcard libft/*.c) $(wildcard srcs/*.c)									\

HEADER = header/fillit.h

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(CFLAGS) $(LIBFT) $(OBJ) -I $(HEADER)
	@echo $(GREEN)*****$(YELLOW)SUCCESS$(GREEN)*****

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean

clean:
	@/bin/rm -f $(OBJ) *.a $(wildcard *.o)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
