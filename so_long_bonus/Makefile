CC = gcc
FLAGS = -framework OpenGL -framework AppKit -L./minilibx -lmlx -glldb
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"
all:
	$(CC) *.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c libft.a -Wall -Wextra -Werror $(FLAGS)
fclean:
	-rf a.out
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
.PHONY: re
