#### SYSTEM ####
.PHONY: $(NAME) all clean fclean re bonus lib
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit


#### DIRECTORIES ####
SRC_DIR = src

#### SOURCE FILES ####
SRCS =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/errors_check/check_errors.c \
		$(SRC_DIR)/errors_check/error_printing.c \
		$(SRC_DIR)/game/main_game.c \
		$(SRC_DIR)/map_gestion/map_opening.c \
		$(SRC_DIR)/map_gestion/map_check.c \
		$(SRC_DIR)/map_gestion/map_check_rect_walls.c \
		$(SRC_DIR)/map_gestion/map_path_check.c \
		$(SRC_DIR)/map_gestion/map_path_index.c \
		$(SRC_DIR)/map_gestion/collect_cords.c \
		$(SRC_DIR)/map_gestion/map_pathfinding.c \
		$(SRC_DIR)/game/create_window.c \
		$(SRC_DIR)/game/close_window_funcs.c \
		$(SRC_DIR)/game/coin_animation.c \
		$(SRC_DIR)/game/player.c \
		$(SRC_DIR)/game/player_movement.c \
		$(SRC_DIR)/game/main_loop.c 

OBJS = $(SRCS:.c=.o)

HEADER = $(SRC_DIR)/header.h

#### LIBFT HEADER COMPILED ####
LIBFT_COMPILED = libft_updated/libft_updated.a
#### MLX HEADER COMPILED ####
MLX_COMPILED = mlx_mac/libmlx.a

### FINAL COMPILATION FILE ###
NAME = so_long

#### RULES ####
$(NAME):	$(OBJS) $(HEADER)
			cd libft_updated && $(MAKE) all
			$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBFT_COMPILED) $(MLX_COMPILED) -o $(NAME) -g3

%.o: %.c	$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@ -g3

all:		$(NAME)

clean:
			cd libft_updated && $(MAKE) clean
			cd mlx_mac && $(MAKE) clean
			$(RM) $(OBJS)

fclean:
			cd libft_updated && $(MAKE) fclean
			cd mlx_mac && $(MAKE) clean
			$(RM) $(OBJS) $(NAME)

lib:
			cd libft_updated && $(MAKE) re
			cd mlx_mac && $(MAKE) re

bonus:
			$(NAME)

re:	fclean $(NAME)
