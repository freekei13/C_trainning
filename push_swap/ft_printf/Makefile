NAME = libftprintf.a
SRC = ft_printf.c ft_print_chars.c ft_print_dec.c ft_print_hex_p.c
OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

GREEN = \033[38;5;76m
BLUE = \033[0;34m
RESET = \033[00m

all:$(NAME)

$(NAME):$(OBJ)
	$(AR) $(NAME) $^
	
%.o:%.c ft_printf.h
	$(CC) $(FLAGS) -g -c $< -o $@
	@printf "$(BLUE)=$(RESET)"


clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all