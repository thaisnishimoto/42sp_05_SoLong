# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 18:56:46 by tmina-ni          #+#    #+#              #
#    Updated: 2023/08/08 14:31:07 by tmina-ni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------FLAGS--------------------#

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
LIBS = -lmlx -lXext -lX11 -L$(LIB_PATH) -lft
MAKE_NO_PRINT = $(MAKE) --no-print-directory


#--------------------PATHS--------------------#

SRC_PATH = ./src/
HEADER_PATH = ./include/
LIB_PATH = ./libft/
MAP_PATH = ./maps/


#--------------------FILES--------------------#

NAME = so_long
SRC = $(wildcard $(SRC_PATH)*.c)
OBJ = $(SRC:.c=.o)
HEADER = $(wildcard $(HEADER_PATH)*.h)


#--------------------RULES--------------------#

all: libft $(NAME)

libft:
	$(MAKE_NO_PRINT) -C $(LIB_PATH)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

#$(SRC_PATH)%.o : $(SRC_PATH)%.c $(HEADER)
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./$(NAME) $(MAP_PATH)$(MAP)

#--------------------LEAKS--------------------#

leak:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(MAP_PATH)$(MAP)


#--------------------CLEAN--------------------#

clean:
	rm -f $(SRC_PATH)*.o
	$(MAKE_NO_PRINT) clean -C $(LIB_PATH)


fclean: clean
	rm -f $(NAME)
	$(MAKE_NO_PRINT) fclean -C $(LIB_PATH)

re: fclean all

.PHONY: all libft bonus leak run clean fclean re
