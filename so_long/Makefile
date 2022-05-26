NAME		= libft.a
LIBFT		= ./library/libft/
CC			= gcc
FLAGS		= ./source/*.c ./library/get_next_line/get_next_line.c ./library/get_next_line/get_next_line_utils.c ./source/libft.a -framework OpenGL -framework AppKit -L ./library/minilibx -lmlx -glldb -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rcs

SRC			= $(wildcard source/*.c)

all:		$(NAME) derle

$(NAME):	$(OBJ)
			make -C $(LIBFT)
			cp library/libft/libft.a source

derle:
			$(CC) $(FLAGS)
			mv ./a.out so_long

clean:
			rm -f ./source/libft.a
			make clean -C $(LIBFT)

fclean:		clean
	@$(RM) -f ./source/libft.a
	@$(RM) -f $(LIBFT)/libft.a
	@$(RM) -f so_long

re:			fclean all

.PHONY:		all clean fclean re derle
# CC = gcc
# FLAGS = -framework OpenGL -framework AppKit -L./minilibx -lmlx -glldb
# all:
# 	$(CC) *.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c libft.a -Wall -Wextra -Werror $(FLAGS)
# fclean:
# 	-rf a.out
# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# .PHONY: re
