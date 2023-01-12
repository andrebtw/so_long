/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:36:43 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/12 17:02:42 by anrodri2         ###   ########.fr       */
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

// ERROR CODES //
# define ERROR -1
# define MALLOC_ERROR -2

# include "../libft_updated/libft_updated.h"
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdio.h>

// MAP STRUCT //

typedef struct s_map
{
	int	y;
	int	x;
}	t_map;

// PATHFINDING STRUCT //

typedef struct s_map_info
{
	int	p_index_x;
	int	p_index_y;
	int	e_index_x;
	int	e_index_y;
	int	c_count;
}	t_map_info;

void		error_printing(char *details, char *advice, char *example);
int			check_errors(int argn, char **args);
int			main_game(char *file);
char		**map_opening(char *file);
int			map_check(char **map, char *file);
void		tab_free(char **tab);
int			check_if_rectangular(char **map);
int			check_walls(char **map);

// PATHFINDING //
int			path_check(char **map, char *file);
t_map_info	find_p_index(char **map, t_map mapc, t_map_info mapi);
t_map_info	find_e_index(char **map, t_map mapc, t_map_info mapi);
int			count_c(char **map, t_map mapc);
int			tab_size(char **tab);
int			**get_collectibles(char **map);
void		tab_free_int(int **tab);
int			findpath(t_map_info map, char **path,
				int *end_pos, char *allowed_chars);

#endif
