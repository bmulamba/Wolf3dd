# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmulamba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/05 06:44:49 by bmulamba          #+#    #+#              #
#    Updated: 2018/08/25 16:01:54 by bmulamba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf

SRC = display.c\
	  key_hook.c\
	  main.c\
	  parser.c\
	  raycal.c 


OBJ = $(SRC:.c=.o)

LIB = -L minilibx_macos -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(OBJ)
		gcc -Wall -Wextra -Werror -g $(LIB) $(SRC) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all
