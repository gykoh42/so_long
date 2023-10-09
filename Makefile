# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 16:09:51 by gykoh             #+#    #+#              #
#    Updated: 2023/10/09 17:12:39 by gykoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address
LDLIBS	= -Llibft -lft
LDMLX	= -Lmlx -lmlx -framework OpenGL -framework AppKit

SOURCES =	./src/main.c \
			./src/map_utils_check.c \
			./src/map_path_check.c \
			./src/map_total_check.c \
			./src/map_init.c \

OBJECTS	= $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(MAKE) -C libft
	$(MAKE) -C mlx
	$(CC) $(CFLAGS) $(LDLIBS) $(LDMLX) $(OBJECTS) -o $(NAME)

clean :
	$(MAKE) -C libft clean
	$(MAKE) -C mlx clean
	rm -f $(OBJECTS)

fclean : clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re