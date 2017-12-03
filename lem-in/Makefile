NAME = lem-in

SRC = main.c \
		getinfo.c \
		possibleroutes.c \
		movement.c \
		movement2.c \
		free.c \

FLAGS = -Wall -Werror -Wextra -g

LIBFT = -L ./libft -lft

INCLUDE = -I lemin.h

all: $(NAME)

$(NAME):
	$(MAKE) -C ./libft
	gcc -o $(NAME) $(SRC) $(LIBFT)

clean:
	rm -f $(NAME)
	$(MAKE) clean -C ./libft

fclean: clean
	$(MAKE) fclean -C ./libft

re: fclean all