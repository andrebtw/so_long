#### SYSTEM ####
.PHONY: $(NAME) all clean fclean re bonus
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror


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
		$(SRC_DIR)/map_gestion/map_pathfinding.c

OBJS = $(SRCS:.c=.o)

#### LIBFT HEADER COMPILED ####
LIBFT_COMPILED = libft_updated/libft_updated.a

### FINAL COMPILATION FILE ###
NAME = so_long

#### RULES ####
$(NAME):	$(OBJS) $(HEADER)
			$(MAKE) -C libft_updated/
			$(CC) $(FLAGS) $(OBJS) $(LIBFT_COMPILED) -o $(NAME) -g3

%.o: %.c	$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@ -g3

all:		$(NAME)

clean:
			cd libft_updated && $(MAKE) clean
			$(RM) $(OBJS)

fclean:
			cd libft_updated && $(MAKE) fclean
			$(RM) $(OBJS) $(NAME)

re:	fclean $(NAME)
