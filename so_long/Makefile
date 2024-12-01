CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11

SRC = $(wildcard ./*.c ./get_next_line/*.c ./ft_printf/*.c ./libft/*.c ./minilibx/*.c)

OBJ = $(SRC:.c=.o)
NAME = so_long

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -I. -I./get_next_line -I./ft_printf -I./libft -I./minilibx -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
