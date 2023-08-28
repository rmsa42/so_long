# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 09:53:34 by rumachad          #+#    #+#              #
#    Updated: 2023/08/28 14:57:06 by rumachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = src/so_long.c src/rendering.c src/free.c src/checks.c \
		src/player_movement.c src/rendering2.c
LIBFT_DIR = libft
LIBFT_PATH = ${LIBFT_DIR}/libft.a
MLX_DIR = minilibx-linux
MLX_PATH = ${MLX_DIR}/libmlx.a
OBJS = ${SRC:.c=.o}
HEADER = include/so_long.h
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I include
MLX = ${MLX_PATH} -L. -lXext -L. -lX11
.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADER}
			make -C ${LIBFT_DIR}
			make -C ${MLX_DIR}
			${CC} ${CFLAGS} ${OBJS} ${MLX} ${LIBFT_PATH} -o ${NAME}

all:	${NAME}

clean:
		make clean -C ${LIBFT_DIR}
		${RM} ${OBJS}

fclean: clean
		make fclean -C ${LIBFT_DIR}
		${RM} ${NAME} so_long

re:	fclean all

.SILENT: