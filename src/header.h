#ifndef HEADER_H
# define HEADER_H

// COLORS //
# define KNORMAL "\x1B[0m"
# define KRED "\x1B[31m"
# define KGREEN "\x1B[32m"
# define KYELLOW "\x1B[33m"
# define KBLUE "\x1B[34m"
# define KWHITE "\x1B[37m"
# define ERROR -1
# define MALLOC_ERROR -2

# include "../libft_updated/libft_updated.h"
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <fcntl.h>

void	error_printing(char *details, char *advice, char *example);
int		check_errors(int argn, char **args);
int		main_game(char *file);
char	**map_opening(char *file);

#endif
