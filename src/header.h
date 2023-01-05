/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:36:43 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/05 22:14:27 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <stdio.h>

void	error_printing(char *details, char *advice, char *example);
int		check_errors(int argn, char **args);
int		main_game(char *file);
char	**map_opening(char *file);
int		map_check(char **map);
void	tab_free(char **tab);
int		check_if_rectangular(char **map);

// MAP STRUCT //
typedef struct s_map
{
	int	y;
	int	x;
}	t_map;

#endif
