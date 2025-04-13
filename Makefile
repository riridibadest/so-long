NAME = so_long
CC = gcc
# CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = 
RM = rm -f

# Library paths
LIBFT = libft/libft.a
MLX = MLX42/build/libmlx42.a
MLX_FLAGS = -ldl -lglfw -lm -lpthread

# Source files (all in src/)
SRC_DIR = src/
SRCS = $(wildcard $(SRC_DIR)*.c)
OBJS = $(SRCS:.c=.o)

# Includes
INC = -I. -Ilibft -IMLX42/include

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "Game compiled! Run with: ./$(NAME) map/map1.ber"

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	make -C libft

$(MLX):
	cmake -B MLX42/build -S MLX42
	make -C MLX42/build -j4

clean:
	make clean -C libft
	$(RM) $(SRC_DIR)*.o

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re