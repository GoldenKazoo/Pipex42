CC          = cc
CFLAGS      = -Wall -Wextra -Werror
NAME        = pipex

SRC_DIR     = ./srcs
OBJ_DIR     = ./objs
INC_DIR     = .
LIBFT_DIR   = ./libft

SRCS        = main.c commands_utils.c commands.c \
              init_data.c errors.c exec.c \
              free.c path.c
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

LIBFT       = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -l:libft.a -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
