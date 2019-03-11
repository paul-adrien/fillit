# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 11:25:58 by plaurent          #+#    #+#              #
#    Updated: 2019/03/11 18:43:50 by eviana           ###   ########.fr        #
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

SRC = $(wildcard srcs/*.c)									\

HEADER = header/

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@make -C libft
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -I $(HEADER) $(LIB)
	@echo $(GREEN)*****$(YELLOW)SUCCESS$(GREEN)*****

%.o: %.c
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

.PHONY: clean fclean

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ) $(wildcard *.a) $(wildcard *.o)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all
