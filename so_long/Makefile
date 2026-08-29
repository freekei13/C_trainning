# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csamakka <csamakka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 00:13:10 by csamakka          #+#    #+#              #
#    Updated: 2026/08/29 15:18:58 by csamakka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = src/main.c src/get_next_line.c src/get_next_line_utils.c src/map_checker.c \
		src/utils.c src/parsing.c src/set_data.c src/rendering.c src/key_config.c \
		src/flood_fill_algo.c
OBJ = $(SRC:.c=.o)

PRINTF = ft_printf/libftprintf.a
PRINTF_P = ft_printf/

CC = cc
FLAGS = -Werror -Wextra -Wall
RM = rm -f

all:$(NAME)

$(GNL):$(OBJ_GNL)
	$(AR) $@ $^

$(PRINTF):
	@make -C $(PRINTF_P)
	
%.o:%.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@ -g

mlx:
	@make -C ./mlx_linux
	
$(NAME):$(OBJ) $(GNL) $(PRINTF)
	$(CC) $(FLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIB) $(PRINTF) -o $(NAME) -g

clean:
	@make clean -C ./mlx_linux
	@make clean -C $(PRINTF_P)
	$(RM) $(OBJ)
	
fclean: clean
	@make fclean -C $(PRINTF_P)
	$(RM) $(NAME)
	
re: fclean mlx all

.PHONY: mlx clean fclean re