#### SYSTEM ####
.PHONY: $(NAME) all clean fclean re bonus
CC = gcc
AR = ar rc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

#### DIRS ####
LIBFT_DIR = libft
GNL_DIR = get_next_line
PRINTF_DIR = ft_printf

#### SOURCE FILES ####
SRCS = 	$(LIBFT_DIR)/ft_atoi.c \
		$(LIBFT_DIR)/ft_strchr.c \
		$(LIBFT_DIR)/ft_bzero.c \
		$(LIBFT_DIR)/ft_calloc.c \
		$(LIBFT_DIR)/ft_isalnum.c \
		$(LIBFT_DIR)/ft_isalpha.c \
		$(LIBFT_DIR)/ft_isascii.c \
		$(LIBFT_DIR)/ft_isdigit.c \
		$(LIBFT_DIR)/ft_isprint.c \
		$(LIBFT_DIR)/ft_memchr.c \
		$(LIBFT_DIR)/ft_memcmp.c \
		$(LIBFT_DIR)/ft_memcpy.c \
		$(LIBFT_DIR)/ft_memmove.c \
		$(LIBFT_DIR)/ft_memset.c \
		$(LIBFT_DIR)/ft_strdup.c \
		$(LIBFT_DIR)/ft_strjoin.c \
		$(LIBFT_DIR)/ft_strlcat.c \
		$(LIBFT_DIR)/ft_strlen.c \
		$(LIBFT_DIR)/ft_strncmp.c \
		$(LIBFT_DIR)/ft_strncpy.c \
		$(LIBFT_DIR)/ft_strnstr.c \
		$(LIBFT_DIR)/ft_strrchr.c \
		$(LIBFT_DIR)/ft_tolower.c \
		$(LIBFT_DIR)/ft_toupper.c \
		$(LIBFT_DIR)/ft_strlcpy.c \
		$(LIBFT_DIR)/ft_substr.c \
		$(LIBFT_DIR)/ft_strtrim.c \
		$(LIBFT_DIR)/ft_putchar_fd.c \
		$(LIBFT_DIR)/ft_putstr_fd.c \
		$(LIBFT_DIR)/ft_putendl_fd.c \
		$(LIBFT_DIR)/ft_putnbr_fd.c \
		$(LIBFT_DIR)/ft_itoa.c \
		$(LIBFT_DIR)/ft_split.c \
		$(LIBFT_DIR)/ft_strmapi.c \
		$(LIBFT_DIR)/ft_striteri.c \
		$(LIBFT_DIR)/ft_lstnew.c \
		$(LIBFT_DIR)/ft_lstadd_front.c \
		$(LIBFT_DIR)/ft_lstsize.c \
		$(LIBFT_DIR)/ft_lstlast.c \
		$(LIBFT_DIR)/ft_lstadd_back.c \
		$(LIBFT_DIR)/ft_lstdelone.c \
		$(LIBFT_DIR)/ft_lstclear.c \
		$(LIBFT_DIR)/ft_lstiter.c \
		$(LIBFT_DIR)/ft_lstmap.c \
		$(GNL_DIR)/get_next_line.c \
		$(GNL_DIR)/get_next_line_utils.c \
		$(PRINTF_DIR)/ft_null_found.c \
		$(PRINTF_DIR)/ft_print_char.c \
		$(PRINTF_DIR)/ft_print_decimals.c \
		$(PRINTF_DIR)/ft_print_hex.c \
		$(PRINTF_DIR)/ft_print_pointer_hex.c \
		$(PRINTF_DIR)/ft_print_pourcentage.c \
		$(PRINTF_DIR)/ft_print_string.c \
		$(PRINTF_DIR)/ft_printf.c \
		$(PRINTF_DIR)/ft_putbase_fd.c \
		$(PRINTF_DIR)/ft_putchar_fd_printf.c \
		$(PRINTF_DIR)/ft_putnbr_fd_printf.c \
		$(PRINTF_DIR)/ft_putstr_fd_printf.c \
		$(PRINTF_DIR)/ft_sizeof_nb_base.c \
		$(PRINTF_DIR)/ft_strlen.c


OBJS = $(SRCS:.c=.o)
HEADER = libft_updated.h

### FINAL COMPILATION FILE ###
NAME = libft_updated.a


#### RULES ####
$(NAME):	$(OBJS) $(HEADER)
			$(AR) $(NAME) $(OBJS)

%.o: %.c	$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:
			$(RM) $(OBJS) $(OBJS_BONUS) $(NAME)

re:	fclean $(NAME)
