#### SYSTEM ####
.PHONY: $(NAME) all clean fclean re bonus
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror


#### DIRECTORIES ####
SRC_DIR = src

#### SOURCE FILES ####
SRCS = $(SRC_DIR)/main.c
OBJS = $(SRCS:.c=.o)

#### LIBFT HEADER COMPILED ####
LIBFT_COMPILED = libft_updated/libft_updated.a

### FINAL COMPILATION FILE ###
NAME = so_long


#### RULES ####
$(NAME):	$(OBJS) $(HEADER)
			$(MAKE) -C libft_updated/
			$(CC) $(FLAGS) $(OBJS) $(LIBFT_COMPILED) -o $(NAME)

%.o: %.c	$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

clean:
			cd libft_updated && $(MAKE) clean
			$(RM) $(OBJS)

fclean:
			cd libft_updated && $(MAKE) fclean
			$(RM) $(OBJS) $(NAME)

re:	fclean $(NAME)
