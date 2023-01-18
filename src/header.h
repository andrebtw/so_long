/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:36:43 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/18 21:36:11 by anrodri2         ###   ########.fr       */
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

// KEYS //
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define ESC_KEY 53

// ERROR CODES //
# define ERROR -1
# define MALLOC_ERROR -2

# include "../libft_updated/libft_updated.h"
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdio.h>
# include "../mlx_mac/mlx.h"

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

// MAIN GAME //
typedef struct s_xmp
{
	void	*ptr;
	char	*path;
	int		width;
	int		height;
}	t_xmp;

typedef struct s_player
{
	t_xmp	xmp;
	int		x;
	int		y;	
}	t_player;

typedef struct s_animation
{
	t_xmp	coin;
	t_xmp	grass;
}	t_animation;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			frame_count;
	int			loop_count;
	t_animation	animation;
	t_player	player;
}	t_mlx;

typedef struct s_map_display
{
	t_xmp	grass;
	t_xmp	wall;
	t_xmp	coins;
	t_xmp	spawn;
	t_xmp	exit;
}	t_map_display;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

int			create_window(t_mlx *mlx);
int			close_window(t_mlx *mlx);

// ANIMATIONS //
int			coin_animation(t_mlx *mlx);

// PLAYER //
int			player(int keycode, t_mlx *mlx);

#endif
