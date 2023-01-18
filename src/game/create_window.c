/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:09:21 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/18 21:37:58 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	error_message(void)
{
	error_printing("XPM file failed to load.",
		"Make sure the XPM file is in the assets directory.",
		"./assets/coin.xpm");
	return (ERROR);
}

int	load_tiles(t_mlx *mlx, t_map_display *map_display)
{
	map_display->grass.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./assets/grass.xpm",
			&map_display->grass.width, &map_display->grass.height);
	map_display->wall.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./assets/wall.xpm",
			&map_display->wall.width, &map_display->wall.height);
	map_display->spawn.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./assets/spawn.xpm",
			&map_display->wall.width, &map_display->wall.height);
	map_display->exit.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./assets/exit.xpm",
			&map_display->wall.width, &map_display->wall.height);
	if (!map_display->grass.ptr || !map_display->wall.ptr)
		return (error_message());
	if (!map_display->spawn.ptr || !map_display->exit.ptr)
		return (error_message());
	return (0);
}

void	draw_loop(t_mlx	*mlx, t_map_display map_display,
		t_map mapc, t_map coords)
{
	while (mlx->map[++mapc.y])
	{
		mapc.x = -1;
		coords.x = 0;
		while (mlx->map[mapc.y][++mapc.x])
		{
			if (ft_strchr("0PCE", mlx->map[mapc.y][mapc.x]))
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					map_display.grass.ptr, coords.x, coords.y);
			if (ft_strchr("1", mlx->map[mapc.y][mapc.x]))
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					map_display.wall.ptr, coords.x, coords.y);
			if (ft_strchr("P", mlx->map[mapc.y][mapc.x]))
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					map_display.spawn.ptr, coords.x, coords.y);
				mlx->player.x = mapc.x;
				mlx->player.y = mapc.y;
			}
			if (ft_strchr("E", mlx->map[mapc.y][mapc.x]))
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					map_display.exit.ptr, coords.x, coords.y);
			coords.x = coords.x + 50;
		}
		coords.y = coords.y + 50;
	}
}

int	draw_tiles(t_mlx *mlx)
{
	t_map_display	map_display;
	t_map			mapc;
	t_map			coords;

	mapc.y = -1;
	coords.y = 0;
	if (load_tiles(mlx, &map_display) == ERROR)
		return (ERROR);
	draw_loop(mlx, map_display, mapc, coords);
	return (0);
}

int	create_window(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (ft_printf("MLX NOT WORKING"),
			tab_free(mlx->map), exit(0), ERROR);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
			ft_strlen(mlx->map[0]) * 50 - 50,
			tab_size(mlx->map) * 50, "so_long");
	if (draw_tiles(mlx) == ERROR)
		return (close_window(&(*mlx)));
	mlx_hook(mlx->win_ptr, 17, 1L << 5, close_window, &(*mlx));
	mlx_hook(mlx->win_ptr, 2, 1L << 0, player, &(*mlx));
	mlx_loop_hook(mlx->mlx_ptr, coin_animation, &(*mlx));
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
