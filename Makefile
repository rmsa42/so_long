# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 09:53:34 by rumachad          #+#    #+#              #
#    Updated: 2023/08/08 16:40:03 by rumachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = so_long.c rendering.c free.c checks.c
LIBFT_DIR = libft
LIBFT_PATH = ${LIBFT_DIR}/libft.a
MLX_DIR = minilibx-linux
MLX_PATH = ${MLX_DIR}/libmlx.a
OBJS = ${SRC:.c=.o}
HEADER = so_long.h
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
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

re:	clean all

.SILENT: