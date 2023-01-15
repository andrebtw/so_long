/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:09:21 by anrodri2          #+#    #+#             */
/*   Updated: 2023/01/15 16:52:59 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	draw_tiles(t_mlx *mlx)
{
	t_xmp	grass;
	//t_xmp	wall;
	t_map	mapc;
	t_map	coords;

	grass.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./assets/grass.xpm", &grass.width, &grass.height);
	//wall.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "./assets/wall.xpm", &wall.width, &wall.height);
	mapc.y = 0;
	coords.y = 0;
	while (mlx->map[mapc.y])
	{
		mapc.x = 0;
		coords.x = 0;
		while (mlx->map[mapc.y][mapc.x])
		{
			if (ft_strchr("0CP", mlx->map[mapc.y][mapc.x]))
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, grass.ptr, coords.x, coords.y);
			mapc.x++;
			coords.x = coords.x + 50;
		}
		coords.y = coords.y + 50;
		mapc.y++;
	}
	return (0);
}

int	create_window(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (ft_printf("MLX NOT WORKING"), tab_free(mlx->map), exit(0), ERROR);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, ft_strlen(mlx->map[0]) * 50 - 50, tab_size(mlx->map) * 50, "so_long");
	draw_tiles(&(*mlx));
	mlx_hook(mlx->win_ptr, 17, 1L<<5, close_window, &(*mlx));
	mlx_hook(mlx->win_ptr, 2, 1L<<0, close_window_esc, &(*mlx));
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
