NAME = pipex
CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC = pipex.c utils_error.c utils.c

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re