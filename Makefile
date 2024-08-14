NAME = so_long
CC = cc -Wall -Wextra -Werror
SRC = so_long.c free_utils.c move_utils.c hook.c helper.c checker.c str_utils.c ft_putstr_fd.c ft_putnbr_fd.c validation.c validation2.c so_long_utils.c manage_malloc.c
OBJ = $(SRC:.c=.o)
#OBJ = so_long.o
libx = ./minilibx-linux
print = ./ft_printf

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(libx)
	@$(CC) -g -o $(NAME) $(OBJ) -I$(libx) -L$(libx) -lmlx -lX11 -lXext -lm

clean:
	@make -C $(libx) clean
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
