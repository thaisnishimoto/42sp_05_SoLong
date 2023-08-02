# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 18:56:46 by tmina-ni          #+#    #+#              #
#    Updated: 2023/08/02 12:02:02 by tmina-ni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
LIBS = -lmlx -lXext -lX11 -L./libft -lft
PROGRAM = game

SRC_PATH = ./src
IMG_PATH = ./src

all:
	$(CC) $(CFLAGS) *.c $(LIBS) -o $(PROGRAM)

leak:
	valgrind --leak-check=full --show-leak-kinds-all ./$(PROGRAM)

clean:
	rm $(PROGRAM)

fclean: clean

re: fclean all
