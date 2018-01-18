NAME = wolf3d

SRC = main.c \
		initialize.c \
		reader.c \
		key.c \
		player.c

FLAGS = -Wall -Werror -Wextra -g

LIBFT = -L ./libft -lft

INCLUDE = -I wolf3d.h

all: $(NAME)

$(NAME):
	$(MAKE) -C ./libft
	gcc -o $(NAME) $(SRC) $(LIBFT) -L./miniLibX/. -lmlx  -framework OpenGL -framework AppKit

clean:
	rm -f $(NAME)
	$(MAKE) clean -C ./libft

fclean: clean
	$(MAKE) fclean -C ./libft

re: fclean all