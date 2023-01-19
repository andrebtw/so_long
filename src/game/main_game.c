/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:38:55 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/19 16:29:45 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	main_game(char *file)
{
	t_mlx		mlx;
	t_map		mapc;

	mapc.y = 0;
	mlx.player.end = 0;
	mlx.frame_count = 0;
	mlx.loop_count = 0;
	mlx.animation.coin.ptr = NULL;
	mlx.animation.grass.ptr = NULL;
	mlx.player.xmp.ptr = NULL;
	mlx.grass_redraw.ptr = NULL;
	mlx.mouvement_count = 0;
	mlx.wall_redraw.ptr = 0;
	mlx.map = map_opening(file);
	if (!mlx.map)
		return (ERROR);
	if (map_check(mlx.map, file) == ERROR)
		return (tab_free(mlx.map), ERROR);
	mlx.collectibles_n = count_c(mlx.map, mapc);
	create_window(&mlx);
	if (!mlx.mlx_ptr)
		return (ERROR);
	return (tab_free(mlx.map), 0);
}
