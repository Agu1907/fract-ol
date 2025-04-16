NAME = fract_ol
BONUS_NAME = fract_ol_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = mlx/libmlx.a

MLXFLAGS = -lXext -lX11 -lm

BONUS_SRC = bonus_src/main.c \
	bonus_src/functions.c \
	bonus_src/exits.c \
	bonus_src/set_handle.c \
	bonus_src/iteration_check.c \
	bonus_src/mandelbrot.c \
	bonus_src/julia.c \
	bonus_src/controls.c \

SRC = src/main.c \
	src/functions.c \
	src/exits.c \
	src/set_handle.c \
	src/iteration_check.c \
	src/mandelbrot.c \
	src/julia.c \
	src/controls.c \

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all : $(NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJ) $(MLX)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME) $(MLX) $(MLXFLAGS)

$(NAME) : $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX) $(MLXFLAGS)

clean : 
	rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

re : fclean all bonus

.PHONY : all clean fclean re bonus
