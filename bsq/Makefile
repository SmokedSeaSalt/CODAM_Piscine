NAME=bsq
CC=cc
CFLAGS= -Wall -Wextra -Werror
SRC= main.c count_matrix_allocate.c find_bsq.c map_error_helpers.c \
	map_error_parsing.c matrix_fill.c print_bsq.c read_map.c free_list.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm $(NAME)

re:  flcean all
