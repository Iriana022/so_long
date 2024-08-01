NAME = so_long
CC = cc -Wall -Wextra -Werror
SRC = so_long.c free_utils.c move_utils.c hook.c helper.c checker.c str_utils.c ft_putstr_fd.c ft_putnbr_fd.c validation.c
OBJ = so_long.o
libx = ./minilibx-linux
print = ./ft_printf

all: $(NAME)

$(NAME):
	$(CC) -g -o $(NAME) $(SRC) -I$(libx) -L$(libx) -lmlx -lX11 -lXext -lm

clean:
	rm -rf $(NAME)
