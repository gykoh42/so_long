# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 16:09:51 by gykoh             #+#    #+#              #
#    Updated: 2023/09/30 17:01:09 by gykoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
LIBFT = -Llibft -Lft
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
SRCS = 
OBJS = ${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C mlx
	$(CC) ${CFLAGS} ${LIBFT} ${MLX} ${OBJS} -o ${NAME}

clean :
	$(MAKE) -C libft clean
	$(MAKE) -C mlx clean
	rm -f $(OBJS)

fclean : clean
	${MAKE} -C libft fclean
	rm -f ${NAME}

re :
	${MAKE} fclean
	${MAKE} all

.PHONY: all clean fclean re