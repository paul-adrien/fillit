# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pa <marvin@42.fr>                          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 18:08:54 by pa                #+#    #+#              #
#    Updated: 2019/03/11 15:44:01 by eviana           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS	= -Wall -Werror -Wextra

SRC = ft_putchar_fd.c ft_putnbr.c ft_putendl.c ft_putstr.c ft_putchar.c	\
	  ft_itoa.c ft_strsplit.c ft_strtrim.c ft_strjoin.c ft_strsub.c		\
	  ft_strnequ.c ft_strequ.c ft_strmapi.c ft_strmap.c ft_striteri.c	\
	  ft_striter.c ft_strclr.c ft_strdel.c ft_strnew.c ft_memdel.c		\
	  ft_memalloc.c ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c	\
	  ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_atoi.c ft_strncmp.c		\
	  ft_strcmp.c ft_strnstr.c ft_strstr.c ft_strrchr.c ft_strlcat.c	\
	  ft_strchr.c ft_strncat.c ft_strcat.c ft_strncpy.c ft_strcpy.c		\
	  ft_memcmp.c ft_memchr.c ft_memmove.c ft_memccpy.c ft_memcpy.c		\
	  ft_bzero.c ft_strlen.c ft_memset.c ft_putnbr_fd.c ft_putendl_fd.c	\
	  ft_putstr_fd.c ft_strdup.c ft_ltoa.c ft_lltoa.c ft_strrev.c 		\
	  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c	\
	  ft_lstmap.c ft_foreach.c ft_factorial.c	ft_strcount.c			\
	  ft_power.c ft_fibonacci.c ft_sqrt.c ft_is_prime.c					\
	  ft_utoa.c ft_ultoa.c ft_ulltoa.c ft_convert_base.c ft_putull.c	\
	  ft_size_long.c get_next_line.c

HEADER = libft.h

OBJ = ft_putchar_fd.o ft_putnbr.o ft_putendl.o ft_putstr.o ft_putchar.o	\
	  ft_itoa.o ft_strsplit.o ft_strtrim.o ft_strjoin.o ft_strsub.o		\
	  ft_strnequ.o ft_strequ.o ft_strmapi.o ft_strmap.o ft_striteri.o	\
	  ft_striter.o ft_strclr.o ft_strdel.o ft_strnew.o ft_memdel.o		\
	  ft_memalloc.o ft_tolower.o ft_toupper.o ft_isprint.o ft_isascii.o	\
	  ft_isalnum.o ft_isdigit.o ft_isalpha.o ft_atoi.o ft_strncmp.o		\
	  ft_strcmp.o ft_strnstr.o ft_strstr.o ft_strrchr.o ft_strlcat.o	\
	  ft_strchr.o ft_strncat.o ft_strcat.o ft_strncpy.o ft_strcpy.o		\
	  ft_memcmp.o ft_memchr.o ft_memmove.o ft_memccpy.o ft_memcpy.o		\
	  ft_bzero.o ft_strlen.o ft_memset.o ft_putnbr_fd.o ft_putendl_fd.o	\
	  ft_putstr_fd.o ft_strdup.o ft_ltoa.o ft_lltoa.o ft_strrev.o		\
	  ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o	\
	  ft_lstmap.o ft_foreach.o ft_factorial.o	ft_strcount.o			\
	  ft_power.o ft_fibonacci.o ft_sqrt.o ft_is_prime.o					\
	  ft_utoa.o ft_ultoa.o ft_ulltoa.o ft_convert_base.o ft_putull.o	\
	  ft_size_long.o get_next_line.o

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -c $(SRC) -I $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
