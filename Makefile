# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolivier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 12:26:44 by nolivier          #+#    #+#              #
#    Updated: 2016/12/07 15:10:17 by nolivier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit.c \
	  ft_purchase.c \
	  ft_compare.c \
	  ft_resolve.c \
	  ft_place_tetri.c \
	  ft_lstdel_tetri.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_strlen.c \

OUT = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAG) $(SRC)
	gcc -o $(NAME) $(OUT) $(FLAG)

clean:
	/bin/rm -f $(OUT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
